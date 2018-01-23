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

# include "fdf.h"

int     ft_count_row(char *map)
{
    int     fd;
    int     nb_lines;
    char    *line;

    nb_lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
	}
	while (get_next_line(fd, &line) > 0)
	{
		nb_lines++;
	}
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
	}
    return (nb_lines);
}

int     ft_count_column(char *line)
{
    int     i;
    char    **str;
    
    i = 0;
    str = ft_strsplit(line, ' ');
    while (str[i] != 0)
		i++;
    return (i);
}

void    ft_print_tab(t_map *map)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;

    while (i < map->len)
	{
		while (j < (map->lines[j]->len))
		{
            while (k < (map->lines[j]->len))
            {
                ft_putnbr(map->lines[j]->points[k]->x);
                ft_putnbr(map->lines[j]->points[k]->y);
                ft_putnbr(map->lines[j]->points[k]->z);
                ft_putnbr(map->lines[j]->points[k]->w);
                ft_putstr(map->lines[j]->points[k]->color);
                ft_putchar('\n');
                k++;
            } 
            k = 0;
            j++; 
        }
        i++;
    }
}

t_point     **ft_get_coord(char *line, int nb_line, t_point ***array_points)
{
    int		i;
	char	**str;
	t_point	*coord;

	i = 0;
    str = ft_strsplit(line, ' ');
	if (!((*array_points) = (t_point**)malloc(sizeof(t_point) * ft_count_column(line))))
        ft_putstr("malloc failed");
	while (str[i] != 0)
	{
		if (!(coord = (t_point*)malloc(sizeof(t_point))))
            ft_putstr("malloc failed");
		coord->x = i;
		coord->y = nb_line;
		coord->z = ft_getnbr(str[i]);
		coord->w = 1;
		coord->color = ft_strchr(str[i], ',') ?  &str[i][2] : "0xFFFFFF";
		(*array_points)[i] = coord;
		i++;
	}
	return (*array_points);
}

t_map   *ft_parse_map(char **argv)
{
    int     fd;
    int     nb_line;
    char    *line;
    t_map   *map;
    t_line  *line_map;
    t_point **array_points;

    nb_line = 0;
    if (!(map = (t_map*)malloc(sizeof(t_map))) ||
		!(map->lines = (t_line**)malloc(sizeof(t_line) * ft_count_row(argv[1]))))
        ft_putstr("malloc failed");
    map->len = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
		ft_putstr("open() failed\n");
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line_map = (t_line*)malloc(sizeof(t_line))))
            ft_putstr("malloc failed");
        line_map->len = ft_count_column(line);
        line_map->points = ft_get_coord(line, nb_line, &array_points);
        map->lines[nb_line] = line_map;
        nb_line++;  
	}
    map->len = nb_line;
    ft_print_tab(map);
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
	}
    return (map);
}






