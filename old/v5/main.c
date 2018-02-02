/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/02/01 17:46:09 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3D.h"

int     mouse_hook(int button, int x, int y, t_env *e)
{
    printf("mouse: %d (%d:%d)\n", button, x, y);
	if (button == SCROLL_UP) // scroll up
		e->zoomFactor -= 10;
	if (button == SCROLL_DOWN) // scroll down
		e->zoomFactor += 10;
    return (0);
}

int     key_hook(int keycode, t_env *e)
{
    printf("key event %d\n", keycode);
    if (keycode == EXIT) // exit
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		exit(EXIT_SUCCESS);
	}
    if (keycode == CLEAR) // clear

    // if (keycode == RESET) // reset
	// {
	// 	mlx_clear_window(e->mlx, e->win);		
	// 	ft_init_map(e);
	// }
	if (keycode == MOVE_UP || keycode == MOVE_DOWN || keycode == MOVE_RIGHT ||
	keycode == MOVE_LEFT)
		move_hook(keycode, e);
	if (keycode == ROTATE_UP || keycode == ROTATE_DOWN || 
	keycode == ROTATE_RIGHT || keycode == ROTATE_LEFT)
		rotate_hook(keycode, e);
	ft_redraw(e);
    return (0);
}

int		move_hook(int keycode, t_env *e)
{
    if (keycode == MOVE_UP) // up
		e->offset_y -= 100;
    if (keycode == MOVE_DOWN) // down
		e->offset_y += 100;
    if (keycode == MOVE_RIGHT) // right
		e->offset_x += 100;
    if (keycode == MOVE_LEFT) // left
		e->offset_x -= 100;
	return (0);
}

int		rotate_hook(int keycode, t_env *e)
{
    if (keycode == ROTATE_UP) // up
		e->angle -= 1;
    if (keycode == ROTATE_DOWN) // down
		e->angle += 1;
    // if (keycode == ROTATE_RIGHT) // right
	// 	e->angle += 1;
    // if (keycode == ROTATE_LEFT) // left
	// 	e->angle -= 1;
	return (0);
}

int		main(int argc, char **argv)
{
	t_env   e;

	if (argc != 2)
		ft_putstr("too many or too few arguments\n");
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	ft_parse_map(&e, argv);
	ft_init_img(&e);
	ft_init_map(&e);
	// mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
