/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:38:17 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/11/17 13:51:56 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**read_map(int fd)
{
	char	*map_inline;
	char	*line;
	char	*tmp;
	char	**map_index;

	line = NULL;
	map_inline = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = map_inline;
		map_inline = my_ft_strjoin(map_inline, line);
		free(line);
		free(tmp);
	}
	map_index = ft_split(map_inline, '\n');
	if (!map_index)
	{
		perror("Error\nMap is empty\n");
		return (NULL);
	}
	return (map_index);
}

int	open_file(char *path)
{
	int	fd;

	//Check if ends with .cub

	//Open Map
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nNot able to open the file:");
		return (0);
	}
	//Read Map
	data_ref()->map = read_map(fd);
	print_map();
	//Check if valid map

	return (1);
}