#include "../includes/so_long.h"

t_data	*ft_load_image(t_vars *vars, char *file)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	ft_init_img(data);
	if (!data)
		ft_delete(vars, "Problem with initiation(data). Malloc return 0", 0);
	data->img = mlx_xpm_file_to_image(vars->mlx, file, &(data->img_width),
			&(data->img_height));
	if (!data->img)
		return (data);
	data->data = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->endian);
	return (data);
}

void	ft_print_img(t_vars *vars, t_data *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < P)
	{
		i = 0;
		while (i < P)
		{
			color = my_mlx_get_pixel(img, i, j);
			if (color != 0xFF000000)
				my_mlx_pixel_put(vars->img, x + i,
					j + y, color);
			i++;
		}
		j++;
	}
}

void	ft_print_details(t_vars *vars, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < vars->map->collect)
		if (vars->map->c_collect[i].x == x && vars->map->c_collect[i].y == y
			&& !vars->map->c_collect[i].is_touched)
			ft_print_img(vars, vars->collect, x * P, y * P);
	while (++j < vars->map->exit)
		if (vars->map->c_exit[j].x == x && vars->map->c_exit[j].y == y)
			ft_print_img(vars, vars->exit, x * P, y * P);
	if (vars->map->c_player.x == x && vars->map->c_player.y == y)
		ft_print_img(vars, vars->player, x * P, y * P);
}

void	ft_print_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map->y)
	{
		x = 0;
		while (x < vars->map->x)
		{
			if (vars->map->map[y][x] == 1)
				ft_print_img(vars, vars->wall, x * 30, y * 30);
			else
				ft_print_img(vars, vars->grass, x * 30, y * 30);
			ft_print_details(vars, x, y);
			x++;
		}
		y++;
	}
}
