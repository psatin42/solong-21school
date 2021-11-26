#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# define P 30

typedef struct s_dekart {
	int	x;
	int	y;
	int	is_touched;
}				t_dekart;

typedef struct s_data {
	void	*img;
	int		img_width;
	int		img_height;
	char	*data;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	int			x;
	int			y;
	int			collect;
	int			player;
	int			exit;
	t_dekart	*c_collect;
	t_dekart	c_player;
	t_dekart	*c_exit;
	int			**map;
}				t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
	t_data	*player;
	t_data	*wall;
	t_data	*collect;
	t_data	*grass;
	t_data	*exit;
	t_map	*map;
	int		up;
	int		down;
	int		left;
	int		right;
	int		moves;
}				t_vars;

/* If program have mistake or need to delete smth / in error_delete.c*/
void			ft_end(char *msg, int errnum);
void			ft_delete(t_vars *vars, char *msg, int errnum);
int				ft_close(t_vars *vars);

/* Functions for free different structures / in free.c*/
void			ft_free_img(void *mlx, t_data *img);
void			ft_free(void *temp);
void			ft_free_dekart(t_vars *vars);
void			ft_free_map(t_vars *vars);

/* For start, load textures and image/ in init.c*/
t_vars			*ft_init_vars(char *file);
void			ft_init_map(t_vars *vars);
void			ft_init_minilbx(t_vars *vars);
void			ft_init_images(t_vars *vars);
void			ft_init_img(t_data *img);

/* Check file and create map/ in map.c*/
void			ft_check_file(t_vars *vars, char *file);
void			ft_read_file(t_vars *vars, char **map, int fd);
void			ft_strjoin_map(t_vars *vars, char **map, char *buf, int fd);
void			ft_read_map(t_vars *vars, char *map);
void			ft_init_dekart(t_dekart *coord);

/* Check map / in map_check.c*/
void			ft_get_map_height(t_vars *vars, char *map);
void			ft_get_map_width(t_vars *vars, char *map);
void			ft_check_border(t_vars *vars, char *map);
void			ft_check_valid(t_vars *vars, char *map);

/* Parse map and save coordinates of collectibles / in map_parse.c */
void			ft_map_parse(t_vars *vars, char *map);
void			ft_write_coord_exit(t_vars *vars, char *map, int i, int *exit);
void			ft_write_coordinate(t_vars *vars, char *map, int i, int *coll);
int				**ft_init_map_2d(t_vars *vars, char *map);
void			ft_clean_map(t_vars *vars, char *map, int y);

/* My mlx functions for drawing pixel by pixel / in mlx_pixels.c */
unsigned int	my_mlx_get_pixel(t_data *img, int x, int y);
void			my_mlx_pixel_put(t_data *img, int x, int y, int color);
unsigned int	create_trgb(int t, int r, int g, int b);

/* Transfer image to window (get picture) / in get_picture.c */
t_data			*ft_load_image(t_vars *vars, char *file);
void			ft_print_map(t_vars *vars);
void			ft_print_details(t_vars *vars, int x, int y);
void			ft_print_img(t_vars *vars, t_data *img, int x, int y);

/* Collectibles - is it collectible/exit or is it touched / in collect.c */
int				ft_is_it_exit(t_vars *vars, int x, int y);
int				ft_is_it_collect(t_vars *vars, int x, int y);
void			ft_touch (t_vars *vars, int x, int y);
int				ft_all_touched(t_vars *vars);

/* Hools and loop / in hooks.c */
int				ft_key_hook(int key, t_vars *vars);
int				ft_key_release(int key, t_vars *vars);
void			ft_display_moves(t_vars *vars, int x, int y);
void			ft_update_map(t_vars *vars);

/* Player moves / in move.c */
void			ft_move_up(t_vars *vars, int x, int y);
void			ft_move_down(t_vars *vars, int x, int y);
void			ft_move_left(t_vars *vars, int x, int y);
void			ft_move_right(t_vars *vars, int x, int y);

#endif 