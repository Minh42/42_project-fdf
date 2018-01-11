/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/01/11 22:01:38 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_print_list(t_list *list)
{
    t_list *tmp = list;
    if (tmp == NULL)
    {
        ft_putstr("erreur");
    }
    while (tmp)
    {
        printf("%d", ((t_point *)(tmp->content))->x);
        printf("%d", ((t_point *)(tmp->content))->y);
        printf("%d", ((t_point *)(tmp->content))->z);
        //printf("%s", ((t_point *)(tmp->content))->color);
        tmp = tmp->next;

    }
}



/*

void    draw_form(void *mlx, void *win) 
{

}

int     expose_hook(t_env *e)
{
    draw_form(e->mlx, e->win);
    return (0);
}

int     mouse_hook(int button, int x, int y, t_env *e)
{
    printf("mouse: %d (%d:%d)\n", button, x, y);
    return (0);
}

int     key_hook(int keycode, t_env *e)
{
    printf("key event %d\n", keycode);
    if (keycode == 53)
        exit(0);
    return (0);
}

int     main()
{
    t_env   e;

    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
    mlx_expose_hook(e.win, expose_hook, &e);
    mlx_key_hook(e.win, key_hook, &e);
    mlx_mouse_hook(e.win, mouse_hook, &e);
    mlx_loop(e.mlx);
    return (0);
}

*/

void afficher_tab(char **str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i][0]);
        i++;
    }
    ft_putchar('\n');
}

t_list **ft_read_and_stock(t_list **list, char *line)
{
    int         i;
    int         j;
    int         x;
    static int  y = 0;
    char        **str;
    
    i = 0;
    j = 0;
    x = 0;
    str = ft_strsplit(line, ' ');
    while (str[i] != '\0')
    {
        if ((*list = (t_list*)malloc(sizeof(t_list))) == NULL)
		    exit(1);
        if (((*list)->content = (t_point*)malloc(sizeof(t_point) * 4)) == NULL)
		    exit(1);
        ((t_point *)(*list)->content)->x = x;
        // ft_putstr("x = ");
        // ft_putnbr(((t_point *)(*list)->content)->x);
        // ft_putchar('\n');
        ((t_point *)(*list)->content)->y = y;
        // ft_putstr("y = ");
        // ft_putnbr(((t_point *)(*list)->content)->y);
        // ft_putchar('\n');
        ((t_point *)(*list)->content)->z = ft_getnbr(&str[i][0]);
        if (ft_strchr(str[i], ',')) 
        {
            ((t_point *)(*list)->content)->color = &str[i][2];
            ft_putstr("color = ");
            ft_putstr(((t_point *)(*list)->content)->color);
        }
        else 
        {
            ((t_point *)(*list)->content)->color = "0xFFFFFF";
            ft_putstr("color = ");
            ft_putstr(((t_point *)(*list)->content)->color);
        }
        /*
        if (ft_strchr(str[i], ',')) 
		{
            ((t_point *)(*list)->content)->z = ft_getnbr(&str[i][0]);
			j = 0;
			while (str[i][j] != '\0')
			{
				if (str[i][j] == ',')
				{
                    ((t_point *)(*list)->content)->color = &str[i][j + 1];
					ft_putstr("color = ");
                    ft_putstr(((t_point *)(*list)->content)->color);
					ft_putchar('\n');
				}
				j++;
			}
		}
        */

        // ft_putstr("z = ");
        // ft_putnbr(((t_point *)(*list)->content)->z);
        // ft_putchar('\n');
        // ft_putstr("color = ");
        // ft_putstr(((t_point *)(*list)->content)->color);
        // ft_putchar('\n');
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
	return (0);
}
