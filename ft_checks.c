/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <mpham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:29:33 by minh              #+#    #+#             */
/*   Updated: 2018/02/06 14:41:51 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_valid_filename(char **argv)
{
	char	*str;
	char	*ext;
	char 	*ret;

	str = argv[1];
	ext = ".fdf";
	ret = ft_strrchr(str, '.');
	if (ret == NULL)
	{
		ft_putstr("incorrect filename\n");
		return (-1);
	}
	else
		if (ft_strcmp(ret, ext) != 0)
		{
			ft_putstr("incorrect filename\n");
			return (-1);
		}
	return (0);
}

int     ft_check_data_entry(char **argv)
{
	int		fd;
    int     ret;
    char	*line;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return(-1);
	}
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
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return(-1);
	}
    return (0);
}

int		ft_isxdigit(char *str)
{
	int		i;
	char 	*hex;

	i = 0;
	if (ft_strlen(str) >= 10)
	{
		hex = ft_strsub(str, ft_strlen(str) - 6, 6);
		if (ft_strspn(hex, "0123456789abcdefABCDEF") == 6 && ft_strstr(str, ",0x"))
		return (1);
	}
	return (0);
}

int     ft_check_data_validity(char **argv)
{
    int     i;
	int		fd;
	char 	**str;
    char	*line;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (-1);
	}
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
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return(-1);
	}
    return (0);
}

int     ft_check_map_validity(char **argv)
{
	int		fd;
    char	*line;
    int		len;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (-1);
	}
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
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return(-1);
	}
    return (0);
}

int	    ft_checks(char **argv)
{
	if (ft_check_valid_filename(argv) == -1)
		return (-1);
	if (ft_check_data_entry(argv) == -1)
		return (-1);
	if (ft_check_data_validity(argv) == -1)
		return (-1);
	if (ft_check_map_validity(argv) == -1)
		return (-1);
	return (0);
}