#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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
	char	**map;
	char	*test;
}
	t_data;

// MY_FT_STRJOIN
char	*my_ft_strjoin(char const *s1, char const *s2);

// OPEN_FILE
int		open_file(char *path);
char	**read_map(int fd);

// DATA_UTILS
t_data	*data_ref(void);
void	print_map(void);

#endif