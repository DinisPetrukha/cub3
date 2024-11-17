NAME = cub3d

SRC = src/my_ft_strjoin.c src/main.c src/data_utils.c src/open_file.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g #-lreadline -g #fsanitize=address

INCLUDES = -I /libft/

LIBFT = include/libft/libft.a

LIBFT_LIB = include/libft

all: $(LIBFT) $(OBJ) $(NAME)

$(LIBFT):
	@echo "\n-Compiling Libft...\n"
	@$(MAKE) -C $(LIBFT_LIB)

	@echo "\n-Compiling $(NAME)..."

$(OBJ): %.o: %.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@echo "n-Linking $(NAME) with libft..."
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)
	@make clean
	@echo "n--------------------------------"
	@echo "$(NAME) is ready!"
	@echo "-------------------------------"

clean:
	@echo "n-Cleaning Libft..."
	$(MAKE) -C $(LIBFT_LIB) clean
	@echo "n-Cleaning object files..."
	@rm -f $(OBJ)
	@echo "n--------------------------------"
	@echo "$(NAME) object files cleaned!"
	@echo "-------------------------------"

fclean: clean
	@echo "n-Cleaning $(NAME) and libft..."
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_LIB) fclean
	@echo "n--------------------------------"
	@echo "$(NAME) object files cleaned!"
	@echo "-------------------------------"

re: fclean all

.PHONY: all clean fclean re r
