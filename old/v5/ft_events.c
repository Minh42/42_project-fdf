/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:39:13 by mpham             #+#    #+#             */
/*   Updated: 2018/02/01 19:08:05 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void    ft_redraw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_bzero(e->img.data, sizeof(int) * WIN_WIDTH * WIN_HEIGHT);
	ft_init_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}

