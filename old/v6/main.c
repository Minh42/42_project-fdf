/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/02/03 17:15:00 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3D.h"

// int     mouse_hook(int button, int x, int y, t_env *e)
// {
// 	printf("mouse: %d (%d:%d)\n", button, x, y);
// 	if (button == SCROLL_UP)
// 	{
// 		e->scale_x += 1;
// 		e->scale_y += 1;
// 	}
// 	if (button == SCROLL_DOWN)
// 	{
// 		e->scale_x -= 1;
// 		e->scale_y -= 1;
// 	}
//     return (0);
// 		ft_redraw(e);
// }

// int     key_hook(int keycode, t_env *e)
// {
//     printf("key event %d\n", keycode);
//     if (keycode == EXIT)
// 		{
// 			mlx_destroy_image(e->mlx, e->img.img_ptr);
// 			exit(EXIT_SUCCESS);
// 			}
//     if (keycode == CLEAR)
// 			mlx_clear_window(e->mlx, e->win);
//     if (keycode == RESET)
// 		{
// 			mlx_clear_window(e->mlx, e->win);		
// 			ft_reset(e);
// 		}
// 		if (keycode == MOVE_UP || keycode == MOVE_DOWN || keycode == MOVE_RIGHT ||
// 			keycode == MOVE_LEFT)
// 		{
// 			move_hook(keycode, e);
// 			ft_redraw(e);
// 		}
// 		if (keycode == ROTATE_UP || keycode == ROTATE_DOWN || 
// 			keycode == ROTATE_RIGHT || keycode == ROTATE_LEFT || keycode == ROTATE_Z1 
// 			|| keycode == ROTATE_Z2)
// 		{
// 			rotate_hook(keycode, e);	
// 			ft_redraw(e);
// 		}
//     return (0);
// }

// int		move_hook(int keycode, t_env *e)
// {
//     if (keycode == MOVE_UP)
// 		e->offset_y -= 100;
//     if (keycode == MOVE_DOWN)
// 		e->offset_y += 100;
//     if (keycode == MOVE_RIGHT)
// 		e->offset_x += 100;
//     if (keycode == MOVE_LEFT)
// 		e->offset_x -= 100;
// 	return (0);
// }

// int		rotate_hook(int keycode, t_env *e)
// {
//     if (keycode == ROTATE_UP)
// 			e->angle_x += 10;
//     if (keycode == ROTATE_DOWN)
// 			e->angle_x -= 10;
//     if (keycode == ROTATE_RIGHT)
// 			e->angle_y += 10;
//     if (keycode == ROTATE_LEFT)
// 			e->angle_y -= 10;
// 		if(keycode == ROTATE_Z1)
// 			e->angle_z += 10;
// 		if(keycode == ROTATE_Z2)
// 			e->angle_z -= 10;		
// 	return (0);
// }

int		main(int argc, char **argv)
{
	t_env   e;

	if (argc != 2)
		ft_putstr("too many or too few arguments\n");
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	e.nb_line = ft_count_line(argv[1]);
	e.nb_col = ft_count_column(argv[1]);
	ft_parse_map(argv, &e, e.nb_line, e.nb_col);
	// ft_load_map(&e);
	// mlx_key_hook(e.win, key_hook, &e);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	// mlx_loop(e.mlx);
	return (0);
}
