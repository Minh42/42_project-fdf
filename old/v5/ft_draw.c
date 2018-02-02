/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:55:51 by mpham             #+#    #+#             */
/*   Updated: 2018/02/01 19:12:52 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void		ft_draw_horizontal(t_env *e)
{
	int 	i;
	int 	j;
	t_coord	coord;
    i =8;
    printf("sizeof = %lu\n", sizeof(float[4][i]));
	
    i = 0;
    while (i < e->map_buffer->len)
	{
        j = 0;
		while (j < (e->map_buffer->lines[i]->len - 1))
		{
            coord.x1 = e->map_buffer->lines[i]->points[j]->x;
            coord.y1 = e->map_buffer->lines[i]->points[j]->y;
            coord.x2 = e->map_buffer->lines[i]->points[j + 1]->x;
            coord.y2 = e->map_buffer->lines[i]->points[j + 1]->y;
            ft_putnbr(coord.x1);
            ft_putchar('A');
            ft_putnbr(coord.y1);
            if (j + 1 != e->map_buffer->lines[i]->len)
            	ft_bresenham(e, coord.x1, coord.y1, coord.x2, coord.y2);
            else
                break;
			j++;
		}
		i++;
    }
}

void		ft_draw_vertical(t_env *e)
{
	int 	i;
	int 	j;
	t_coord	coord;

	i = 0;
    j = 0;

    while (j < (e->map_buffer->lines[i]->len))
    {
		i = 0;
        while (i < e->map_buffer->len - 1)
        {
            coord.x1 = e->map_buffer->lines[i]->points[j]->x;
            coord.y1 = e->map_buffer->lines[i]->points[j]->y;
            coord.x2 = e->map_buffer->lines[i + 1]->points[j]->x;
            coord.y2 = e->map_buffer->lines[i + 1]->points[j]->y;
            if (i + 1 != e->map_buffer->len)
            	ft_bresenham(e, coord.x1, coord.y1, coord.x2, coord.y2);
            else
                break;
            i++;
        }
        j++;
    }
}
