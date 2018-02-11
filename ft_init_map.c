/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:49:49 by mpham             #+#    #+#             */
/*   Updated: 2018/02/11 22:46:06 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include "math3D.h"

t_color ft_colorConverter(t_env *e, int hexValue)
{
    t_color rgbcolor;
  
  if (e->color_r > 255 || e->color_g > 255 || e->color_b > 255)
  {
      e->color_r -= 255;
      e->color_g -= 255;
      e->color_b -= 255;
  }
  rgbcolor.r = ((hexValue >> 16) & 0xFF) + e->color_r;
  rgbcolor.g = ((hexValue >> 8) & 0xFF) + e->color_g;
  rgbcolor.b = ((hexValue) & 0xFF) + e->color_b;

  return (rgbcolor); 
}

void    ft_fill_pixel(t_env *e, int x, int y, int z, int color)
{
    int     new_color;
    t_color rgbcolor;
    
    new_color = mlx_get_color_value(e->mlx, color);
    rgbcolor = ft_colorConverter(e, new_color);
    if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
 	e->img.data[y * e->img.sizeline + x * e->img.bpp / 8] = rgbcolor.r;
 	e->img.data[y * e->img.sizeline + x * e->img.bpp / 8 + 1] = rgbcolor.g; 
 	e->img.data[y * e->img.sizeline + x * e->img.bpp / 8 + 2] = rgbcolor.b;
    //((int*)e->img.data)[(y * WIN_WIDTH) + x] = color;

     
}

void    ft_init_img(t_env *e)
{
    e->img.img_ptr = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
    e->img.data = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp, &e->img.sizeline, &e->img.endian);
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
    scale = m4_scaling(vec3((1 + e->scale_x), (1 + e->scale_y), (1 + e->scale_z)));
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
    ft_set_coord(e, ft_mult_mat4(translate, ft_mult_mat4(rotation, scale)));
    
    // camera = m4_look_at(eye, center, up);
    // projection = m4_perspective(100.0, WIN_WIDTH/WIN_HEIGHT, 1.0, 100.0); 
    
    ft_draw_horizontal(e);
    ft_draw_vertical(e);
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
    ft_set_coord(e, ft_mult_mat4(translate, ft_mult_mat4(rotation, scale)));
    
    // camera = m4_look_at(eye, center, up);
    // projection = m4_perspective(100.0, WIN_WIDTH/WIN_HEIGHT, 1.0, 100.0); 
    
    ft_draw_horizontal(e);
    ft_draw_vertical(e);  
    mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}

void    ft_set_coord(t_env *e, mat4_t matrice)
{
    int     i;
	int     j;
    int     x;
    int     y;
    int     z;
    int     w;
    int     color;
    vec4_t  vecteur;

    i = 0;
	while (i < e->nb_line)
	{
        j = 0;
		while (j < e->nb_col)
		{
            x = e->map[i][j][0];
            y = e->map[i][j][1];           
            z = e->map[i][j][2];
            w = e->map[i][j][3];
            color = e->map[i][j][4];
            vecteur = vec4(x, y, z, w);
            vecteur = m4_mult_pos(matrice, vecteur);
            e->map_buffer[i][j][0] = vecteur.x;
            e->map_buffer[i][j][1] = vecteur.y;
            e->map_buffer[i][j][2] = vecteur.z;
            e->map_buffer[i][j][3] = vecteur.w;  
            e->map_buffer[i][j][4] = color;            
			j++;
		}
		i++;
	}
}