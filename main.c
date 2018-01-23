/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/01/23 21:03:49 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3D.h"

/*
void		draw_vertical(void *mlx, void *win, t_map *map)
{

	
}
*/

void        draw_form(void *mlx, void *win, t_map *map)
{
    int         i;
	int         j;
	int 		x;
	int 		y;
	int			z;
	int			w;
    vec3_t     	vecteur;
    vec4_t     	vecteur_pos;
    // vec4_t     	matrice;
	mat4_t     	translation;
	// mat4_t		rotationz;
	// mat4_t		rotationy;
	vec4_t		resultat;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	z = 0;
	w = 0;
    vecteur = vec3((WIN_WIDTH - (19 * TILE_WIDTH)) / 2, (WIN_HEIGHT - (11 * TILE_HEIGHT)) / 2, 0);
	translation = m4_translation(vecteur);
	// rotationz = m4_rotationz(330 * 3.14 / 180);
	// rotationy = m4_rotationy(45 * 3.14 / 180);
    while (i < map->len)
	{
        j = 0;
		while (j < (map->lines[i]->len))
		{
            x = map->lines[i]->points[j]->x;
            y = map->lines[i]->points[j]->y;
            z = map->lines[i]->points[j]->z;
			w = map->lines[i]->points[j]->w;
			vecteur_pos = vec4(x, y, z, w);
			resultat = m4_mult_pos(translation, vecteur_pos);
        	mlx_pixel_put(mlx, win, resultat.x, resultat.y, 0x0000FFFF);
			j++;
		}
		i++;
	}
}

int     expose_hook(t_env *e)
{
	draw_form(e->mlx, e->win, e->map);
	return (0);
}

// int     mouse_hook(int button, int x, int y, t_env *e)
// {
//     printf("mouse: %d (%d:%d)\n", button, x, y);
//     return (0);
// }

// int     key_hook(int keycode, t_env *e)
// {
//     printf("key event %d\n", keycode);
//     if (keycode == 53) // exit
//         exit(0);
//     if (keycode == 49) // reset

//     if (keycode == 126) // up
//     if (keycode == 125) // down
//     if (keycode == 124) // right
//     if (keycode == 123) // left

//     return (0);
// }

int		main(int argc, char **argv)
{
	t_env   e;
	t_map	*map;

	if (argc != 2)
		ft_putstr("too many or too few arguments\n");
	map = ft_parse_map(argv);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	e.map = map;
	mlx_expose_hook(e.win, expose_hook, &e);
	// mlx_key_hook(e.win, key_hook, &e);
	// mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
