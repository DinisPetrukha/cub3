NAME= cub3d

CC= cc
CFLAGS= -Wall -Werror -Wextra -g	

SOURCES= cub3d.c minimap.c destroy.c

OBJ_DIR= obj
OBJ= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

MLX_DIR= ./mlx
MLX= $(MLX_DIR)/libmlx_Linux.a -lXext -lX11 -lm -lz

LIBFT_DIR= ./includes/libft
LIBFT= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(MLX) $(LIBFT)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all fclean clean re
