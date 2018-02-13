/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:39:13 by mpham             #+#    #+#             */
/*   Updated: 2018/02/13 11:10:42 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == EXIT)
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		ft_free_tab(e);
		exit(EXIT_SUCCESS);
	}
	if (keycode == CLEAR)
		mlx_clear_window(e->mlx, e->win);
	if (keycode == RESET)
		ft_reset(e);
	move_hook(keycode, e);
	zoom_hook(keycode, e);
	rotate_hook(keycode, e);
	color_hook(keycode, e);
	ft_redraw(e);
	return (0);
}

void	move_hook(int keycode, t_env *e)
{
	if (keycode == MOVE_UP)
		e->offset_y -= 100;
	if (keycode == MOVE_DOWN)
		e->offset_y += 100;
	if (keycode == MOVE_RIGHT)
		e->offset_x += 100;
	if (keycode == MOVE_LEFT)
		e->offset_x -= 100;
}

void	zoom_hook(int keycode, t_env *e)
{
	if (keycode == ZOOM_IN)
		e->zoom += 1;
	if (keycode == ZOOM_OUT)
		e->zoom -= 1;
	if (keycode == ZOOM_UP)
		e->scale_z += 1;
	if (keycode == ZOOM_DOWN)
		e->scale_z -= 1;
}

void	rotate_hook(int keycode, t_env *e)
{
	if (keycode == ROTATE_UP)
		e->angle_x += 10;
	if (keycode == ROTATE_DOWN)
		e->angle_x -= 10;
	if (keycode == ROTATE_RIGHT)
		e->angle_y += 10;
	if (keycode == ROTATE_LEFT)
		e->angle_y -= 10;
	if (keycode == ROTATE_Z1)
		e->angle_z += 10;
	if (keycode == ROTATE_Z2)
		e->angle_z -= 10;
}

void	color_hook(int keycode, t_env *e)
{
	if (keycode == COLOR_RED)
		e->color_r += 10;
	if (keycode == COLOR_GREEN)
		e->color_g += 10;
	if (keycode == COLOR_BLUE)
		e->color_b += 10;
}
