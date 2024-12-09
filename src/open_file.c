/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:38:17 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/12/09 09:49:58 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Função para calcular a altura do mapa
void	set_map_size(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x > data_()->matrix_width)
			data_()->matrix_width = x;
		y++;
	}
	data_()->matrix_height = y;
}

void free_mat(char **mat)
{
	int i = 0;

	while (mat[i] != NULL)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

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
	free(map_inline);
	if (!map_index)
	{
		ft_putstr_fd("Error\nMap is empty\n", 2);
		return (NULL);
	}
	set_map_size(map_index);
	if (data_()->matrix_height < 3)
		exitmap(map_index, 1, "Error\nMap is too low\n");
	return (map_index);
}

int	file_name_verification(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '.')
			break ;
		i++;
	}
	if (!ft_strncmp(&path[i], ".cub", 5))
		return (1);
	return (0);
}



// Return 1 if all correct
// Return 0 if not correct and print the error
int	open_file(char *path)
{
	int	fd;

	//Check if ends with .cub
	if (!file_name_verification(path))
	{
		ft_putstr_fd("Error\nInvalid file name\n", 2);
		exit(1);
	}
	//Open Map
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nNot able to open the file:");
		exit(1);
	}
	//Read Map
	data_()->map = read_map(fd);
	if (data_()->map == NULL)
		exit(1);
	print_map(); // <-- Test
	//Check if valid map
	check_symbols(data_()->map);
	init_data(data_());
	//Load all necessary data to t_data struct

	//Return 1 if all good
	return (1);
}
