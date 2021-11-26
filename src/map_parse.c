#include "../includes/so_long.h"

void	ft_clean_map(t_vars *vars, char *map, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(vars->map->map[i]);
		i++;
	}
	free(vars->map->map);
	vars->map->map = 0;
	free(map);
	ft_delete(vars, "Problem with malloc - ft_map_parse", 0);
}

int	**ft_init_map_2d(t_vars *vars, char *map)
{
	int	**map2D;
	int	y;

	map2D = (int **)malloc(sizeof(int *) * vars->map->y);
	y = 0;
	if (!map2D)
	{
		free(map);
		ft_delete(vars, "Problem with malloc ft_map_parse", 0);
	}
	while (y < vars->map->y)
	{
		map2D[y] = (int *)malloc(sizeof(int) * vars->map->x);
		if (!map2D[y])
			ft_clean_map(vars, map, y);
		y++;
	}
	return (map2D);
}

void	ft_write_coordinate(t_vars *vars, char *map, int i, int *coll)
{
	if (map[i] == 'C')
	{
		vars->map->c_collect[*coll].x = i % (vars->map->x + 1);
		vars->map->c_collect[*coll].y = i / (vars->map->x + 1);
		vars->map->c_collect[*coll].is_touched = 0;
		map[i] = '0';
		(*coll)++;
	}
	else if (map[i] == 'P')
	{
		vars->map->c_player.x = i % (vars->map->x + 1);
		vars->map->c_player.y = i / (vars->map->x + 1);
		map[i] = '0';
	}
}

void	ft_write_coord_exit(t_vars *vars, char *map, int i, int *exit)
{
	if (map[i] == 'E')
	{
		vars->map->c_exit[*exit].x = i % (vars->map->x + 1);
		vars->map->c_exit[*exit].y = i / (vars->map->x + 1);
		vars->map->c_exit[*exit].is_touched = 0;
		map[i] = '0';
		(*exit)++;
	}
}

void	ft_map_parse(t_vars *vars, char *map)
{
	int	x;
	int	y;
	int	i;
	int	coll;
	int	exit;

	coll = 0;
	i = 0;
	y = 0;
	exit = 0;
	vars->map->map = ft_init_map_2d(vars, map);
	while (y < vars->map->y)
	{
		x = 0;
		while (x < vars->map->x)
		{
			if (map[i] == 'P' || map[i] == 'C')
				ft_write_coordinate(vars, map, i, &coll);
			else if (map[i] == 'E')
				ft_write_coord_exit(vars, map, i, &exit);
			vars->map->map[y][x++] = map[i++] - '0';
		}
		i++;
		y++;
	}
}
