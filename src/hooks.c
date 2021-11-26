#include "../includes/so_long.h"

void	ft_display_moves(t_vars *vars, int x, int y)
{
	if (vars->map->c_player.x != x || vars->map->c_player.y != y)
	{
		vars->moves++;
		ft_putnbr_fd(vars->moves, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_update_map(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->map->c_player.x;
	y = vars->map->c_player.y;
	if (vars->up)
		ft_move_up(vars, x, y);
	else if (vars->down)
		ft_move_down(vars, x, y);
	else if (vars->left)
		ft_move_left(vars, x, y);
	else if (vars->right)
		ft_move_right(vars, x, y);
	ft_display_moves(vars, x, y);
	ft_print_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

int	ft_key_release(int key, t_vars *vars)
{
	if (key == 13)
		vars->up = 0;
	else if (key == 1)
		vars->down = 0;
	else if (key == 0)
		vars->left = 0;
	else if (key == 2)
		vars->right = 0;
	ft_update_map(vars);
	if (ft_is_it_collect(vars, vars->map->c_player.x, vars->map->c_player.y))
		ft_touch(vars, vars->map->c_player.x, vars->map->c_player.y);
	if (ft_is_it_exit(vars, vars->map->c_player.x, vars->map->c_player.y)
		&& ft_all_touched(vars))
		ft_delete(vars, "", 3);
	return (1);
}

int	ft_key_hook(int key, t_vars *vars)
{
	if (key == 13)
		vars->up = 1;
	else if (key == 1)
		vars->down = 1;
	else if (key == 0)
		vars->left = 1;
	else if (key == 2)
		vars->right = 1;
	if (key == 53 || key == 256 || key == 65307)
		ft_delete(vars, "", 3);
	ft_update_map(vars);
	if (ft_is_it_collect(vars, vars->map->c_player.x, vars->map->c_player.y))
		ft_touch(vars, vars->map->c_player.x, vars->map->c_player.y);
	if (ft_is_it_exit(vars, vars->map->c_player.x, vars->map->c_player.y)
		&& ft_all_touched(vars))
		ft_delete(vars, "", 3);
	return (1);
}
