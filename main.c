/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/02/13 11:30:44 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3d.h"

char	*ft_skip(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != ',')
	{
		i++;
	}
	if (str[i] == ',')
		i++;
	if (str[i] == '0')
		i++;
	if (str[i] == 'x')
		i++;
	return (&str[i]);
}

void	ft_redraw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_load_map(e);
}

void	ft_reset(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->angle_x = 0;
	e->angle_y = 0;
	e->angle_z = 0;
	e->offset_x = 0;
	e->offset_y = 0;
	e->zoom = 0;
	e->scale_z = 0;
	ft_reset_map(e);
}

void	ft_free_tab(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->nb_line)
	{
		j = 0;
		while (j < e->nb_col)
		{
			free(e->map[i][j]);
			free(e->map_buffer[i][j]);
			j++;
		}
		i++;
	}
	free(e->map);
	free(e->map_buffer);
}

int		main(int argc, char **argv)
{
	t_env	e;

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
	mlx_hook(e.win, 2, 0, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
