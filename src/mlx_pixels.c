#include "../includes/so_long.h"

unsigned int	my_mlx_get_pixel(t_data *img, int x, int y)
{
	char			*dst;
	unsigned int	colour;

	dst = img->data + (y * img->line_length + x * (img->bpp / 8));
	colour = *(unsigned int *)dst;
	return (colour);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
