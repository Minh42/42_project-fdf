/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:55:51 by mpham             #+#    #+#             */
/*   Updated: 2018/02/07 14:32:21 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void		ft_draw_horizontal(t_env *e)
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
            coord.x1 = e->map_buffer[i][j][0];
            coord.y1 = e->map_buffer[i][j][1];
            coord.x2 = e->map_buffer[i][j + 1][0];
            coord.y2 = e->map_buffer[i][j + 1][1];
            coord.z1 = e->map_buffer[i][j][2];  
            coord.color = e->map_buffer[i][j][4];
            if (j + 1 != e->nb_col)
            	ft_bresenham(e, coord.x1, coord.y1, coord.x2, coord.y2, coord.z1, coord.color);
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

    while (j < e->nb_col)
    {
		i = 0;
        while (i < e->nb_line - 1)
        {
            coord.x1 = e->map_buffer[i][j][0];
            coord.y1 = e->map_buffer[i][j][1];
            coord.x2 = e->map_buffer[i + 1][j][0];
            coord.y2 = e->map_buffer[i + 1][j][1];
            coord.z1 = e->map_buffer[i][j][2];            
            coord.color = e->map_buffer[i][j][4];     
            if (i + 1 != e->nb_line)
            	ft_bresenham(e, coord.x1, coord.y1, coord.x2, coord.y2, coord.z1, coord.color);
            else
                break;
            i++;
        }
        j++;
    }
}
