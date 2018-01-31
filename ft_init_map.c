/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:49:49 by mpham             #+#    #+#             */
/*   Updated: 2018/01/31 11:51:19 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include "math3D.h"

void    ft_fill_pixel(t_env *e, int x, int y, int color)
{
    //int new_color;

    //new_color = mlx_get_color_value(e->mlx, color);
 	((int*)e->img.data)[(y * WIN_WIDTH) + x] = color;

    // mlx_put_image_to_window(e.mlx, e.win, e.img.img_ptr, 0, 0);
}

void    ft_init_img(t_env *e)
{
    e->img.img_ptr = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
    e->img.data = (int *)mlx_get_data_addr(e->img.img_ptr, &e->img.bpp, &e->img.sizeline, &e->img.endian);
}

void    ft_init_map(t_env *e)
{
    ft_init_img(e);
    ft_set_coord(e);
    ft_draw_horizontal(e);
    ft_draw_vertical(e);  
    mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}

void    ft_set_coord(t_env *e)
{
    int     i;
	int     j;
    int     x;
    int     y;
    int     z;
    int     w;
    // mat4_t  projection;
    // mat4_t  modelview;
    mat4_t  translation;
    mat4_t  rotationx;
    mat4_t  rotationz;
    vec4_t  vecteur;
    vec3_t  coord;

    coord = vec3((WIN_WIDTH - (18 * TILE_WIDTH)) / 2, (WIN_HEIGHT - (10 * TILE_HEIGHT)) / 2, 0);
	translation = m4_translation(coord);
    rotationx = m4_rotationx(45 * PI / 180);
    rotationz = m4_rotationz(4 * PI / 180);
    i = 0;
    while (i < e->map->len)
	{
        j = 0;
		while (j < (e->map->lines[i]->len))
		{
            x = e->map->lines[i]->points[j]->x;
            y = e->map->lines[i]->points[j]->y;
            z = e->map->lines[i]->points[j]->z;
            w = e->map->lines[i]->points[j]->w;
            vecteur = vec4(x, y, z, w);
            vecteur = m4_mult_pos(rotationx, vecteur);
            vecteur = m4_mult_pos(rotationz, vecteur);
            vecteur = m4_mult_pos(translation, vecteur);
            e->map->lines[i]->points[j]->x = vecteur.x;
            e->map->lines[i]->points[j]->y = vecteur.y;
            e->map->lines[i]->points[j]->z = vecteur.z;
            e->map->lines[i]->points[j]->w = vecteur.w;
			j++;
		}
		i++;
    }
    // modelview = m4_look_at(vec3(1, 1, 1), vec3(0, 0, 0), vec3(0, 1, 0));
    // projection = m4_perspective(70, TILE_WIDTH/TILE_HEIGHT, 1, 100);
}