/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/01/26 15:57:57 by mpham            ###   ########.fr       */
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
    if (keycode == 53) // exit
        exit(0);
    if (keycode == 51) // clear
		mlx_clear_window(e->mlx, e->win);
    if (keycode == 49) // clear
		ft_init_map(e);


    // if (keycode == 126) // up
		

    // if (keycode == 125) // down
    // if (keycode == 124) // right
    // if (keycode == 123) // left

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
	e.img.img_ptr = mlx_new_image(e.mlx, TILE_WIDTH, TILE_HEIGHT);
	ft_init_map(&e);

	// mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
