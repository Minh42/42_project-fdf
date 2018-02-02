/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:49:49 by mpham             #+#    #+#             */
/*   Updated: 2018/02/01 19:11:23 by mpham            ###   ########.fr       */
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
    mat4_t  modelview;
    mat4_t  modelview2;
    mat4_t  modelview3;
    // mat4_t  projection;

    // mat4_t  camera;
    vec3_t  translate;
    vec3_t  scale;
    vec3_t  rotate_x;
    vec3_t  rotate_y;
    vec3_t  rotate_z;    
    // vec3_t  eye;
    // vec3_t  center;   
    // vec3_t  up;

    scale = vec3(1, 1, 1);
    modelview = m4_scaling(scale);

    rotate_x = vec3(1, 0, 0);
    // rotate_y = vec3(0, 1, 0);
    // rotate_z = vec3(0, 0, 1);
    modelview2 = m4_rotationx(((45.0 + e->angle) * PI / 180.0));//m4_rotation(((45.0 + e->angle) * PI / 180.0), rotate_x);
  
    translate = vec3((WIN_WIDTH - (18 * TILE_WIDTH)) / 2, (WIN_HEIGHT - (10 * TILE_HEIGHT)) / 2, 0);
	modelview3 = m4_scaling(scale);//m4_translation(translate);

    ft_set_coord(e, ft_mult_mat4(modelview3, ft_mult_mat4(modelview2, modelview)));

    // projection = m4_perspective(70, WIN_WIDTH/WIN_HEIGHT, 1.0, 100.0); 

    // ft_set_coord(e, projection);
    ft_draw_horizontal(e);
    ft_draw_vertical(e); 
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}


// void    ft_change_map(t_env *e)
// {
//     // static float   angle;
//     mat4_t  modelview2;
//     vec3_t  rotate_x;

//     // angle += e->angle;
//     // if (angle >= 360.0)
//     //     angle -= 360.0;

//     rotate_x = vec3(1, 0, 0);
//     modelview2 = m4_rotation(1, rotate_x);
//     ft_set_coord(e, modelview2);
// }



// void    ft_change_map(t_env *e)
// {
//     static float   angle;
//     mat4_t  projection;

//     angle += e->zoomFactor;
//     if (angle >= 360.0)
//         angle -= 360.0;
//     projection = m4_perspective(angle, WIN_WIDTH/WIN_HEIGHT, 1.0, 100.0); 
//     ft_set_coord(e, projection);
// }


void    ft_set_coord(t_env *e, mat4_t matrice)
{
    int     i;
	int     j;
    int     x;
    int     y;
    int     z;
    int     w;
    vec4_t  vecteur;

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
            // ft_putnbr(x);
            // ft_putnbr(y);
            // ft_putnbr(z);
            // ft_putchar(' ');
            vecteur = vec4(x, y, z, w);
            vecteur = m4_mult_pos(matrice, vecteur);
            //  ft_putchar(' ');
            // ft_putnbr(vecteur.x);
            // ft_putnbr(vecteur.y);
            // ft_putnbr(vecteur.z);
            e->map_buffer->lines[i]->points[j]->x = vecteur.x;
            e->map_buffer->lines[i]->points[j]->y = vecteur.y;
            e->map_buffer->lines[i]->points[j]->z = vecteur.z;
            e->map_buffer->lines[i]->points[j]->w = vecteur.w;
			j++;
		}
		i++;
    }
}

void    malloc_points(t_env *e)
{
    int i;
    int j;

    i = 0;
    while (i < e->map->len)
	{
        e->map_buffer->lines[i] = (t_line *)malloc(sizeof(t_line));
        e->map_buffer->lines[i]->points = (t_point **)malloc(sizeof(t_point *) * e->map->lines[i]->len);
        j = 0;
		while (j < (e->map->lines[i]->len))
		{
            e->map_buffer->lines[i]->points[j] = (t_point*)malloc(sizeof(t_point));
			j++;
		}
		i++;
    }
}


// void    ft_translate_coord(t_env *e)
// {
//     int     i;
// 	int     j;
//     int     x;
//     int     y;
//     int     z;
//     int     w;
//     vec3_t  coord;
//     vec4_t  vecteur;
//     mat4_t  translation;

//     coord = vec3((WIN_WIDTH - (18 * TILE_WIDTH)) / 2, (WIN_HEIGHT - (10 * TILE_HEIGHT)) / 2, 0);
// 	translation = m4_translation(coord);
//     i = 0;
//     while (i < e->map->len)
// 	{
//         j = 0;
// 		while (j < (e->map->lines[i]->len))
// 		{
//             x = e->map->lines[i]->points[j]->x;
//             y = e->map->lines[i]->points[j]->y;
//             z = e->map->lines[i]->points[j]->z;
//             w = e->map->lines[i]->points[j]->w;
//             vecteur = vec4(x, y, z, w);
//             vecteur = m4_mult_pos(translation, vecteur);
//             e->map->lines[i]->points[j]->x = vecteur.x;
//             e->map->lines[i]->points[j]->y = vecteur.y;
//             e->map->lines[i]->points[j]->z = vecteur.z;
//             e->map->lines[i]->points[j]->w = vecteur.w;
// 			j++;
// 		}
// 		i++;
//     }
// }

// void    ft_scale_coord(t_env *e)
// {
//     int     i;
// 	int     j;
//     int     x;
//     int     y;
//     int     z;
//     int     w;
//     vec3_t  coord;
//     vec4_t  vecteur;
//     mat4_t  scale;

//     coord = vec3((1 + e->scale_x), (1 + e->scale_y), 1);
// 	scale = m4_scaling(coord);
//     i = 0;
//     while (i < e->map->len)
// 	{
//         j = 0;
// 		while (j < (e->map->lines[i]->len))
// 		{
//             x = e->map->lines[i]->points[j]->x;
//             y = e->map->lines[i]->points[j]->y;
//             z = e->map->lines[i]->points[j]->z;
//             w = e->map->lines[i]->points[j]->w;
//             vecteur = vec4(x, y, z, w);
//             vecteur = m4_mult_pos(scale, vecteur);
//             e->map->lines[i]->points[j]->x = vecteur.x;
//             e->map->lines[i]->points[j]->y = vecteur.y;
//             e->map->lines[i]->points[j]->z = vecteur.z;
//             e->map->lines[i]->points[j]->w = vecteur.w;
// 			j++;
// 		}
// 		i++;
//     }
// }

// void    ft_rotationx_coord(t_env *e)
// {
//     int     i;
// 	int     j;
//     int     x;
//     int     y;
//     int     z;
//     int     w;
//     mat4_t  rotationx;
//     vec4_t  vecteur;

//     rotationx = m4_rotationx((e->angle) * PI / 180);
//     i = 0;
//     while (i < e->map->len)
// 	{
//         j = 0;
// 		while (j < (e->map->lines[i]->len))
// 		{
//             x = e->map->lines[i]->points[j]->x;
//             y = e->map->lines[i]->points[j]->y;
//             z = e->map->lines[i]->points[j]->z;
//             w = e->map->lines[i]->points[j]->w;
//             vecteur = vec4(x, y, z, w);
//             vecteur = m4_mult_pos(rotationx, vecteur);
//             e->map->lines[i]->points[j]->x = vecteur.x;
//             e->map->lines[i]->points[j]->y = vecteur.y;
//             e->map->lines[i]->points[j]->z = vecteur.z;
//             e->map->lines[i]->points[j]->w = vecteur.w;
// 			j++;
// 		}
// 		i++;
//     }
// }