/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/01/15 15:34:08 by minh             ###   ########.fr       */
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
        printf("%s", ((t_point *)(tmp->content))->color);
        tmp = tmp->next;
    }
    
}

int     ft_XtoIsoX(int x, int y)
{
    int isoX;

    isoX = (x - y) * (TILE_WIDTH / 2);
    return (isoX);
}

int     ft_YtoIsoY(int x, int y)
{
    int isoY;

    isoY = (x + y) * (TILE_HEIGHT / 2);
    return (isoY);
}

void    draw_form(void *mlx, void *win, t_list *list)
{
    int x;
    int y;
    int i;
    int j;

    x = 0;
    y = 0;
    i = (WIN_WIDTH / 2) - (11 * TILE_WIDTH);
    j = (WIN_HEIGHT / 2) - (19 * TILE_HEIGHT);
    while (list)
    {
        x = ((t_point *)(*list).content)->x;
        y = ((t_point *)(*list).content)->y;
        mlx_pixel_put(mlx, win, ft_XtoIsoX(x, y) + i, ft_YtoIsoY(x, y), 0x0000FFFF);
        list = list->next;
    }
}

int     expose_hook(t_env *e)
{
    draw_form(e->mlx, e->win, e->list);
    return (0);
}


/*
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
*/

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
