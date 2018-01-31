/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:39:13 by mpham             #+#    #+#             */
/*   Updated: 2018/01/31 17:16:00 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"


void    ft_redraw(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img.img_ptr);
	ft_init_img(e);
	ft_draw_horizontal(e);
    ft_draw_vertical(e); 
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}