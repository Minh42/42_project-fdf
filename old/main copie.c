/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2017/12/22 21:08:04 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     key_hook(int keycode, t_env *e)
{
    printf("key event %d\n", keycode);
    if (keycode == 53)
        exit(0);
    return (0);
}

void    draw_grid(void *mlx, void *win)
{
    t_point coord; 

    coord.x = 50;
    coord.x2 = 150;
    coord.y = 50;
    coord.y2 = 150;
    
    while ()
    draw_form(coord->x, coord->y, coord->x2, coord->y2)
    
}


void    draw_form(int x, int y, int x2, int y2)
{
    int x;
    int y;
    int nb_col;
    int nb_ligne;

    // créer un rectangle en parcourant de gauche à droite
    y = 50;
    nb_ligne = 150;
    while (y <= nb_ligne)
    {
        x = 50;
        nb_col = 400;
        while (x < nb_col)
        {      
            if (x == 50 || y == 50)
                mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
            if (y == nb_ligne)
                mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
            x++;
        }
            if (x == nb_col)
                mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
        y++;
    }
}

int     expose_hook(t_env *e)
{
    draw_grid(e->mlx, e->win);
    return (0);
}

int     mouse_hook(int button, int x, int y, t_env *e)
{
    printf("mouse: %d (%d:%d)\n", button, x, y);
    return (0);
}

int     main()
{
    t_env   e;

    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, 1280, 1024, "mlx 42");
    mlx_expose_hook(e.win, expose_hook, &e);
    mlx_key_hook(e.win, key_hook, &e);
    mlx_mouse_hook(e.win, mouse_hook, &e);
    mlx_loop(e.mlx) ; //ne rend pas la main il faut appeler exit lorsqu'on appuie sur une touche pour fermer la fenetre
    return (0);
}

// changer la couleur en fonction des coordonnées