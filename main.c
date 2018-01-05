/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:13:24 by minh              #+#    #+#             */
/*   Updated: 2018/01/05 17:34:56 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_print_list(t_list *liste)
{
    t_list *tmp = liste;
    if (tmp == NULL)
    {
        ft_putstr("erreur");
    }
    while (tmp)
    {
        printf("%s", tmp->content);
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









int		main(int argc, char **argv)
{
    int		fd;
    char	*line;
    t_list  *list = NULL;

	if (argc != 2)
		ft_putstr("too many or too few arguments\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
    }
    if ((list = (t_list*)malloc(sizeof(t_list))) == NULL)
        return (-1);
    if (list)
    {
        list->content = 0;
        list->next = NULL;
    }
	while (get_next_line(fd, &line) > 0)
	{

        ft_list_push_back(&list, line);

    }
    list = ft_list_last(list);
    ft_putstr(list->content);
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
	}
	return (0);
}
