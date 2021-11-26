#include "../includes/so_long.h"

void	ft_move_up(t_vars *vars, int x, int y)
{
	if (vars->map->map[y - 1][x] != 1)
		vars->map->c_player.y -= 1;
}

void	ft_move_down(t_vars *vars, int x, int y)
{
	if (vars->map->map[y + 1][x] != 1)
		vars->map->c_player.y += 1;
}

void	ft_move_left(t_vars *vars, int x, int y)
{
	if (vars->map->map[y][x - 1] != 1)
		vars->map->c_player.x -= 1;
}

void	ft_move_right(t_vars *vars, int x, int y)
{
	if (vars->map->map[y][x + 1] != 1)
		vars->map->c_player.x += 1;
}
