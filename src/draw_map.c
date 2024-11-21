/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:03:53 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/21 20:03:53 by dpetrukh         ###   ########.fr       */
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

void	draw_player(t_player *player)
{
	if (data_()->first_render == 0)
	{
		player->y = ((player->y * BLOCK_SIZE) + (BLOCK_SIZE / 2)) - (PLAYER_SIZE_V1 / 2);
		player->x = ((player->x *BLOCK_SIZE) + (BLOCK_SIZE / 2)) - (PLAYER_SIZE_V1 / 2);
		data_()->first_render = 1;
	}
	draw_square_to_image(player->x, player->y, 0x00FF0000, PLAYER_SIZE_V1, data_()->canva);
	draw_player_lines(player, 0xFFFFFF, data_()->canva);
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
	// int	line_midle[2];
	int	line_right[2];
	int	line_left[2];
	int	flag_1;
	int	flag_2;
	int	i;

	center[0] = player->y + (PLAYER_SIZE_V1 / 2);
	center[1] = player->x+ (PLAYER_SIZE_V1 / 2);
	line_len = 1000;
	i = 0;
	flag_1 = 0;
	flag_2 = 0;
	while (i < line_len)
	{
		// [0] = Y // [1] = X
		// line_midle[0] = center[0] + i * sin(player->angle);
		// line_midle[1] = center[1] + i * cos(player->angle);
		line_right[0] = center[0] + i * (sin(player->angle + 0.50));
		line_right[1] = center[1] + i * (cos(player->angle + 0.50));
		line_left[0] = center[0] + i * (sin(player->angle - 0.50));
		line_left[1] = center[1] + i * (cos(player->angle - 0.50));
		// if (!is_wall_line(data_(), line_midle[0], line_midle[1]))
		// 	my_mlx_pixel_put(image, line_midle[0] , line_midle[1], color);
		if (flag_1 == 0 && !is_wall_line(data_(), line_right[0], line_right[1], &flag_1))
			my_mlx_pixel_put(image, line_right[0] , line_right[1], color);
		if (flag_2 == 0 && !is_wall_line(data_(), line_left[0], line_left[1], &flag_2))
			my_mlx_pixel_put(image, line_left[0] , line_left[1], color);
		i++;
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