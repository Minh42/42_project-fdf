/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_stock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <mpham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:07:06 by minh              #+#    #+#             */
/*   Updated: 2018/01/23 15:07:07 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int     ft_count_line(char *map)
{
    int     fd;
    int     nb_line;
    char    *line;

    nb_line = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed\n");
	while (get_next_line(fd, &line) > 0)
	{
		nb_line++;
	}
	free(line);
	if (close(fd) == -1)
		ft_putstr("close() failed\n");
    return (nb_line);
}

int     ft_count_column(char *map)
{
	int		i;
    int     fd;
    char    *line;
	char 	**str;
	
	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed\n");
	while (get_next_line(fd, &line) > 0)
	{
    	str = ft_strsplit(line, ' ');
		while (str[i] != '\0')
			i++;
		break;
	}
	free(line);
	if (close(fd) == -1)
		ft_putstr("close() failed\n");
    return (i);
}

void    ft_print_tab(int nb_line, int nb_col, int (*map)[nb_line][nb_col][4])
{
    int i;
    int j;

    i = 0;
	while (i < nb_line)
	{
        j = 0;
		while (j < nb_col)
		{
			ft_putnbr((*map)[i][j][0]);
			ft_putnbr((*map)[i][j][1]);
			ft_putnbr((*map)[i][j][2]);
			ft_putnbr((*map)[i][j][3]);
			// ft_putnbr((*map)[i][j][4]);
            ft_putchar('\n');
			j++;
		}
		i++;
	}
}

void     ft_get_coord(char *line, int nb_line, int nb_col, int (*map)[nb_line][nb_col][4])
{
    static	int	i;
	int			j;
	char		**str;

	j = 0;
    str = ft_strsplit(line, ' ');
	while (str[j] != '\0' && j < nb_col)
	{
		(*map)[i][j][0] = j; //* TILE_WIDTH;
		(*map)[i][j][1] = i; //* TILE_HEIGHT;
		(*map)[i][j][2] = ft_getnbr(str[j]);
		(*map)[i][j][3] = 1;
		//(*map)[i][j][4] = ft_strchr(str[i], ',') ?  &str[i][2] : "0xFFFFFF";
		j++;
	}
	i++;
}

void   ft_parse_map(char **argv, t_env *e, int nb_line, int nb_col)
{
	int     fd;
    char    *line;
	int 	(*map)[nb_line][nb_col][4]; // map is a pointer to a 3 dimensional array
	int 	(*map_buffer)[nb_line][nb_col][4];

	if(!(map = malloc(sizeof(*map))) || !(map_buffer = malloc(sizeof(*map_buffer))))
	{
		ft_putstr("malloc failed");
		exit(EXIT_FAILURE);
	}
	e->map = map;
	e->map_buffer = map_buffer;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
		ft_putstr("open() failed\n");
	while (get_next_line(fd, &line) > 0)
	{
        ft_get_coord(line, nb_line, nb_col, map);
	}
	free(line);
	ft_print_tab(nb_line, nb_col, map);
	if (close(fd) == -1)
		ft_putstr("close() failed\n");
}
