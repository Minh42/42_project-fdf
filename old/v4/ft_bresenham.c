/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:17 by mpham             #+#    #+#             */
/*   Updated: 2018/01/22 17:27:22 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_bresenham(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x,y;

    i = 0;
    dx = x2 - x1;
    dy = y2 - y1;
    if (dx > 0)
        incx = 1;
    else
    {
        incx = -1;
        dx = -dx;
    }      
    if (dy > 0)
        incy = 1;
    else
    {
        incy = -1;
        dy = -dy; 
    }
    x = x1;
    y = y1;
    if (dx > dy)
    {
	    mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        while (i < dx)
        {
            if(e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
            {
                e += inc2;
                x += incx;
            }
            mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
            i++; 
        }
    }
    else
    {
	    mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        while(i < dy)
        {
            if(e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else 
            {
                e += inc2;
                y += incy;
            }
 	        mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
             i++;        
        }
    }
}
