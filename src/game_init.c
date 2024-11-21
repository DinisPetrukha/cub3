/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:47:46 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/21 15:19:31 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_image *image, int y, int x, int color)
{
	char	*dst;

	if (color == -16777216)
	 	return ;
	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

// TEMPORARIAMENTE PROBLEMA DE SEG FAULT AO CLICAR NA CRUZ
int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
	 	free(data->mlx_ptr);
	if (data->canva)
		free(data->canva);
	if (data->player)
		free(data->player);
	return (0);
}

void	draw_square_to_image(int x, int y, int color, int size, t_image *image)
{
	int	s_y;
	int	s_x;

	s_y = 0;
	while (s_y < size)
	{
		s_x = 0;
		while (s_x < size)
		{
			my_mlx_pixel_put(image, s_y + y, s_x + x, color);
			s_x++;
		}
		s_y++;
	}
}

void	draw_player_lines(t_player *player, int color, t_image *image)
{
	int	center[2];
	int	line_len;
	int	cur_y;
	int	cur_x;
	int	i;
	//[0] == y
	//[1] == x;

	// color = 0x000000;
	center[0] = player->y + (PLAYER_SIZE_V1 / 2);
	center[1] = player->x+ (PLAYER_SIZE_V1 / 2);
	line_len = 30;
	i = 0;
	while (i < line_len)
	{
		cur_y = center[0] + i * sin(player->angle);
		cur_x = center[1] + i * cos(player->angle);
		my_mlx_pixel_put(image, cur_y , cur_x, color);
		i++;
	}
}

void	draw_player(t_player *player)
{
	if (data_()->first_render == 0)
	{
		player->y = ((player->y * BLOCK_SIZE) + (BLOCK_SIZE / 2)) - (PLAYER_SIZE_V1 / 2);
		player->x = ((player->x *BLOCK_SIZE) + (BLOCK_SIZE / 2)) - (PLAYER_SIZE_V1 / 2);
		data_()->first_render = 1;
	}
	draw_square_to_image(player->x, player->y, 0x00FF0000, PLAYER_SIZE_V1, data_()->canva);
	draw_player_lines(player, 0x00FF0000, data_()->canva);
}

void	init_data(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->player = malloc(sizeof(t_player));
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N')
			{
				data->player->y = y;
				data->player->x = x;
			}
			x++;
		}
		y++;
	}
}

int	draw_map_v1(void *param)
{
	int	y;
	int	x;

	y = 0;
	t_data *data = (t_data *)param;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_square_to_image(x * BLOCK_SIZE , y * BLOCK_SIZE , 0xFFFFFF, BLOCK_SIZE, data->canva);
			if (data->map[y][x] == '0' || data->map[y][x] == 'N')
				draw_square_to_image(x * BLOCK_SIZE , y * BLOCK_SIZE , 0xB09F9E, BLOCK_SIZE, data->canva);
			x++;
		}
		y++;
	}
	// Draw Player
	draw_player(data->player);
	mlx_put_image_to_window(data_()->mlx_ptr, data_()->win_ptr, data_()->canva->img_ptr, 0, 0);
	return (1);
}


int	is_wall(t_data *data, float next_y, float next_x)
{
	int	top_left[2];
	int	top_right[2];
	int	bottom_right[2];
	int	bottom_left[2];

	// Convertendo as coordenadas do jogador para blocos na matriz
	top_left[0] = (int)(next_y / BLOCK_SIZE);
	top_left[1] = (int)(next_x / BLOCK_SIZE);

	top_right[0] = (int)(next_y / BLOCK_SIZE);
	top_right[1] = (int)((next_x + PLAYER_SIZE_V1) / BLOCK_SIZE);

	bottom_right[0] = (int)((next_y + PLAYER_SIZE_V1) / BLOCK_SIZE);
	bottom_right[1] = (int)((next_x + PLAYER_SIZE_V1) / BLOCK_SIZE);

	bottom_left[0] = (int)((next_y + PLAYER_SIZE_V1) / BLOCK_SIZE);
	bottom_left[1] = (int)(next_x / BLOCK_SIZE);

	printf("Top_Left: [%i][%i]\nTop_Right: [%i][%i]\nBottom_Right:[%i][%i]\nBottom_Left:[%i][%i]\n----------\n",
			top_left[0], top_left[1],
			top_right[0], top_right[1],
			bottom_right[0], bottom_right[1],
			bottom_left[0], bottom_left[1]);
	printf("POSITION: %c\n", data->map[(int)top_left[0]][(int)top_left[1]]);
	// Verificar se qualquer um dos pontos onde o jogador estaria é uma parede
	if (data->map[top_left[0]][top_left[1]] == '1' ||    // Canto superior esquerdo
		data->map[top_right[0]][top_right[1]] == '1' ||   // Canto superior direito
		data->map[bottom_right[0]][bottom_right[1]] == '1' || // Canto inferior direito
		data->map[bottom_left[0]][bottom_left[1]] == '1')  // Canto inferior esquerdo
		return (1); // Colisão detectada

	return (0); // Sem colisão
}

void	player_movement(int keycode, t_data *data)
{
	t_player	*player;

	player = data->player;
	if (keycode == W || keycode == UP)
	{
		if (!is_wall(data, player->y + PLAYER_SPEED * sin(player->angle), player->x + PLAYER_SPEED * cos(player->angle)))
		{
			player->y += PLAYER_SPEED * sin(player->angle);
			player->x += PLAYER_SPEED * cos(player->angle);
		}
	}
	if (keycode == S || keycode == DOWN)
	{
		if (!is_wall(data, player->y - PLAYER_SPEED * sin(player->angle), player->x - PLAYER_SPEED * cos(player->angle)))
		{
			player->y -= PLAYER_SPEED * sin(player->angle);
			player->x -= PLAYER_SPEED * cos(player->angle);
		}
	}
	if (keycode == A || keycode == LEFT)
	{
		player->angle -= 0.1;
		if (player->angle < 0)
			player->angle += 2 * M_PI;
	}
	if (keycode == D || keycode == RIGHT)
	{
		player->angle += 0.1;
		if (player->angle < 0)
			player->angle -= 2 * M_PI;
	}
	draw_map_v1(data);
}

int	keypress(int keycode, t_data *data)
{
	player_movement(keycode, data);
	return (1);
}

// Retun 1 if success
// Return 0 if not success
int	game_init(void)
{
	data_();
	// Initializing The Mlx
	data_()->mlx_ptr = mlx_init();
	if (!data_()->mlx_ptr)
		return (0);
	data_()->win_ptr = mlx_new_window(data_()->mlx_ptr, 500, 500, "window");
	if (!data_()->win_ptr)
		return (0);
	// Initializing The Main Canva and Map_Layer
	init_data(data_());
	data_()->canva = malloc(sizeof(t_image));
	init_image(data_()->canva);
	// Drawing Like a Picasso
	draw_map_v1(data_());
	// Close window when X it's Clicked
	mlx_hook(data_()->win_ptr, DestroyNotify, StructureNotifyMask,
		close_window, data_());
	// Loop The Game
	mlx_hook(data_()->win_ptr, KeyPress, KeyPressMask, keypress, data_());
	mlx_loop(data_()->mlx_ptr);
	mlx_loop_hook(data_()->mlx_ptr, draw_map_v1, data_());
	return (1);
}