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

# define WINDOW_HEIGHT	1000
# define WINDOW_WIDTH	1000

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
# include <stdbool.h>
# include <time.h>

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

typedef struct s_player {
	float	x;
	float	y;
	float	orient;
	char	angle_pos;
}
	t_player;

typedef struct s_data {
	void		*mlx_ptr;
	void		*window;
	void		*image_ptr;
	char		**map;
	int			first_render;
	int			matrix_width;
	int			matrix_height;
	int			dif_timer;
	t_binds		*key;
	t_image		*frame;
	t_player	*player;
}
	t_data;

// MY_FT_STRJOIN
char	*my_ft_strjoin(char const *s1, char const *s2);

// OPEN_FILE
int		open_file(char *path);
char	**read_map(int fd);
void	free_mat(char **mat);

//FUNCTIONS_UTILS
void	init_keys(t_data *data);
void	init_image(t_image *image);

// DATA_UTILS
t_data	*data_(void);
void	print_map(void);

//GAME_INIT
int		game_init(void);
void	init_data(t_data *data);

//CLOSE_FREE
int		close_window(t_data *data);

//PLAYER_MOVEMENT
int		is_wall_player(t_data *data, float next_y, float next_x);
int		is_wall_line(t_data *data, float next_y, float next_x, int *flag);
void	player_movement(int keycode, t_data *data);
int		keypress(int keycode, t_data *data);
int		key_lift(int keycode, t_data *data);
void	player_input(t_binds *key, int keycode, bool pressed);

//DRAW_MAP
int		loop_handler(void *param);
void	draw_player_lines(t_player *player, int color, t_image *image);
void	draw_square_to_image(int x, int y, int color, int size, t_image *image);
void	draw_player(t_player *player);
void	my_mlx_pixel_put(t_image *image, int y, int x, int color);

//IS_VALID
void	exitmap(char **map, int ret, char *msg);
void	free_map(char **map, int ret);
void	check_symbols(char **map);
void	check_player(char **map, t_player *player);

#endif