/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:49:49 by mpham             #+#    #+#             */
/*   Updated: 2018/02/05 19:55:03 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include "math3D.h"

void    ft_fill_pixel(t_env *e, int x, int y, int color)
{
    //int new_color;
    if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
    //new_color = mlx_get_color_value(e->mlx, color);
 	((int*)e->img.data)[(y * WIN_WIDTH) + x] = color;

    // mlx_put_image_to_window(e.mlx, e.win, e.img.img_ptr, 0, 0);
}

void    ft_init_img(t_env *e)
{
    e->img.img_ptr = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
    e->img.data = (int *)mlx_get_data_addr(e->img.img_ptr, &e->img.bpp, &e->img.sizeline, &e->img.endian);
}

void    ft_load_map(t_env *e)
{
    mat4_t  translate;
    mat4_t  scale;
    mat4_t  rotationx;
    mat4_t  rotationy;
    mat4_t  rotationz;
    mat4_t  rotation;
    // mat4_t  projection;
    // mat4_t  camera;

	ft_init_img(e);
    if (e->scale_x < 0)
        e->scale_x += 1;
    if (e->scale_y < 0)
        e->scale_y += 1;   
    scale = m4_scaling(vec3((1 + e->scale_x), (1 + e->scale_y), 1));
    if (e->angle_x >= 360.0)
        e->angle_x -= 360.0;
    if (e->angle_y >= 360.0)
        e->angle_y -= 360.0;
    if (e->angle_z >= 360.0)
        e->angle_z -= 360.0;
    rotationx = m4_rotationx((0.0 + e->angle_x) * PI / 180.0);
    rotationy = m4_rotationy((0.0 + e->angle_y) * PI / 180.0);
    rotationz = m4_rotationz((0.0 + e->angle_z) * PI / 180.0);
	translate = m4_translation(vec3((WIN_WIDTH - (e->nb_col * TILE_WIDTH)) / 2, (WIN_HEIGHT - (e->nb_line * TILE_HEIGHT)) / 2, 0));
    rotation = ft_mult_mat4(rotationz, ft_mult_mat4(rotationy, rotationx));
    ft_set_coord(e, ft_mult_mat4(translate, ft_mult_mat4(rotation, scale)), e->nb_line, e->nb_col, e->map, e->map_buffer);
    
    // camera = m4_look_at(eye, center, up);
    // projection = m4_perspective(100.0, WIN_WIDTH/WIN_HEIGHT, 1.0, 100.0); 
    
    ft_draw_horizontal(e, e->nb_line, e->nb_col, e->map_buffer);
    ft_draw_vertical(e, e->nb_line, e->nb_col, e->map_buffer);  
    mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}

void    ft_reset_map(t_env *e)
{
    mat4_t  translate;
    mat4_t  scale;
    mat4_t  rotationx;
    mat4_t  rotationy;
    mat4_t  rotationz;
    mat4_t  rotation;
    // mat4_t  projection;
    // mat4_t  camera;

	ft_init_img(e);
    scale = m4_scaling(vec3(1, 1, 1));
    rotationx = m4_rotationx(0.0 * PI / 180.0);
    rotationy = m4_rotationy(0.0 * PI / 180.0);
    rotationz = m4_rotationz(0.0 * PI / 180.0);
	translate = m4_translation(vec3((WIN_WIDTH - (e->nb_col * TILE_WIDTH)) / 2, (WIN_HEIGHT - (e->nb_line * TILE_HEIGHT)) / 2, 0));
    rotation = ft_mult_mat4(rotationz, ft_mult_mat4(rotationy, rotationx));
    ft_set_coord(e, ft_mult_mat4(translate, ft_mult_mat4(rotation, scale)), e->nb_line, e->nb_col, e->map, e->map_buffer);
    
    // camera = m4_look_at(eye, center, up);
    // projection = m4_perspective(100.0, WIN_WIDTH/WIN_HEIGHT, 1.0, 100.0); 
    
    ft_draw_horizontal(e, e->nb_line, e->nb_col, e->map_buffer);
    ft_draw_vertical(e, e->nb_line, e->nb_col, e->map_buffer);  
    mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}

void    ft_set_coord(t_env *e, mat4_t matrice, int nb_line, int nb_col, t_point (*map)[nb_line][nb_col], t_point (*map_buffer)[nb_line][nb_col])
{
    int     i;
	int     j;
    int     x;
    int     y;
    int     z;
    int     w;
    vec4_t  vecteur;

    i = 0;
	while (i < e->nb_line)
	{
        j = 0;
		while (j < e->nb_col)
		{
            x = (*map)[i][j].x;
            y = (*map)[i][j].y;            
            z = (*map)[i][j].z;
            w = (*map)[i][j].w;
            vecteur = vec4(x, y, z, w);
            vecteur = m4_mult_pos(matrice, vecteur);
            (*map_buffer)[i][j].x = vecteur.x;
            (*map_buffer)[i][j].y = vecteur.y;
            (*map_buffer)[i][j].z = vecteur.z;
            (*map_buffer)[i][j].w = vecteur.w;            
			j++;
		}
		i++;
	}
}