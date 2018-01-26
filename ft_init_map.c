/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:49:49 by mpham             #+#    #+#             */
/*   Updated: 2018/01/26 16:35:51 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include "math3D.h"

void    ft_fill_pixel(t_env *e)
{
    e->img.data = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp, &e->img.sizeline, &e->img.endian);
    ft_putnbr(&e->img.bpp);

    // mlx_get_color_value(void *mlx_ptr, int color)
    // mlx_put_image_to_window(e.mlx, e.win, e.img.img_ptr, 0, 0);
}

void    ft_init_map(t_env *e)
{
    int     i;
	int     j;
    int     x;
    int     y;
    int     z;
    int     w;
    t_env   *tmp;
    // mat4_t  projection;
    // mat4_t  modelview;
    mat4_t  translation;
    mat4_t  rotationx;
    mat4_t  rotationz;
    vec4_t  vecteur;
    vec3_t  coord;

    tmp = e;
    coord = vec3((WIN_WIDTH - (18 * TILE_WIDTH)) / 2, (WIN_HEIGHT - (10 * TILE_HEIGHT)) / 2, 0);
	translation = m4_translation(coord);
    rotationx = m4_rotationx(45 * PI / 180);
    rotationz = m4_rotationz(350 * PI / 180);
    i = 0;
    while (i < tmp->map->len)
	{
        j = 0;
		while (j < (tmp->map->lines[i]->len))
		{
            x = tmp->map->lines[i]->points[j]->x;
            y = tmp->map->lines[i]->points[j]->y;
            z = tmp->map->lines[i]->points[j]->z;
            w = tmp->map->lines[i]->points[j]->w;
            vecteur = vec4(x, y, z, w);
            vecteur = m4_mult_pos(rotationx, vecteur);
            vecteur = m4_mult_pos(rotationz, vecteur);
            vecteur = m4_mult_pos(translation, vecteur);
            tmp->map->lines[i]->points[j]->x = vecteur.x;
            tmp->map->lines[i]->points[j]->y = vecteur.y;
            tmp->map->lines[i]->points[j]->z = vecteur.z;
            tmp->map->lines[i]->points[j]->w = vecteur.w;
			j++;
		}
		i++;
    }
    ft_draw_horizontal(e->mlx, e->win, tmp);
    ft_draw_vertical(e->mlx, e->win, tmp);  


    // modelview = m4_look_at(vec3(1, 1, 1), vec3(0, 0, 0), vec3(0, 1, 0));
    // projection = m4_perspective(70, TILE_WIDTH/TILE_HEIGHT, 1, 100);



}