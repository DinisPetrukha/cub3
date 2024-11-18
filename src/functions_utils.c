/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:02:04 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/18 13:49:53 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_image(t_image *image)
{
	image->img_ptr = mlx_new_image(data_()->mlx_ptr, 500, 500);
	image->addr = mlx_get_data_addr(image->img_ptr, &image->bpp,
			&image->line_len, &image->endian);
}