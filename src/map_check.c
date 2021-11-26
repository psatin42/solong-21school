#include "../includes/so_long.h"

void	ft_get_map_width(t_vars *vars, char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		vars->map->x++;
		i++;
	}
	if (!vars->map->x || !map[i])
	{
		free(map);
		ft_delete(vars, "Invalid map: 1 or less strings", 1);
	}
}

void	ft_get_map_height(t_vars *vars, char *map)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = (int)ft_strlen(map);
	while (i < size && map[i] != '\0')
	{
		j = 0;
		while (map[i + j] != '\0' && map[i + j] != '\n')
			j++;
		if (j != vars->map->x)
		{
			free(map);
			ft_delete(vars, "Invalid map: uneven width", 1);
		}
		i += j + 1;
		vars->map->y++;
	}
}

void	ft_check_border(t_vars *vars, char *map)
{
	int	i;
	int	x;

	i = 0;
	x = vars->map->x;
	while (map[i])
	{
		if ((i % (x + 1) == 0 || i % (x + 1) == x - 1 || i < x)
			&& map[i] != '1')
		{
			free(map);
			ft_delete(vars, "Invalid map: no walls", 1);
		}
		i++;
	}
	while (--i > ((x + 1) * vars->map->y - (x + 1)))
	{
		if (map[i] != '1')
		{
			free(map);
			ft_delete(vars, "Invalid map: no walls", 1);
		}
	}
}

void	ft_check_valid(t_vars *vars, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			vars->map->collect++;
		else if (map[i] == 'E')
			vars->map->exit++;
		else if (map[i] == 'P')
			vars->map->player++;
		else if (map[i] != '0' && map[i] != '1' && map[i] != '\n')
		{
			free(map);
			ft_delete(vars, "Invalid map: wrong content", 1);
		}
		i++;
	}
	if (vars->map->collect < 1 || vars->map->player != 1
		|| vars->map->exit < 1)
	{
		free(map);
		ft_delete(vars, "Invalid map: wrong configuration", 1);
	}
}
