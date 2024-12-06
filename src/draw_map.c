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

int	float_equal(float a, float b)
{
	float	difference;
	float	toleration;

	toleration = 0.001;
	difference = a - b;
	if ((-toleration <= difference) && (difference <= toleration))
		return (1);
	return (0);
}

int	collision(char	**map, float pos_x, float pos_y, float angle)
{
	int	i;
	int	j;

	i = (int)pos_x;
	j = (int)pos_y;
	if (float_equal((float)i, pos_x) && i != 0 && ((angle > M_PI / 2)
		&& (angle < 3 * M_PI / 2)))
		i--;
	if (float_equal((float)j, pos_y) && j != 0 && ((angle > M_PI)))
		j--;
	//printf("CHECK COLLISION: map[%d][%d] = %c\n", j, i, map[j][i]); 
	if (map[j][i] == '1')
		return (1);
	return (0);
}

float	distance(float x1, float y1, float x2, float y2)
{
	float sqr_difx;
	float sqr_dify;
	float	sum;
	float	value;

	sqr_difx = (x2 - x1) * (x2 - x1);
	sqr_dify = (y2 - y1) * (y2 - y1);
	sum = sqr_difx + sqr_dify;
	value = sqrt(sum);
	return (value);
}

int	vertical_ray(t_data *data, float m, float n, float interval, float angle)
{
	float	center[2];
	float	new_x;
	float	y;

	if (interval == 0)
		return (-1);
	center[0] = (data->player->x + (PLAYER_SIZE_V1 / 2));
	center[1] = (data->player->y + (PLAYER_SIZE_V1 / 2));
	if (interval > 0)
		new_x = ceilf(center[0] / BLOCK_SIZE) * BLOCK_SIZE;
	else
		new_x = floorf(center[0] / BLOCK_SIZE) * BLOCK_SIZE;
	while (1)
	{
		y = m * new_x + n;
		//printf("VER: %f %f\n", new_x, y);
		if (y < 0 || y > (data->matrix_height * BLOCK_SIZE))
			return (-1);
		if (collision(data->map, new_x / BLOCK_SIZE, y / BLOCK_SIZE, angle))
			break ;
		new_x += interval;
	}
	//printf("DISTANCE: %f %f %f %f\n", center[0], center[1], new_x, y);
	return (distance(center[0], center[1], new_x, y));
}

int	horizontal_ray(t_data *data, float m, float n, float interval, float angle)
{
	float	center[2];
	float	x;
	float	new_y;

	if (interval == 0)
		return (-1);
	center[0] = (data->player->x + (PLAYER_SIZE_V1 / 2));
	center[1] = (data->player->y + (PLAYER_SIZE_V1 / 2));
	if (interval > 0)
		new_y = ceilf(center[1] / BLOCK_SIZE) * BLOCK_SIZE;
	else
		new_y = floorf(center[1] / BLOCK_SIZE) * BLOCK_SIZE;
	while (1)
	{
		x = (new_y - n) / m;
		//y = m * new_x + n;
		//printf("HOR: %f %f\n", x, new_y);
		//WONT WORK WITH IRREGULAR-END MAPS
		if (x < 0 || x > (data->matrix_width * BLOCK_SIZE))
			return (-1);
		if (collision(data->map, x / BLOCK_SIZE, new_y / BLOCK_SIZE, angle))
			break ;
		new_y += interval;
	}
	return (distance(center[0], center[1], x, new_y));
}

float	rainbow(t_data *data, t_player *player, float angle)
{
	float	center[2];
	float	increment[2];
	float	rays[2];
	float	m;
	float	n;

	center[0] = (player->x + (PLAYER_SIZE_V1 / 2));
	center[1] = (player->y + (PLAYER_SIZE_V1 / 2));
	if (sin(angle) > 0)
		increment[1] = BLOCK_SIZE;
	else if (sin(angle) < 0)
		increment[1] = -BLOCK_SIZE;
	else
		increment[1] = 0;
	if (cos(angle) > 0)
		increment[0] = BLOCK_SIZE;
	else if  (cos(angle) < 0)
		increment[0] = -BLOCK_SIZE;
	else
		increment[0] = 0;
	if (angle == M_PI / 2 || angle == 3 * M_PI / 2)
		return (horizontal_ray(data, 0, 0, increment[1], angle));
	m = tan(angle);
	n = center[1] - (m * center[0]);
	//printf("PX: %f PY: %f\n", center[0], center[1]);
	//printf("Y = %f x + %f | ANGLE: %f\n", m, n, angle);
	rays[0] = horizontal_ray(data, m, n, increment[1], angle);
	//printf("horizontal_ray: %f\n", rays[0]);
	rays[1] = vertical_ray(data, m, n, increment[0], angle);
	//printf("vertical_ray: %f\n", rays[1]);
	if ((rays[0] <= rays[1] && rays[0] != -1) || rays[1] == -1)
		return (rays[0]);
	return (rays[1]);
}

void	draw_3d(t_data *data, t_player *player, t_image *image)
{
	//#define RENDER_DISTANCE == FOV_DEEPNESS
	//0.5 radians == 60o
//	float	render_distance;
	float	current_angle;
	float	distant;
	float	angle_step;
	int	i;

	i = 0;
	current_angle = 0;
	//render_distance = 300;
	angle_step = (WINDOW_WIDTH / FOV_WIDE);
	while (i < WINDOW_WIDTH)
	{

		distant = rainbow(data, player, (player->orient + current_angle) <= FOV_DEEPNESS);
		//only in range of proper distance 
		//add color do #define
		//printf("DISTANCE: %f\n", distant);
		draw_half(image, 13158350, 15329736);
		if ((int)distant > 6 && ((int)distant <= FOV_DEEPNESS))
			draw_bar(image, distant, 500);
		current_angle += angle_step;
		i++;
	}
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
	//draw_3d(data_(), player, image);
	//printf("DISTANCE: %f\n", rainbow(data_(), player, (player->orient + angle)));

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
		//player->y = ((player->y * BLOCK_SIZE) + (BLOCK_SIZE / 2)) - (PLAYER_SIZE_V1 / 2);
		//player->x = ((player->x *BLOCK_SIZE) + (BLOCK_SIZE / 2)) - (PLAYER_SIZE_V1 / 2);
		player->y = (player->y * BLOCK_SIZE);
		player->x = (player->x * BLOCK_SIZE);
		
		data_()->first_render = 1;
	}
	//printf("PL_X: %f PL_Y: %f\n", player->x, player->y);
	draw_square_to_image(player->x, player->y, 0x00FF0000, PLAYER_SIZE_V1, data_()->frame);
	draw_line_at_angle(player, 0, 0xFFFFFF, data_()->frame);
	//draw_player_rays(player, -FOV_WIDE, FOV_WIDE, FOV_DEEPNESS, 0xFFFFFF, data_()->frame);
}

//ceil color and floor color 
void	draw_half(t_image *image, int ccolor, int fcolor)
{
	//[0] = x [1] = y
	int	cur_x;
	int	cur_y;

	cur_y = 0;
	while (cur_y < WINDOW_HEIGHT / 2)
	{
		cur_x = 0;
		while (cur_x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(image, cur_y, cur_x, ccolor);
			cur_x++;
		}
		cur_y++;
	}
	while (cur_y < WINDOW_HEIGHT)
	{
		cur_x = 0;
		while (cur_x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(image, cur_y, cur_x, fcolor);
			cur_x++;
		}
		cur_y++;
	}
}

void	draw_bar(t_image *image, float distant, int pos_x)
{
	//pixer per distance
	float	ppd;
	float	bar_size;
	int	cur_y;

	ppd = (FOV_DEEPNESS - (PLAYER_SIZE_V1 / 2)) / (WINDOW_HEIGHT - 1);
	bar_size = WINDOW_HEIGHT - (distant - (PLAYER_SIZE_V1 / 2)) * ppd;
	cur_y = (int)ceilf(bar_size) / 2;
	while (cur_y < (int)ceilf(bar_size))
	{
		my_mlx_pixel_put(image, cur_y, pos_x, 6617700);
		cur_y++;
	}
}
/*
void	draw_rectangle_to_image(t_image *image, int start[2], int end[2], int color)
{
	//[0] = x [1] = y
	int	cur_x;
	int	cur_y;

	cur_y = start[1];
	while (cur_y < end[1])
	{
		cur_x = start[0];
		while (cur_x < end[1])
		{
			my_mlx_pixel_put(image, cur_y, cur_x, color);
			cur_x++;
		}
		cur_y++;
	}
}*/

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
	// if ((data->dif_timer != instant.tv_nsec / 100000000) && (instant.tv_nsec / 100000000 % 1 == 0))
	// {
		apply_changes(data);
		//draw_3d(data, data->player, data->frame);
		//draw_half(data->frame, 13158350, 15329736);
		draw_minimap(data);
		draw_player(data->player);
		mlx_put_image_to_window(data_()->mlx_ptr, data_()->window, data_()->frame->img_ptr, 0, 0);
	// 	data->dif_timer = instant.tv_nsec / 100000000;
	// }
	return (0);
}
