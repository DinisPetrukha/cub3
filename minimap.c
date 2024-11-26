#include "./includes/cub3d.h"

void	map_count_row(t_player *player, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nCouldnt open file\n", 24);
		exit(1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	player->height = i;
}

void	name_check(char *name)
{
	int	i;
	int	ret;

	i = ft_strlen(name);
	ret = ft_strncmp(&name[i - 4], ".cub", 5);
	if (name[i - 5] == '/')
		ret = 1;
	if (ret)
	{
		write(2, "Error\nWrong name\n", 17);
		exit (0);
	}
}

void	init_map(t_player *player, char *file)
{
	int	fd;
	int	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nCouldnt open file\n", 24);
		exit(1);
	}
	player->map = (char **)ft_calloc((player->height + 1), sizeof(char *));
	if (!player->map)
		exit(1);
	i = 0;
	player->width = 0;
	while (i < player->height)
	{
		player->map[i] = get_next_line(fd);
		if ((ft_strlen(player->map[i]) - 1) > (size_t)player->width)
			player->width = ft_strlen(player->map[0]) - 1;
		i++;
	}
	close(fd);
}

int	is_protected(t_player *player, int y, int x)
{
	//above
	if (y == 0 || ft_strlen(player->map[y - 1]) - 1 <= (size_t)x || player->map[y - 1][x] == 32)
		return (0);
	//below
	if (y == player->height - 1 
		|| ft_strlen(player->map[y + 1]) - 1 <= (size_t)x 
		|| player->map[y + 1][x] == 32)
		return (0);
	//left
	if (x == 0 || player->map[y][x - 1] == 32)
		return (0);
	//right
	if (x == player->width - 1 || player->map[y][x + 1] == 32 ||
		player->map[y][x + 1] == '\n')
			return (0);
	return (1);
}

void	check_symbols(t_player *player)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < player->height)
	{
		j = 0;
		if (player->map[i][0] == '\n')
			exitmap(player->map, 0, "Error\nGap in map\n");
		while (player->map[i][j])
		{
			c = player->map[i][j];
			if (!player->map[i][j + 1] && c != '\n')
				exitmap(player->map, 0, "Error\nNo new line\n");
			if (!(c == 32 || c == 10 || c == '0' || c == '1'
				|| c == 'S' || c == 'W' || c == 'N' || c == 'E'))
				exitmap(player->map, 0, "Error\nWrong letter\n");
			//just check spaces and player for protection
			if (c != 32 && c != '1' && c != 10)
			{
				if (!(is_protected(player, i, j)))
					exitmap(player->map, 0, "Error\nNot Protected\n");
			}
			j++;
		}
		i++;
	}
}

void	check_player(t_player *player)
{
	int	player_n;
	int	i;
	int	j;

	j = 0;
	player_n = 0;
	while (j < player->height)
	{
		i = 0;
		while (player->map[j][i])
		{
			if (player->map[j][i] > 'A' && player->map[j][i] < 'Z')
			{
				player->y = j + 0.5;
				player->x = i + 0.5;
				player->map[j][i] = '0';
				player_n++;
			}
			if (player->map[j][i] == 'N')
				player->orient = 90;
			if (player->map[j][i] == 'S')
				player->orient = 270;
			if (player->map[j][i] == 'W')
				player->orient = 180;
			if (player->map[j][i] == 'E')
				player->orient = 0;
			i++;
		}
		j++;
	}
	if (player_n != 1)
		exitmap(player->map, 0, "Error\nMultiple Players\n");
}

//DIDN'T HANDLE SUBJECT INPUT, JUST SIMPLE SO_LONG MAP
void	map_constructor(t_player *player, char *file)
{
	name_check(file);
	//texture_check
	//colour_check
	map_count_row(player, file);
	if (player->height < 3)
	{
		write(2, "Error\nMap is too low\n", 21);
		exit(0);
	}
	init_map(player, file);
	check_symbols(player);
	check_player(player);
	//no need, draw_minimap already handles it
	//map->map[map->p_y][map->p_x] = '0';
}

void	draw_minimap(t_mlx *root)
{
	int	cur_x;
	int	cur_y;
	int	i;
	int	j;

	cur_y = 0;
	while (cur_y < root->player->height * MP_SCALER)
	{
		cur_x = 0;
		while (cur_x < root->player->width * MP_SCALER)
		{
			i = cur_x / MP_SCALER; 
			j = cur_y / MP_SCALER;
			if (!root->player->map[j][i])
				break ;
			if (root->player->map[j][i] == 32 || root->player->map[j][i] == '\n');
			else if (root->player->map[j][i] == '1')
				put_pixel(&root->frame, cur_x, cur_y, MP_WALL);
			else
				put_pixel(&root->frame, cur_x, cur_y, MP_FLOOR);
			cur_x++;
		}
		cur_y++;
	}
	//mlx_put_image_to_window(root->mlx, root->window, root->frame.img, 0, 0);
}

void	draw_light(t_mlx *root)
{
	int cur_y;
	int cur_x;
	double	j;
	double	i;
	/*double difference;
	double tol_dif;*/

	//tol_dif = 0.01;
	cur_y = 0;
	while (cur_y <= WINDOW_HEIGHT)
	{
		cur_x = 0;
		while (cur_x <= WINDOW_WIDTH)
		{
			j = (double)cur_y;
			i = (double)cur_x;
			if (j == -i + (root->player->x * MP_SCALER))
				put_pixel(&root->frame, cur_x, cur_y, MP_LIGHT);
			/*difference = atan((j / MP_SCALER) / (i / MP_SCALER)) - tan(root->player->orient);
			//printf("X: %f Y: %f\n", j / MP_SCALER, i / MP_SCALER);
			//if (atan((j / MP_SCALER) / (i / MP_SCALER)) > 2.000)
			//printf("ATAN: %f\n", atan((j / MP_SCALER) / (i / MP_SCALER)));
			//printf("ORIENT: %f\n", root->player->orient);
			//printf("DIF %f\n", difference);
			if ((-tol_dif <= difference) && (difference <= tol_dif))
			{
			//	printf("(%f / %d) / (%f / %d) = %f | ATAN: %f\n", j, MP_SCALER, i, MP_SCALER, ((j / MP_SCALER) / (i / MP_SCALER)), atan((j / MP_SCALER) / (i / MP_SCALER)));
				//printf("PUT_PIXEL: %d %d\n", cur_x, cur_y);
				put_pixel(&root->frame, cur_x, cur_y, MP_LIGHT);
			}*/
			cur_x++;
		}
		cur_y++;
	}
}

void	draw_player(t_mlx *root)
{
	int	cur_y;
	int	cur_x;

	cur_y = (root->player->y * MP_SCALER) - (MP_FAT / 2);
	while (cur_y <= (root->player->y * MP_SCALER) + (MP_FAT / 2))
	{
		cur_x = (root->player->x * MP_SCALER) - (MP_FAT / 2);
		while (cur_x <= (root->player->x * MP_SCALER) + (MP_FAT / 2))
		{
			put_pixel(&root->frame, cur_x, cur_y, MP_PLAYER);
			cur_x++;
		}
		cur_y++;
	}
}


