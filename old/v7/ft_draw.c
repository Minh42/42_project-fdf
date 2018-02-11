/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:55:51 by mpham             #+#    #+#             */
/*   Updated: 2018/02/02 17:54:43 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void		ft_draw_horizontal(t_env *e, int nb_line, int nb_col, t_point (*map_buffer)[nb_line][nb_col])
{
	int 	i;
	int 	j;
	t_coord	coord;
	
    i = 0;
    while (i < e->nb_line)
	{
        j = 0;
		while (j < e->nb_col - 1)
		{
            coord.x1 = (*map_buffer)[i][j].x;
            coord.y1 = (*map_buffer)[i][j].y;
            coord.x2 = (*map_buffer)[i][j + 1].x;
            coord.y2 = (*map_buffer)[i][j + 1].y;
            if (j + 1 != nb_col)
            	ft_bresenham(e, coord.x1, coord.y1, coord.x2, coord.y2);
            else
                break;
			j++;
		}
		i++;
    }
}

void		ft_draw_vertical(t_env *e, int nb_line, int nb_col, t_point (*map_buffer)[nb_line][nb_col])
{
	int 	i;
	int 	j;
	t_coord	coord;

	i = 0;
    j = 0;

    while (j < nb_col)
    {
		i = 0;
        while (i < nb_line - 1)
        {
            coord.x1 = (*map_buffer)[i][j].x;
            coord.y1 = (*map_buffer)[i][j].y;
            coord.x2 = (*map_buffer)[i + 1][j].x;
            coord.y2 = (*map_buffer)[i + 1][j].y;
            if (i + 1 != nb_line)
            	ft_bresenham(e, coord.x1, coord.y1, coord.x2, coord.y2);
            else
                break;
            i++;
        }
        j++;
    }
}
