/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:15:29 by sephilip          #+#    #+#             */
/*   Updated: 2024/04/11 12:16:22 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <time.h>

//#define malloc(x) NULL
# define MP_SCALER	50	
# define MP_WALL	2516615
# define MP_FLOOR	15329736
# define MP_PLAYER	6579400
# define MP_LIGHT	13158450
# define MP_FAT		8

# define WINDOW_HEIGHT	1000
# define WINDOW_WIDTH	1000

# define ASSET_NBR	128

typedef struct s_image
{
	void	*img;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_image;

typedef struct s_player
{
	char	**map;
	int		height;
	int		width;
	float		x;
	float		y;
	float		orient;
}	t_player;

typedef struct s_binds
{
	int	move_up;
	int	move_down;
	int	move_left;
	int	move_right;
	int	camera_left;
	int	camera_right;
	int	esc;
}	t_binds;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	t_player	*player;
	t_binds		*key;
	t_image		frame;
	int		dif_timer;
	//t_image		*asset;
	//int			s;
}	t_mlx;


//CUB3D.C
void	put_pixel(t_image *img, int x, int y, int color);

//MINIMAP.C
void	map_count_row(t_player *player, char *file);
void	name_check(char *name);
void	init_map(t_player *player, char *file);
int	is_protected(t_player *player, int y, int x);
void	check_symbols(t_player *player);
void	check_player(t_player *player);
void	map_constructor(t_player *player, char *file);
void	draw_minimap(t_mlx *root);
void	draw_light(t_mlx *root);
void	draw_player(t_mlx *root);

//DESTROY.C
void	exitmap(char **map, int ret, char *msg);
void	free_map(char **map, int ret);
void	killmlx(t_mlx *root, int ret);
void	ft_putmat(char **mat);

#endif /*SO_LONG_H */
