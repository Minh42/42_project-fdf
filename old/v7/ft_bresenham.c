/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:31:17 by mpham             #+#    #+#             */
/*   Updated: 2018/02/03 18:30:09 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_bresenham1(t_env *e, t_algo *b, int x1, int y1)
{
    int i;

    i = 0;
    while (i <= b->Dx)
    {
        ft_fill_pixel(e, x1 + e->offset_x, y1 + e->offset_y, 0x0000FFFF);
        i++;
        x1 += b->Xincr;
        b->ex -= b->dy;
        if (b->ex < 0)
        {
            y1 += b->Yincr;
            b->ex += b->dx;
        }  
    }
}

void    ft_bresenham2(t_env *e, t_algo *b, int x1, int y1)
{
    int i;

    i = 0;
    while (i <= b->Dy)
    {
        ft_fill_pixel(e, x1 + e->offset_x, y1 + e->offset_y, 0x0000FFFF);
        i++;
        y1 += b->Yincr;
        b->ey -= b->dx;
        if (b->ey < 0)
        {
            x1 += b->Xincr;
            b->ey += b->dy;
        }   
    }

}

void    ft_bresenham(t_env *e, int x1, int y1, int x2, int y2)
{
    t_algo  b;

    b.ex = ft_abs(x2 - x1);
    b.ey = ft_abs(y2 - y1);
    b.dx = 2 * b.ex;
    b.dy = 2 * b.ey;
    b.Dx = b.ex;
    b.Dy = b.ey;
    b.Xincr = 1;
    b.Yincr = 1;
    
    if (x1 > x2)
        b.Xincr = -1;
    if (y1 > y2)
        b.Yincr = -1;
    if (b.Dx > b.Dy)
        ft_bresenham1(e, &b, x1, y1);
    else
        ft_bresenham2(e, &b, x1, y1);
}
