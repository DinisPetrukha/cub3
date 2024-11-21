#ifndef CUB3_H
# define CUB3_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define BLOCK_SIZE 32
# define PLAYER_SIZE_V1 12

# define PLAYER_SPEED 4

# define W 119
# define UP 65362
# define S 115
# define DOWN 65364
# define A 97
# define LEFT 65361
# define D 100
# define RIGHT 65363

# define ESC 65307
# define Q 113

# include <math.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_player {
	float	x;
	float	y;
	float	angle;
	t_image	*image;
}
	t_player;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image_ptr;
	char		**map;
	int			first_render;
	int			matrix_width;
	int			matrix_height;
	t_image		*canva;
	t_image		*map_layer;
	t_player	*player;
}
	t_data;

// MY_FT_STRJOIN
char	*my_ft_strjoin(char const *s1, char const *s2);

// OPEN_FILE
int		open_file(char *path);
char	**read_map(int fd);

//FUNCTIONS_UTILS

// DATA_UTILS
t_data	*data_(void);
void	print_map(void);

//GAME_INIT
int		game_init(void);
void	init_image(t_image *image);

//CLOSE_FREE
int		close_window(t_data *data);

//PLAYER_MOVEMENT
int		is_wall_player(t_data *data, float next_y, float next_x);
int		is_wall_line(t_data *data, float next_y, float next_x, int *flag);
void	player_movement(int keycode, t_data *data);
int		keypress(int keycode, t_data *data);

//DRAW_MAP
int		draw_map_v1(void *param);
void	draw_player_lines(t_player *player, int color, t_image *image);
void	draw_square_to_image(int x, int y, int color, int size, t_image *image);
void	draw_player(t_player *player);
void	my_mlx_pixel_put(t_image *image, int y, int x, int color);

#endif