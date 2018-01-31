/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/01/31 12:46:05 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3D.h"

// int     expose_hook(t_env *e)
// {
// 	draw_form(e->mlx, e->win, e->map);
// 	return (0);
// }

// int     mouse_hook(int button, int x, int y, t_env *e)
// {
//     printf("mouse: %d (%d:%d)\n", button, x, y);
	

//     return (0);
// }

int     key_hook(int keycode, t_env *e)
{
    printf("key event %d\n", keycode);
    if (keycode == EXIT) // exit
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		exit(EXIT_SUCCESS);
	}
    if (keycode == CLEAR) // clear
		mlx_clear_window(e->mlx, e->win);
    // if (keycode == RESET) // reset
	// {
	// 	mlx_clear_window(e->mlx, e->win);		
	// 	ft_init_map(e);
	// }
	move_hook(keycode, e);

    return (0);
}

int		move_hook(int keycode, t_env *e)
{
    if (keycode == MOVE_UP) // up
	{
		e->offset_y -= 200;
		ft_redraw(e);
	}s
    if (keycode == MOVE_DOWN) // down
	{
		e->offset_y += 200;
		ft_redraw(e);
	}
    if (keycode == MOVE_RIGHT) // right
	{
		e->offset_x += 200;
		ft_redraw(e);
	}
    if (keycode == MOVE_LEFT) // left
	{
		e->offset_x -= 200;
		ft_redraw(e);
	}
	return (0);
}



int		main(int argc, char **argv)
{
	t_env   e;

	if (argc != 2)
		ft_putstr("too many or too few arguments\n");
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	e.map = ft_parse_map(argv);
	ft_init_map(&e);
	// mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
