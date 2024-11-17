/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:47:46 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/17 22:26:00 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// TEMPORARIAMENTE PROBLEMA DE SEG FAULT AO CLICAR NA CRUZ
int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
	 	free(data->mlx_ptr);
	return (0);
}

void	draw_square(int x, int y, int color)
{
	int	s_y;
	int	s_x;

	s_y = 0;
	while (s_y < BLOCK_SIZE)
	{
		s_x = 0;
		while (s_x < BLOCK_SIZE)
		{
			mlx_pixel_put(data_()->mlx_ptr, data_()->win_ptr, s_x + x, s_y + y, color);
			s_x++;
		}
		s_y++;
	}
}

void	draw_player(int x, int y, int color)
{
	int	p_y;
	int	p_x;

	y = (y + (BLOCK_SIZE / 2)) - PLAYER_SIZE_V1;
	x = (x + (BLOCK_SIZE / 2)) - PLAYER_SIZE_V1;
	p_y = 0;
	while (p_y < PLAYER_SIZE_V1)
	{
		p_x = 0;
		while (p_x < PLAYER_SIZE_V1)
		{
			mlx_pixel_put(data_()->mlx_ptr, data_()->win_ptr, p_x + x, p_y + y, color);
			p_x++;
		}
		p_y++;
	}
}


void	draw_map_v1(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_square(x * BLOCK_SIZE, y * BLOCK_SIZE, 0xFFFFFF);
			if (data->map[y][x] == '0' || data->map[y][x] == 'N')
				draw_square(x * BLOCK_SIZE, y * BLOCK_SIZE, 0xB09F9E);
			if (data->map[y][x] == 'N')
				draw_player(x * BLOCK_SIZE, y * BLOCK_SIZE, 0xFF0000);
			x++;
		}
		y++;
	}
}

// Retun 1 if success
// Return 0 in not success
int	game_init(void)
{
	data_()->mlx_ptr = mlx_init();
	data_()->win_ptr = mlx_new_window(data_()->mlx_ptr, 1500, 1500, "window");
	data_()->image_ptr = mlx_new_image(data_()->mlx_ptr, 1500, 1500);
	draw_map_v1(data_());
	mlx_hook(data_()->win_ptr, DestroyNotify, StructureNotifyMask,
		close_window, data_());
	mlx_loop(data_()->mlx_ptr);
	return (1);
}