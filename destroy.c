#include "./includes/cub3d.h"

void	exitmap(char **map, int ret, char *msg)
{
	ft_printf("%s", msg);
	free_map(map, ret);
}

void	free_map(char **map, int ret)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(ret);
}

void	killmlx(t_mlx *root, int ret)
{
	mlx_destroy_image(root->mlx, root->frame.img);
	mlx_destroy_window(root->mlx, root->window);
	mlx_destroy_display(root->mlx);
	free(root->mlx);
	free_map(root->player->map, ret);
}


void	ft_putmat(char **mat)
{
	int	i;
	int	j;

	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			write(1, &mat[i][j], 1);
			j++;
		}
		i++;
	}
}
