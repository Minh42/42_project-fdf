/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:29:33 by minh              #+#    #+#             */
/*   Updated: 2018/02/12 18:44:23 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math3d.h"

int		ft_check_valid_filename(char **argv)
{
	char	*str;
	char	*ext;
	char	*ret;

	str = argv[1];
	ext = ".fdf";
	ret = ft_strrchr(str, '.');
	if (ret == NULL)
	{
		ft_putstr("incorrect filename\n");
		return (-1);
	}
	else
	{
		if (ft_strcmp(ret, ext) != 0)
		{
			ft_putstr("incorrect filename\n");
			return (-1);
		}
	}
	return (0);
}

int		ft_check_data_entry(int fd)
{
	int		ret;
	char	*line;

	ret = get_next_line(fd, &line);
	if (ret == 0 || ret == -1)
	{
		ft_putstr("no data found\n");
		return (-1);
	}
	while (get_next_line(fd, &line) > 0)
	{
	}
	free(line);
	return (0);
}

int		ft_check_data_validity(int fd)
{
	int		i;
	char	**str;
	char	*line;

	while (get_next_line(fd, &line))
	{
		i = 0;
		str = ft_strsplit(line, ' ');
		while (str[i] != '\0')
		{
			if (ft_isnumber(str[i]) == 0 && ft_isxdigit(str[i]) == 0)
			{
				ft_putstr("invalid data\n");
				return (-1);
			}
			i++;
		}
	}
	free(line);
	return (0);
}

int		ft_check_map_validity(int fd)
{
	char	*line;
	int		len;

	get_next_line(fd, &line);
	len = ft_count_words(line);
	while (get_next_line(fd, &line))
	{
		if (len != ft_count_words(line))
		{
			ft_putstr("map not rectangular\n");
			return (-1);
		}
	}
	free(line);
	return (0);
}

int		ft_checks(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (-1);
	}
	if (ft_check_valid_filename(argv) == -1)
		return (-1);
	if (ft_check_data_entry(fd) == -1)
		return (-1);
	if (ft_check_data_validity(fd) == -1)
		return (-1);
	if (ft_check_map_validity(fd) == -1)
		return (-1);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (-1);
	}
	return (0);
}
