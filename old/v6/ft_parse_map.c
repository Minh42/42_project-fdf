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

void    ft_print_tab(int nb_line, int nb_col, int ***map)
{
    int i;
    int j;

    i = 0;
	while (i < nb_line)
	{
        j = 0;
		while (j < nb_col)
		{
			ft_putnbr(map[i][j][0]);
			ft_putnbr(map[i][j][1]);
			ft_putnbr(map[i][j][2]);
			ft_putnbr(map[i][j][3]);
			// ft_putstr(map[i][j].color);
            ft_putchar('\n');
			j++;
		}
		i++;
	}
}

void     ft_get_coord(char *line, int nb_line, int nb_col, int ***map, int ***map_buffer)
{
    static	int	i;
	int			j;
	char		**str;

	j = 0;
    str = ft_strsplit(line, ' ');

	map[i] = (int **)malloc(nb_col * sizeof(int *));
	map_buffer[i] = (int **)malloc(nb_col * sizeof(int *));
	while (str[j] != '\0' && j < nb_col)
	{
		map[i][j] = (int *)malloc(4 * sizeof(int));
		map_buffer[i][j] = (int *)malloc(4 * sizeof(int));
		map[i][j][0] = j * TILE_WIDTH;
		map[i][j][1] = i * TILE_HEIGHT;
		map[i][j][2] = ft_getnbr(str[j]);
		map[i][j][3] = 1;
		// map[i][j].color = ft_strchr(str[j], ',') ?  &str[j][2] : "0xFFFFFF";
		j++;
	}
	i++;
}

void   ft_parse_map(char **argv, t_env *e, int nb_line, int nb_col)
{
	int		fd;
    char	*line;
	int		***map;
	int 	***map_buffer;

	if(!(map = (int ***)malloc(nb_line * sizeof(int **))) || 
		!(map_buffer = (int ***)malloc(nb_line * sizeof(int **))))
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
        ft_get_coord(line, nb_line, nb_col, e->map, e->map_buffer);
	}
	free(line);
	ft_print_tab(nb_line, nb_col, e->map);
	if (close(fd) == -1)
		ft_putstr("close() failed\n");
}
