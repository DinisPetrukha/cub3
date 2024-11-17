/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:37 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/17 13:51:32 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	*data_ref(void)
{
	static t_data	data;

	return (&data);
}

void	print_map(void)
{
	int	i;

	i = 0;
	if (data_ref()->map)
	{
		while (data_ref()->map[i])
		{
			printf("%s\n",data_ref()->map[i]);
			i++;
		}
	}
}
