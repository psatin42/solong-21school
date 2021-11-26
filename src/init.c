#include "../includes/so_long.h"

void	ft_init_img(t_data *img)
{
	img->bpp = 0;
	img->endian = 0;
	img->line_length = 0;
	img->img_height = 0;
	img->img_width = 0;
	img->data = NULL;
	img->img = NULL;
}

void	ft_init_map(t_vars *vars)
{
	vars->map = (t_map *)malloc(sizeof(t_map));
	if (!vars->map)
		ft_delete(vars, "Problem with initiation(map). Malloc return 0", 0);
	vars->map->x = 0;
	vars->map->y = 0;
	vars->map->collect = 0;
	vars->map->exit = 0;
	vars->map->player = 0;
	vars->map->c_collect = 0;
	vars->map->c_exit = 0;
}

void	ft_init_images(t_vars *vars)
{
	vars->player = ft_load_image(vars, "./img/player.xpm");
	vars->exit = ft_load_image(vars, "./img/exit.xpm");
	vars->collect = ft_load_image(vars, "./img/collect.xpm");
	vars->wall = ft_load_image(vars, "./img/wall.xpm");
	vars->grass = ft_load_image(vars, "./img/grass.xpm");
	if (!vars->player->img || !vars->exit->img || !vars->collect->img
		|| !vars->wall->img || !vars->grass->img)
		ft_delete(vars, "problem with mlx_xpm_to_image", 0);
}

void	ft_init_minilbx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		ft_delete(vars, "mlx_init problem", 0);
	vars->win = mlx_new_window(vars->mlx, vars->map->x * P, vars->map->y * P,
			"Let's play a little game");
	if (!vars->win)
		ft_delete(vars, "can't open new window", 0);
	vars->img = (t_data *)malloc(sizeof(t_data));
	if (!vars->img)
		ft_delete(vars, "can't make an image - malloc", 0);
	ft_init_img(vars->img);
	vars->img->img = mlx_new_image(vars->mlx, vars->map->x * P,
			vars->map->y * P);
	if (!vars->img->img)
		ft_delete(vars, "can't make an image", 0);
	vars->img->data = mlx_get_data_addr(vars->img->img, &vars->img->bpp,
			&vars->img->line_length, &vars->img->endian);
}

t_vars	*ft_init_vars(char *file)
{
	t_vars	*result;

	result = (t_vars *)malloc(sizeof(t_vars));
	if (!result)
		ft_delete(result, "Problem with initiation(vars). Malloc return 0", 0);
	result->img = NULL;
	result->collect = NULL;
	result->grass = NULL;
	result->wall = NULL;
	result->player = NULL;
	result->exit = NULL;
	result->win = 0;
	result->up = 0;
	result->down = 0;
	result->left = 0;
	result->right = 0;
	result->moves = 0;
	ft_init_map(result);
	ft_check_file(result, file);
	ft_init_minilbx(result);
	ft_init_images(result);
	return (result);
}
