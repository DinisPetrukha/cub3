#include "./includes/cub3d.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y *img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

//1 if there is a collision. 0 if there isn't (no wall)
int	collision(char **map, float pos_x, float pos_y)
{
	int i;
	int j;

	i = (int)pos_x;
	j = (int)pos_y;
	if (map[j][i] == '1')
		return (1);
	return (0);
}


/*
void	moveplayer(t_mlx *root, int movy, int movx)
{
	//colision
	if (MP_FAT / 2)

	root->player->x += movx 0.2;
}*/


void	player_input(t_binds *key, int keycode, bool pressed)
{
	if (keycode == 115)
		key->move_up = pressed;
	if (keycode == 119)
		key->move_down = pressed;
	if (keycode == 97)
		key->move_left = pressed;
	if (keycode == 100)
		key->move_right = pressed;
	if (keycode == 65361)
		key->camera_left = pressed;
	if (keycode == 65363)
		key->camera_right = pressed;
	if (keycode == 65307)
		key->esc = pressed;
}


int	key_lift(int keycode, t_mlx *root)
{
	player_input(root->key, keycode, 0);
	return (0);
}

int	key_press(int keycode, t_mlx *root)
{
	player_input(root->key, keycode, 1);
	return (0);
}

void	apply_changes(t_mlx *root, t_binds *key)
{
	if (key->move_up && !collision(root->player->map, root->player->x, root->player->y + 0.2))
		root->player->y += 0.2;
	if (key->move_down && !collision(root->player->map, root->player->x, root->player->y - 0.2))
		root->player->y -= 0.2;
	if (key->move_left && !collision(root->player->map, root->player->x - 0.2, root->player->y))
		root->player->x -= 0.2;
	if (key->move_right && !collision(root->player->map, root->player->x + 0.2, root->player->y))
		root->player->x += 0.2;
	if (key->camera_left)
	{
		if (root->player->orient == 358)
			root->player->orient = 0;
		else
			root->player->orient += 2;
	}
	//CAREFULL WITH ODD NUMBERS
	if (key->camera_right)
	{
		if (root->player->orient == 0)
			root->player->orient = 358;
		else
			root->player->orient -= 2;
	}
	if (key->esc)
		killmlx(root, 0);
}

int	loop_handler(t_mlx *root)
{
	struct timespec instant;

	clock_gettime(CLOCK_REALTIME, &instant);
	if ((root->dif_timer != instant.tv_nsec / 100000000) && (instant.tv_nsec / 100000000 % 1 == 0))
	{
		apply_changes(root, root->key); 
		draw_minimap(root)2
		draw_player(root);
		draw_light(root);
		printf("-----> PLAYER ORIENT: %f\n", root->player->orient);
		printf("-----> PLAYER X: %f\n", root->player->x);
		printf("> PLAYER X: %i\n", (int)root->player->x);
		printf("-----> PLAYER Y: %f\n", root->player->y);
		printf("> PLAYER Y: %i\n", (int)root->player->y);
		mlx_put_image_to_window(root->mlx, root->window, root->frame.img, 0, 0)	;
		root->dif_timer = instant.tv_nsec / 100000000;
	}
	return (0);
}

void	init_keys(t_binds *key)
{
	key->move_up = 0;
	key->move_down = 0;
	key->move_left = 0;
	key->move_right = 0;
	key->camera_left = 0;
	key->camera_right = 0;
	key->esc = 0;
}

int	main(int argc, char *argv[])
{
	t_mlx	root;
	t_player	player;
	t_image		frame;
	t_binds		key;

	if (argc != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 32);
		return (0);
	}
	root.dif_timer = 0;
	map_constructor(&player, argv[1]);
	ft_putmat(player.map);
	printf("WIDTH: %d\n", player.width);
	printf("HEIGHT: %d\n", player.height);
	printf("PLAYER X: %f\n", player.x);
	printf("PLAYER Y: %f\n", player.y);
	player.orient = 45;
	printf("PLAYER ORIENT: %f\n", player.orient);
	init_keys(&key);
	root.player = &player;
	root.mlx = mlx_init();
	if (!root.mlx)
		exitmap(player.map, 1, "Error: Couldn't init MLX\n");
	//root->asset =
	if (MP_SCALER * player.width >= WINDOW_WIDTH || MP_SCALER * player.height >= WINDOW_HEIGHT)
		printf("WARNING: MINIMAP IS AS BIG AS THE WINDOW\n");
	//WARNING FOR WRONG RATIO
	frame.img = mlx_new_image(root.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!frame.img)
		exit(1); // leaklessly
	frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_length, &frame.endian);
	root.frame = frame;
	root.key = &key;
	root.window = mlx_new_window(root.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!root.window)
		exit(1);  //leaklessly
	//mlx_hook(root.window, 17, 1L << 0, exit_handler, &root);
	//mlx_key_hook(root.window, input_handler, &root);
	mlx_hook(root.window, 2, 1L << 0, key_press, &root);
	mlx_hook(root.window, 3, 1L << 1, key_lift, &root);
	//frame render
	mlx_loop_hook(root.mlx, loop_handler, &root);
	mlx_loop(root.mlx);
	return (0);
}
