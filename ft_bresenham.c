/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:17 by mpham             #+#    #+#             */
/*   Updated: 2018/02/12 15:09:19 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	ft_color_converter(t_env *e, int hexvalue)
{
	t_color rgbcolor;

	if (e->color_r > 255 || e->color_g > 255 || e->color_b > 255)
	{
		e->color_r -= 255;
		e->color_g -= 255;
		e->color_b -= 255;
	}
	rgbcolor.r = ((hexvalue >> 16) & 0xFF) + e->color_r;
	rgbcolor.g = ((hexvalue >> 8) & 0xFF) + e->color_g;
	rgbcolor.b = ((hexvalue) & 0xFF) + e->color_b;
	return (rgbcolor);
}

void	ft_fill_pixel(t_env *e, int x1, int y1, t_coord *coord)
{
	int		new_color;

	new_color = mlx_get_color_value(e->mlx, coord->color);
	if (x1 >= 0 && y1 >= 0 && x1 < WIN_WIDTH && y1 < WIN_HEIGHT)
		((int*)e->img.data)[(y1 * WIN_WIDTH) + x1] = new_color;
}

void	ft_bresenham1(t_env *e, t_algo *b, t_coord *coord)
{
	int i;

	i = 0;
	while (i <= b->dpx)
	{
		ft_fill_pixel(e, coord->x1 + e->offset_x, coord->y1 +
		e->offset_y, coord);
		i++;
		coord->x1 += b->xincr;
		b->ex -= b->dy;
		if (b->ex < 0)
		{
			coord->y1 += b->yincr;
			b->ex += b->dx;
		}
	}
}

void	ft_bresenham2(t_env *e, t_algo *b, t_coord *coord)
{
	int i;

	i = 0;
	while (i <= b->dpy)
	{
		ft_fill_pixel(e, coord->x1 + e->offset_x, coord->y1 +
		e->offset_y, coord);
		i++;
		coord->y1 += b->yincr;
		b->ey -= b->dx;
		if (b->ey < 0)
		{
			coord->x1 += b->xincr;
			b->ey += b->dy;
		}
	}
}

void	ft_bresenham(t_env *e, t_coord *coord)
{
	t_algo	b;

	b.ex = ft_abs(coord->x2 - coord->x1);
	b.ey = ft_abs(coord->y2 - coord->y1);
	b.dx = 2 * b.ex;
	b.dy = 2 * b.ey;
	b.dpx = b.ex;
	b.dpy = b.ey;
	b.xincr = 1;
	b.yincr = 1;
	if (coord->x1 > coord->x2)
		b.xincr = -1;
	if (coord->y1 > coord->y2)
		b.yincr = -1;
	if (b.dpx > b.dpy)
		ft_bresenham1(e, &b, coord);
	else
		ft_bresenham2(e, &b, coord);
}
