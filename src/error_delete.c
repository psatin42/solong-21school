#include "../includes/so_long.h"

int	ft_close(t_vars *vars)
{
	ft_delete(vars, "", 3);
	return (1);
}

void	ft_end(char *msg, int errnum)
{
	if (errnum == 3)
		exit(0);
	if (msg || errnum)
		ft_putendl_fd("Error", 2);
	if (msg)
		ft_putstr_fd(msg, 2);
	exit (0);
}

void	ft_delete(t_vars *vars, char *msg, int errnum)
{
	if (vars)
	{
		if (vars->img)
			ft_free_img(vars->mlx, vars->img);
		if (vars->player)
			ft_free_img(vars->mlx, vars->player);
		if (vars->collect)
			ft_free_img(vars->mlx, vars->collect);
		if (vars->exit)
			ft_free_img(vars->mlx, vars->exit);
		if (vars->grass)
			ft_free_img(vars->mlx, vars->grass);
		if (vars->wall)
			ft_free_img(vars->mlx, vars->wall);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		if (vars->map->map && errnum != 1)
			ft_free_map(vars);
		ft_free_dekart(vars);
		if (vars->map && errnum != 1)
			ft_free(vars->map);
		ft_free(vars);
	}
	ft_end(msg, errnum);
}
