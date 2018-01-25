/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:49:49 by mpham             #+#    #+#             */
/*   Updated: 2018/01/25 17:46:19 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include "math3D.h"


void    ft_init_map(t_env *e)
{
    // int     i;
	// int     j;
    // int     x1;
    // int     y1;
    // int     z1;
    // int     w1;

    // int     x2;
    // int     y2;
    // int     z2;
    // int     w2;

    mat4_t  projection;
    mat4_t  modelview;
    mat4_t  translation;
    // vec4_t  vecteur;
    vec3_t  coord;

    modelview = m4_look_at(vec3(1, 1, 1), vec3(0, 0, 0), vec3(0, 1, 0));
    projection = m4_perspective(70, TILE_WIDTH/TILE_HEIGHT, 1, 100);

    coord = vec3((WIN_WIDTH - (19 * TILE_WIDTH)) / 2, (WIN_HEIGHT - (11 * TILE_HEIGHT)) / 2, 0);
	translation = m4_translation(coord);

    ft_draw_horizontal(e->mlx, e->win, e);
    ft_draw_vertical(e->mlx, e->win, e);  

    //         x1 = e->map->lines[0]->points[0]->x;
    //         y1 = e->map->lines[0]->points[0]->y;
    //         z1 = e->map->lines[0]->points[0]->z;
	// 		w1 = e->map->lines[0]->points[0]->w;

    //         x2 = e->map->lines[0]->points[1]->x;
    //         y2 = e->map->lines[0]->points[1]->y;
    //         z2 = e->map->lines[0]->points[1]->z;
	// 		w2 = e->map->lines[0]->points[1]->w;  
    // ft_bresenham(e->mlx, e->win, x1, y1, x2, y2);



}