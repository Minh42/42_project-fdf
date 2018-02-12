/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:07:06 by minh              #+#    #+#             */
/*   Updated: 2018/02/12 18:03:26 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_line(char *map)
{
	int			fd;
	int			nb_line;
	char		*line;

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

int		ft_count_column(char *map)
{
	int			i;
	int			fd;
	char		*line;
	char		**str;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed\n");
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		while (str[i] != '\0')
			i++;
		break ;
	}
	while (get_next_line(fd, &line) > 0)
	{
	}
	free(line);
	if (close(fd) == -1)
		ft_putstr("close() failed\n");
	return (i);
}

void	ft_print_tab(t_env *e)
{
	int			i;
	int			j;

	i = 0;
	while (i < e->nb_line)
	{
		j = 0;
		while (j < e->nb_col)
		{
			ft_putnbr(e->map[i][j][0]);
			ft_putchar('\n');
			ft_putnbr(e->map[i][j][1]);
			ft_putchar('\n');
			ft_putnbr(e->map[i][j][2]);
			ft_putchar('\n');
			ft_putnbr(e->map[i][j][3]);
			ft_putchar('\n');
			ft_putnbr(e->map[i][j][4]);
			ft_putchar('\n');
			j++;
		}
		i++;
	}
}

void	ft_get_coord(t_env *e, char *line)
{
	static	int	i;
	int			j;
	char		**str;

	j = 0;
	str = ft_strsplit(line, ' ');
	e->map[i] = (int **)malloc(e->nb_col * sizeof(int *));
	e->map_buffer[i] = (int **)malloc(e->nb_col * sizeof(int *));
	while (str[j] != '\0' && j < e->nb_col)
	{
		e->map[i][j] = (int *)malloc(5 * sizeof(int));
		e->map_buffer[i][j] = (int *)malloc(5 * sizeof(int));
		e->map[i][j][0] = j * TILE_WIDTH;
		e->map[i][j][1] = i * TILE_HEIGHT;
		e->map[i][j][2] = ft_getnbr(str[j]);
		e->map[i][j][3] = 1;
		e->map[i][j][4] = ft_strchr(str[j], ',') ?
		ft_atoi_base(ft_skip(str[j]), 16) : (int)ft_strtol("FFFFFF");
		j++;
	}
	i++;
}

void	ft_parse_map(t_env *e, char **argv)
{
	int			fd;
	char		*line;
	int			***map;
	int			***map_buffer;

	if (!(e->map = (int ***)malloc(e->nb_line * sizeof(int **))) ||
			!(e->map_buffer = (int ***)malloc(e->nb_line * sizeof(int **))))
	{
		ft_putstr("malloc failed");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		exit(EXIT_SUCCESS);
	}
	while (get_next_line(fd, &line) > 0)
		ft_get_coord(e, line);
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		exit(EXIT_SUCCESS);
	}
}
