/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/02/07 11:49:42 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3D.h"

int		main(int argc, char **argv)
{
	t_env   e;

	if (argc != 2)
	{
		ft_putstr("usage : ./fdf [valid_filename.fdf]\n");
		exit(EXIT_SUCCESS);
	}
	if (ft_checks(argv) == -1)
	{
		ft_putstr("incorrect map\n");
		exit(EXIT_SUCCESS);
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	e.nb_line = ft_count_line(argv[1]);
	e.nb_col = ft_count_column(argv[1]);
	ft_parse_map(&e, argv);
	ft_load_map(&e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
