#include "../includes/so_long.h"

void	ft_init_dekart(t_dekart *coord)
{
	coord->x = 0;
	coord->y = 0;
	coord->is_touched = -1;
}

void	ft_read_map(t_vars *vars, char *map)
{
	ft_get_map_width(vars, map);
	ft_get_map_height(vars, map);
	ft_check_border(vars, map);
	ft_check_valid(vars, map);
	vars->map->c_collect = (t_dekart *)malloc(sizeof(t_dekart)
			* vars->map->collect);
	if (!vars->map->c_collect)
	{
		free(map);
		ft_delete(vars, "Problem with malloc - ft_read_map", 0);
	}
	ft_init_dekart(vars->map->c_collect);
	vars->map->c_exit = (t_dekart *)malloc(sizeof(t_dekart) * vars->map->exit);
	if (!vars->map->c_exit)
	{
		free(map);
		ft_delete(vars, "Problem with malloc - ft_read_map", 0);
	}
	ft_init_dekart(vars->map->c_exit);
	ft_map_parse(vars, map);
}

void	ft_strjoin_map(t_vars *vars, char **map, char *buf, int fd)
{
	char	*result;

	result = ft_strjoin(*map, buf);
	free (*map);
	*map = NULL;
	if (!result)
	{
		close(fd);
		ft_delete(vars, "Can't put map together - strjoin", 1);
	}
	else
		*map = result;
}

void	ft_read_file(t_vars *vars, char **map, int fd)
{
	int		ret;
	char	buf[2048];

	ret = -1;
	while (ret)
	{
		ret = read(fd, buf, 2047);
		if (ret == -1)
		{
			free(*map);
			close(fd);
			ft_delete(vars, "Can't read file", 1);
		}
		else
		{
			buf[ret] = '\0';
			ft_strjoin_map(vars, map, buf, fd);
		}
	}
}

void	ft_check_file(t_vars *vars, char *file)
{
	int		fd;
	char	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_delete(vars, "Can't open file", 1);
	map = ft_calloc(1, sizeof(char) + 1);
	map[1] = '\0';
	if (!map)
	{
		close(fd);
		ft_delete(vars, "Problem with map init - ft_calloc", 0);
	}
	ft_read_file(vars, &map, fd);
	ft_read_map(vars, map);
	close(fd);
	free(map);
}
