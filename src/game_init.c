/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:47:46 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/21 20:10:29 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
			if (data->map[y][x] == 'N'
				|| data->map[y][x] == 'S'
				|| data->map[y][x] == 'E'
				|| data->map[y][x] == 'W')
			{
				data->player->y = y;
				data->player->x = x;
			}
			x++;
		}
		data->matrix_width = x;
		y++;
	}
	data->matrix_height = y;
	data->player->angle = 0;
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