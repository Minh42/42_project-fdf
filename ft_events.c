/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:39:13 by mpham             #+#    #+#             */
/*   Updated: 2018/02/03 16:03:44 by minh             ###   ########.fr       */
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
	ft_reset_map(e);
}
