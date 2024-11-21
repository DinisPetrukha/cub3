/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:02:12 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/21 20:02:12 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// TEMPORARIAMENTE PROBLEMA DE SEG FAULT AO CLICAR NA CRUZ
int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->canva->img_ptr);
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