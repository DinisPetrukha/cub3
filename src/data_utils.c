/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:37 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/17 18:36:21 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	*data_(void)
{
	static t_data	data;

	return (&data);
}

void	print_map(void)
{
	int	i;

	i = 0;
	if (data_()->map)
	{
		while (data_()->map[i])
		{
			printf("%s\n",data_()->map[i]);
			i++;
		}
	}
}
