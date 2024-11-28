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

void	draw_line_at_angle(t_player *player, float angle, int color, t_image *image)
{
	int		center[2];
	int		line_len;
	int		line[2];
	int		i;
	int		hit_wall_flag;

	center[0] = player->y + (PLAYER_SIZE_V1 / 2);
	center[1] = player->x + (PLAYER_SIZE_V1 / 2);
	line_len = 500;
	i = 0;
	hit_wall_flag = 0;
	while (i < line_len && hit_wall_flag == 0)
	{
		line[0] = center[0] + i * sin(player->orient + angle);
		line[1] = center[1] + i * cos(player->orient + angle);
		if (!is_wall_line(data_(), line[0], line[1], &hit_wall_flag))
			my_mlx_pixel_put(image, line[0], line[1], color);
		i++;
	}
}

void	draw_player_rays(t_player *player, float angle_min, float angle_max, int num_rays, int color, t_image *image)
{
	float	angle_step;
	float	current_angle;
	int		i;

	// Divide o intervalo entre os ângulos em partes iguais
	angle_step = (angle_max - angle_min) / (num_rays - 1);
	current_angle = angle_min;

	i = 0;
	while (i < num_rays)
	{
		draw_line_at_angle(player, current_angle, color, image);
		current_angle += angle_step;
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
	draw_square_to_image(player->x, player->y, 0x00FF0000, PLAYER_SIZE_V1, data_()->frame);
	// draw_player_lines(player, 0xFFFFFF, data_()->frame);
	draw_player_rays(player, -0.50, 0.50, 50, 0xFFFFFF, data_()->frame);
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




// void	draw_player_lines(t_player *player, int color, t_image *image)
// {
// 	int	center[2];
// 	int	line_len;
// 	// int	line_midle[2];
// 	int	line_right[2];
// 	int	line_left[2];
// 	int	flag_1;
// 	int	flag_2;
// 	int	i;

// 	center[0] = player->y + (PLAYER_SIZE_V1 / 2);
// 	center[1] = player->x+ (PLAYER_SIZE_V1 / 2);
// 	line_len = 500;
// 	i = 0;
// 	flag_1 = 0;
// 	flag_2 = 0;
// 	while (i < line_len)
// 	{
// 		// [0] = Y // [1] = X
// 		// line_midle[0] = center[0] + i * sin(player->orient);
// 		// line_midle[1] = center[1] + i * cos(player->orient);
// 		line_right[0] = center[0] + i * (sin(player->orient + 0.50));
// 		line_right[1] = center[1] + i * (cos(player->orient + 0.50));
// 		line_left[0] = center[0] + i * (sin(player->orient - 0.50));
// 		line_left[1] = center[1] + i * (cos(player->orient - 0.50));
// 		// if (!is_wall_line(data_(), line_midle[0], line_midle[1], color, &flag_1))
// 		// 	my_mlx_pixel_put(image, line_midle[0] , line_midle[1], color);
// 		if (flag_1 == 0 && !is_wall_line(data_(), line_right[0], line_right[1], &flag_1))
// 			my_mlx_pixel_put(image, line_right[0] , line_right[1], color);
// 		if (flag_2 == 0 && !is_wall_line(data_(), line_left[0], line_left[1], &flag_2))
// 			my_mlx_pixel_put(image, line_left[0] , line_left[1], color);
// 		i++;
// 	}
// }




void	draw_minimap(t_data *data)
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
				draw_square_to_image(x * BLOCK_SIZE , y * BLOCK_SIZE , 0xFFFFFF, BLOCK_SIZE, data->frame);
			if (data->map[y][x] == '0' || data->map[y][x] == 'N')
				draw_square_to_image(x * BLOCK_SIZE , y * BLOCK_SIZE , 0xB09F9E, BLOCK_SIZE, data->frame);
			x++;
		}
		y++;
	}
}

int	loop_handler(void *param)
{
	struct timespec instant;

	clock_gettime(CLOCK_REALTIME, &instant);
	t_data *data = (t_data *)param;
	if ((data->dif_timer != instant.tv_nsec / 100000000) && (instant.tv_nsec / 100000000 % 1 == 0))
	{
		draw_minimap(data);
		draw_player(data->player);
		mlx_put_image_to_window(data_()->mlx_ptr, data_()->window, data_()->frame->img_ptr, 0, 0);
		data->dif_timer = instant.tv_nsec / 100000000;
	}
	return (0);
}