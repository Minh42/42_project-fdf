/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:55:51 by mpham             #+#    #+#             */
/*   Updated: 2018/02/12 18:28:16 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3d.h"

void	ft_draw_horizontal(t_env *e)
{
	int		i;
	int		j;
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
				ft_bresenham(e, &coord);
			else
				break ;
			j++;
		}
		i++;
	}
}

void	ft_draw_vertical(t_env *e)
{
	int		i;
	int		j;
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
				ft_bresenham(e, &coord);
			else
				break ;
			i++;
		}
		j++;
	}
}
