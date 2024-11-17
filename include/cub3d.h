#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define BLOCK_SIZE 32
# define PLAYER_SIZE_V1 12

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

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image_ptr;
	char	**map;
}
	t_data;

// MY_FT_STRJOIN
char	*my_ft_strjoin(char const *s1, char const *s2);

// OPEN_FILE
int		open_file(char *path);
char	**read_map(int fd);

//FUNCTIONs_UTILS

// DATA_UTILS
t_data	*data_(void);
void	print_map(void);

//GAME_INIT
int		game_init(void);

#endif