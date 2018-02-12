/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:49:49 by mpham             #+#    #+#             */
/*   Updated: 2018/02/12 19:10:37 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3d.h"

void	ft_init_img(t_env *e)
{
	e->img.img_ptr = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->img.data = (int *)mlx_get_data_addr(e->img.img_ptr, &e->img.bpp,
	&e->img.sizeline, &e->img.endian);
}

void	ft_print_dashboard(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 25, 15, 16777215, "Quit = ESC");
	mlx_string_put(e->mlx, e->win, 25, 35, 16777215, "Move = < > ^ v");
	mlx_string_put(e->mlx, e->win, 25, 55, 16777215, "Zoom = + OR -");
	mlx_string_put(e->mlx, e->win, 25, 75, 16777215,
	"Alt = Page up OR Page down");
	mlx_string_put(e->mlx, e->win, 25, 95, 16777215, "Rx = W OR S");
	mlx_string_put(e->mlx, e->win, 25, 115, 16777215, "Ry = A OR D");
	mlx_string_put(e->mlx, e->win, 25, 135, 16777215, "Rz = Q OR E");
	mlx_string_put(e->mlx, e->win, 25, 155, 16777215, "Reset = SPACE");
}

void	ft_load_map(t_env *e)
{
	t_matrice	m;

	ft_init_img(e);
	if (e->zoom < 0)
		e->zoom += 1;
	m.scale = m4_scaling(vec3((1 + e->zoom), (1 + e->zoom),
	(1 + e->scale_z)));
	if (e->angle_x >= 360.0)
		e->angle_x -= 360.0;
	if (e->angle_y >= 360.0)
		e->angle_y -= 360.0;
	if (e->angle_z >= 360.0)
		e->angle_z -= 360.0;
	m.rotationx = m4_rotationx((0.0 + e->angle_x) * PI / 180.0);
	m.rotationy = m4_rotationy((0.0 + e->angle_y) * PI / 180.0);
	m.rotationz = m4_rotationz((0.0 + e->angle_z) * PI / 180.0);
	m.translate = m4_translation(vec3((WIN_WIDTH - (e->nb_col * TILE_WIDTH)) / 2
	, (WIN_HEIGHT - (e->nb_line * TILE_HEIGHT)) / 2, 0));
	m.rotation = mult_mat4(m.rotationz, mult_mat4(m.rotationy, m.rotationx));
	ft_set_coord(e, mult_mat4(m.translate, mult_mat4(m.rotation, m.scale)));
	ft_draw_horizontal(e);
	ft_draw_vertical(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	ft_print_dashboard(e);
}

void	ft_reset_map(t_env *e)
{
	t_matrice	m;

	ft_init_img(e);
	e->scale_z = 0;
	m.scale = m4_scaling(vec3(1, 1, 1));
	m.rotationx = m4_rotationx(0.0 * PI / 180.0);
	m.rotationy = m4_rotationy(0.0 * PI / 180.0);
	m.rotationz = m4_rotationz(0.0 * PI / 180.0);
	m.translate = m4_translation(vec3((WIN_WIDTH - (e->nb_col * TILE_WIDTH)) / 2
	, (WIN_HEIGHT - (e->nb_line * TILE_HEIGHT)) / 2, 0));
	m.rotation = mult_mat4(m.rotationz, mult_mat4(m.rotationy, m.rotationx));
	ft_set_coord(e, mult_mat4(m.translate, mult_mat4(m.rotation, m.scale)));
	ft_draw_horizontal(e);
	ft_draw_vertical(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}

void	ft_set_coord(t_env *e, t_mat4 matrice)
{
	t_point	coord;
	t_vec4	vecteur;

	coord.i = 0;
	while (coord.i < e->nb_line)
	{
		coord.j = 0;
		while (coord.j < e->nb_col)
		{
			coord.x = e->map[coord.i][coord.j][0];
			coord.y = e->map[coord.i][coord.j][1];
			coord.z = e->map[coord.i][coord.j][2];
			coord.w = e->map[coord.i][coord.j][3];
			coord.color = e->map[coord.i][coord.j][4];
			vecteur = vec4(coord.x, coord.y, coord.z, coord.w);
			vecteur = m4_mult_pos(matrice, vecteur);
			e->map_buffer[coord.i][coord.j][0] = vecteur.x;
			e->map_buffer[coord.i][coord.j][1] = vecteur.y;
			e->map_buffer[coord.i][coord.j][2] = vecteur.z;
			e->map_buffer[coord.i][coord.j][3] = vecteur.w;
			e->map_buffer[coord.i][coord.j][4] = coord.color;
			coord.j++;
		}
		coord.i++;
	}
}
