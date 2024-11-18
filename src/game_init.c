/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:47:46 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/18 15:54:11 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
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
			my_mlx_pixel_put(image, s_x + x, s_y + y, color);
			s_x++;
		}
		s_y++;
	}
}

void	draw_player(t_player *player)
{
	int	x;
	int	y;

	y = ((player->y * BLOCK_SIZE) + (BLOCK_SIZE / 2)) - (PLAYER_SIZE_V1 / 2);
	x = ((player->x *BLOCK_SIZE) + (BLOCK_SIZE / 2)) - (PLAYER_SIZE_V1 / 2);
	draw_square_to_image(x, y, 0x00FF0000, PLAYER_SIZE_V1, data_()->canva);
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
	return (1);
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
	//my_mlx_pixel_put(data_()->canva, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data_()->mlx_ptr, data_()->win_ptr, data_()->canva->img_ptr, 0, 0);
	//mlx_loop_hook(data_()->mlx_ptr, draw_map_v1, data_());
	mlx_loop(data_()->mlx_ptr);
	return (1);
}