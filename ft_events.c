/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:39:13 by mpham             #+#    #+#             */
/*   Updated: 2018/02/03 18:34:14 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"


void    ft_redraw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_load_map(e);
}

void    ft_reset(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->angle_x = 0;
	e->angle_y = 0;
	e->angle_z = 0;
	e->offset_x = 0;
	e->offset_y = 0;
	e->scale_x = 0;
	e->scale_y = 0;
	ft_reset_map(e);
}
