/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2017/12/23 17:07:37 by minh             ###   ########.fr       */
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

t_list	*ft_create_elem(void *data)
{
	t_list *elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (elem)
	{
		elem->next = 0;
		elem->data = data;
	}
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;

	list = *begin_list;
	if (! list)
	{
		list = ft_create_elem(data);
	}
	else
	{
		while ((list)->next)
		{
			list = list->next;
		}
		list->next = ft_create_elem(data);
	}
}

void	ft_list_foreach(t_list *list, void (*f)(void*))
{
	while (list)
	{
		f(list->data);
		list = list->next;
	}
}

void    print_list(t_list *list)
{
    t_elem *elem;
    
    elem = list -> first;
    while (elem)
    {
        printf("%d\n", elem->data);
        elem = elem -> next;
    }
}

/*
void    draw_form(void *mlx, void *win, t_point *coord)
{
    // int x;
    // int y;
    // int nb_col;
    // int nb_ligne;

    // créer un rectangle en parcourant de gauche à droite
    //y = 50;
    //nb_ligne = 150;
    while (y <= y2)
    {
        //x = 50;
        //nb_col = 400;
        while (x < x2)
        {      
            if (x == 100 || y == 100)
                mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
            if (y == y2)
                mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
            x++;
        }
            if (x == x2)
                mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
        y++;
    }
}
*/

void    draw_grid(void *param)
{
    int x;
    int x2;
    int y;
    int y2;
    int i;
    int j;
    //int k;
    t_list *coord;
    
    x = 100;
    x2 = 2000;
    y = 100;
    y2 = 1200;
    i = (x2 - x) / 19;
    j = (y2 - y) / 11;
    
    if (((coord = (t_list*)malloc(sizeof(t_list))) == NULL) ||
	(coord->data = (t_point*)malloc(sizeof(t_point) * 4)) == NULL)
		return (NULL);

    coord->data.x = x;
    coord->data.x2 = x + i;
    coord->data.y = x;
    coord->data.y2 = x + j;

    ft_create_elem(t_point *coord);
    print_list(&coord);
        
         
    /*
    while (y <= y2)
    {
        while (x < x2)
        {
            ft_list_foreach()
            x = x + i;
        }
        y = y + j;
    }
    */

}

int     expose_hook(t_env *e)
{
    draw_grid(t_env *e);
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