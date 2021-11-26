#include "../includes/so_long.h"

int	ft_isitber(char *name)
{
	size_t	length;

	length = ft_strlen(name);
	if (!name || length <= 4)
		return (0);
	if (ft_strncmp(name + length - 4, ".ber", 4))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		ft_end("Invalid number of arguments", 0);
	if (!ft_isitber(argv[1]))
		ft_end("Invalid format of map. Please try *.ber", 0);
	vars = ft_init_vars(argv[1]);
	ft_print_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, ft_key_hook, vars);
	mlx_hook(vars->win, 3, 1L << 1, ft_key_release, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_close, vars);
	mlx_loop(vars->mlx);
	return (0);
}
