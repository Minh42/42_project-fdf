/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:55:51 by mpham             #+#    #+#             */
/*   Updated: 2018/01/26 09:37:41 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void		ft_draw_horizontal(void *mlx, void *win, t_env *e)
{
	int 	i;
	int 	j;
	t_coord	coord;
	
    i = 0;
    while (i < e->map->len)
	{
        j = 0;
		while (j < (e->map->lines[i]->len - 1))
		{
            coord.x1 = e->map->lines[i]->points[j]->x;
            coord.y1 = e->map->lines[i]->points[j]->y;
            coord.x2 = e->map->lines[i]->points[j + 1]->x;
            coord.y2 = e->map->lines[i]->points[j + 1]->y;
            if (j + 1 != e->map->lines[i]->len)
            	ft_bresenham(mlx, win, coord.x1, coord.y1, coord.x2, coord.y2);
            else
                break;
			j++;
		}
		i++;
    }
}

void		ft_draw_vertical(void *mlx, void *win, t_env *e)
{
	int 	i;
	int 	j;
	t_coord	coord;

	i = 0;
    j = 0;

    while (j < (e->map->lines[i]->len))
    {
		i = 0;
        while (i < e->map->len - 1)
        {
            coord.x1 = e->map->lines[i]->points[j]->x;
            coord.y1 = e->map->lines[i]->points[j]->y;
            coord.x2 = e->map->lines[i + 1]->points[j]->x;
            coord.y2 = e->map->lines[i + 1]->points[j]->y;
            if (i + 1 != e->map->len)
            	ft_bresenham(mlx, win, coord.x1, coord.y1, coord.x2, coord.y2);
            else
                break;
            i++;
        }
        j++;
    }
}
