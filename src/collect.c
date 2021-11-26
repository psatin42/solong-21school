#include "../includes/so_long.h"

int	ft_is_it_exit(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i < vars->map->exit)
	{
		if (vars->map->c_exit[i].x == x && vars->map->c_exit[i].y == y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_it_collect(t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i < vars->map->collect)
	{
		if (vars->map->c_collect[i].x == x && vars->map->c_collect[i].y == y)
			return (1);
		i++;
	}
	return (0);
}

void	ft_touch (t_vars *vars, int x, int y)
{
	int	i;

	i = 0;
	while (i < vars->map->collect)
	{
		if (vars->map->c_collect[i].x == x && vars->map->c_collect[i].y == y)
		{
			vars->map->c_collect[i].is_touched = 1;
			return ;
		}
		i++;
	}
}

int	ft_all_touched(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map->collect)
	{
		if (!vars->map->c_collect[i].is_touched)
			return (0);
		else
			i++;
	}
	return (1);
}
