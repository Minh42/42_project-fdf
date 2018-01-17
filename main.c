/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/01/17 17:43:32 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void alloc_matrice(const int nb_ligne, const int nb_col, t_matrice *matrice)
{
  matrice->nb_ligne = nb_ligne;
  matrice->nb_col = nb_col;
  matrice->p_matrice = (double*)malloc(sizeof(double) * nb_ligne * nb_col);
}

void    free_matrice(const t_matrice *matrice)
{
    free(matrice->p_matrice);
}

double  *matrice_element(const t_matrice *matrice, const int i, const int j)
{
    return (matrice->p_matrice + (i - 1) + matrice->nb_ligne * (j - 1));
}

void    mult_matrice(const t_matrice *matrice1, const t_matrice *matrice2, t_matrice *resultat)
{
    int     i;
    int     j;
    int     k;
    double  p;

    i = 1;
    j = 1;
    k = 1;
    free_matrice(resultat);
    alloc_matrice(matrice1->nb_ligne, matrice2->nb_col, resultat);
  
    while (i < matrice1->nb_ligne)
    {
        while (j < matrice2->nb_col)
        {
            p = 0;
            while (k <= matrice1->nb_col)
            {
                p = p + (*matrice_element(matrice1, i, k))*(*matrice_element(matrice2, k, j));
            }
            j++;
        }
        i++;
    }
    matrice_element(resultat, i, j) = p;
}


// t_matrice   *ft_translate(t_matrice *modelview, t_list *list)
// {
//     t_matrice   *translation;

//     translation = { {1, 0, 0, WIN_WIDTH/2}, {0, WIN_HEIGHT/2, 0, 1 }, {0, 0, 1, 0}, {0, 0, 0, 1} };

// }

// t_matrice   *ft_rotate(t_matrice *modelview, double angle, t_list *list)
// {
//     t_matrice   *rotation;

//     rotation =  

// }

// t_matrice   *ft_scale(t_matrice *modelview, t_list *list)
// {
//     t_matrice   *scale;

//     scale = { {2, 0, 0, 0}, {0, 2, 0, 0 }, {0, 0, 2, 0}, {0, 0, 0, 1} };

// }




void    draw_form(void *mlx, void *win, t_list *list)
{
    int         x;
    int         y;
    int         z;
    int         matrice[4][4];
    t_matrice   *modelview;
    // t_matrice   *translation;      
    // t_matrice   *resultat;




    x = 0;
    y = 0;
    matrice[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    // alloc_matrice(4, 4, modelview);
    // alloc_matrice(4, 4, translation);

    //translation->p_matrice = {{2, 3, 2, 0}, {4, 1, 2, 3}, {3, 0, 1, 3}, {1, 3, 0, 2}};
    // mult_matrice(modelview, translation, resultat);
    // ft_print_matrice(resultat);
    // modelview = ft_translate(modelview, t_list *list);
    while (list)
    {
        x = ((t_point *)(*list).content)->x; 
        y = ((t_point *)(*list).content)->y;
        z = ((t_point *)(*list).content)->z;
        mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
        list = list->next;
    }
}

// t_matrice ft_translation(t_matrice *modelview, int vecteur)
// {

// }



// t_matrice projection;
// t_matrice modelview;

// projection = ft_perspective(70.0, (double) WIN_WIDTH/WIN_HEIGHT, 1.0, 100.0);

// t_matrice ft_perspective(double angle, double ratio, double near, double far)



int     expose_hook(t_env *e)
{
    draw_form(e->mlx, e->win, e->list);
    return (0);
}

// int     mouse_hook(int button, int x, int y, t_env *e)
// {
//     printf("mouse: %d (%d:%d)\n", button, x, y);
//     return (0);
// }

// int     key_hook(int keycode, t_env *e)
// {
//     printf("key event %d\n", keycode);
//     if (keycode == 53) // exit
//         exit(0);
//     if (keycode == 49) // reset
    
//     if (keycode == 126) // up
//     if (keycode == 125) // down
//     if (keycode == 124) // right
//     if (keycode == 123) // left

//     return (0);
// }


t_list **ft_read_and_stock(t_list **list, char *line)
{
    int         i;
    int         x;
    static int  y = 0;
    char        **str;
    
    i = 0;
    x = 0;
    str = ft_strsplit(line, ' ');
    while (str[i] != '\0')
    {
        if (((*list = (t_list*)malloc(sizeof(t_list))) == NULL) ||
	    ((*list)->content = (t_point*)malloc(sizeof(t_point) * 4)) == NULL)
		    exit(1);
        ((t_point *)(*list)->content)->x = x;
        ((t_point *)(*list)->content)->y = y;
        ((t_point *)(*list)->content)->z = ft_getnbr(&str[i][0]);
        ((t_point *)(*list)->content)->color = ft_strchr(str[i], ',') ?  &str[i][2] : "0xFFFFFF";
        i++;
        x++;
        list = &(*list)->next;
    }
    *list = NULL;
    y++;
    return (list);
}

int		main(int argc, char **argv)
{
    int		fd;
    char	*line;
    t_list  *list;
    t_list  **p_list;
    t_env   e;

	if (argc != 2)
		ft_putstr("too many or too few arguments\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
    }
    p_list = &list;
	while (get_next_line(fd, &line) > 0)
	{
        p_list = ft_read_and_stock(p_list, line);
    }
    //ft_print_list(list);
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
	}
    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
    e.list = list;
    mlx_expose_hook(e.win, expose_hook, &e);
    // mlx_key_hook(e.win, key_hook, &e);
    // mlx_mouse_hook(e.win, mouse_hook, &e);
    mlx_loop(e.mlx);
    return (0);
}
