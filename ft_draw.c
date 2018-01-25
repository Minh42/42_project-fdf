/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:55:51 by mpham             #+#    #+#             */
/*   Updated: 2018/01/25 17:56:50 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void		ft_draw_horizontal(void *mlx, void *win, t_env *e)
{
	int 	i;
	int 	j;
	int		isoX1;
	int		isoY1;
	int		isoX2;
	int		isoY2;
	t_coord	coord;
	
    i = 0;
    while (i < e->map->len)
	{
        j = 0;
		while (j < (e->map->lines[i]->len - 1))
		{
            coord.x1 = e->map->lines[i]->points[j]->x;
            coord.y1 = e->map->lines[i]->points[j]->y;
            // coord.z1 = e->map->lines[i]->points[j]->z;
			// coord.w1 = e->map->lines[i]->points[j]->w;
			isoX1 = coord.x1 - coord.y1;
			isoY1 = (coord.x1 + coord.y1) / 2;
            coord.x2 = e->map->lines[i]->points[j + 1]->x;
            coord.y2 = e->map->lines[i]->points[j + 1]->y;
            // coord.z2 = e->map->lines[i]->points[j + 1]->z;
			// coord.w2 = e->map->lines[i]->points[j + 1]->w;  
			isoX2 = coord.x2 - coord.y2;
			isoY2 = (coord.x2 + coord.y2) / 2;
            // vecteur = vec4(x, y, z, w);
            // vecteur = m4_mult_pos(modelview, vecteur);
            // vecteur = m4_mult_pos(translation, vecteur);
            // mlx_pixel_put(e->mlx, e->win, vecteur.x, vecteur.y, 0x0000FFFF);
            if (j + 1 != e->map->lines[i]->len)
            {
            	ft_bresenham(mlx, win, isoX1, isoY1, isoX2, isoY2);
			}
            else
                break;
			j++;
		}
		i++;
    }
}

void		ft_draw_vertical(void *mlx, void *win, t_env *e)
{
	int 	i;
	int 	j;
	int		isoX1;
	int		isoY1;
	int		isoX2;
	int		isoY2;
	t_coord	coord;

	i = 0;
    j = 0;

    while (j < (e->map->lines[i]->len))
    {
		i = 0;
        while (i < e->map->len - 1)
        {
            coord.x1 = e->map->lines[i]->points[j]->x;
            coord.y1 = e->map->lines[i]->points[j]->y;
			isoX1 = coord.x1 - coord.y1;
			isoY1 = (coord.x1 + coord.y1) / 2;
            coord.x2 = e->map->lines[i + 1]->points[j]->x;
            coord.y2 = e->map->lines[i + 1]->points[j]->y;
			isoX2 = coord.x2 - coord.y2;
			isoY2 = (coord.x2 + coord.y2) / 2;
            if (i + 1 != e->map->len)
            {
            	ft_bresenham(mlx, win, isoX1, isoY1, isoX2, isoY2);
				// ft_putnbr(coord.y1);
				// ft_putchar('\n');
				// ft_putnbr(coord.y2);
				// ft_putchar('\n');
            }
            else
                break;
            i++;
        }
        j++;
    }
}





// void        draw_form(void *mlx, void *win, t_map *map)
// {
//     int         i;
// 	int         j;
//     // vec3_t     	vecteur;
//     // vec4_t     	vecteur_pos;
//     // vec4_t     	matrice;
// 	// mat4_t     	translation;
// 	// mat4_t		rotationz;
// 	// mat4_t		rotationy;
// 	// vec4_t		resultat;
// 	mat4_t	projection;
// 	mat4_t  modelview;

// 	projection = perspective(70, (double) TILE_WIDTH/TILE_HEIGHT, 1, 100);
// 	modelview = m4_identity();

// 	i = 0;
// 	j = 0;
//     // vecteur = vec3((WIN_WIDTH - (19 * TILE_WIDTH)) / 2, (WIN_HEIGHT - (11 * TILE_HEIGHT)) / 2, 0);
// 	// translation = m4_translation(vecteur);
// 	// rotationz = m4_rotationz(330 * 3.14 / 180);
// 	// rotationy = m4_rotationy(45 * 3.14 / 180);
//     while (i < map->len)
// 	{
//         j = 0;
// 		while (j < (map->lines[i]->len))
// 		{
//             // x = map->lines[i]->points[j]->x;
//             // y = map->lines[i]->points[j]->y;
//             // z = map->lines[i]->points[j]->z;
// 			// w = map->lines[i]->points[j]->w;
// 			ft_bresenham(mlx, win, map->lines[i]->points[j]->x, map->lines[i]->points[j + 1]->x, map->lines[i]->points[j]->y, map->lines[i]->points[j + 1]->y);
// 			// vecteur_pos = vec4(x, y, z, w);
// 			// resultat = m4_mult_pos(translation, vecteur_pos);
//         	// mlx_pixel_put(mlx, win, resultat.x, resultat.y, 0x0000FFFF);
// 			j++;
// 		}
// 		i++;
// 	}
// }