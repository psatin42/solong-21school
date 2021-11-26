#include "../includes/so_long.h"

void	ft_free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map->y)
		free(vars->map->map[i++]);
	free(vars->map->map);
}

void	ft_free_dekart(t_vars *vars)
{
	if (vars->map->c_collect)
		free(vars->map->c_collect);
	if (vars->map->c_exit)
		free(vars->map->c_exit);
	vars->map->c_collect = NULL;
	vars->map->c_exit = NULL;
}

void	ft_free(void *temp)
{
	free(temp);
	temp = NULL;
}

void	ft_free_img(void *mlx, t_data *img)
{
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	ft_free(img);
}
