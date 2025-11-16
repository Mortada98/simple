#include "cub3d.h"

int	rgb_to_int(t_color color)
{
	return ((color.r & 0xFF) << 16)
		| ((color.g & 0xFF) << 8)
		| (color.b & 0xFF);
}

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	offset = y * img->line_len + x * (img->bpp / 8);
	dst = img->addr + offset;
	*(int *)dst = color;
}

int	get_color_from_tex(t_img *tex, int x, int y)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	offset = y * tex->line_len + x * (tex->bpp / 8);
	dst = tex->addr + offset;
	return (*(int *)dst);
}
