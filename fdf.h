/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:53:40 by minh              #+#    #+#             */
/*   Updated: 2018/01/24 19:52:33 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_WIDTH 25
# define TILE_HEIGHT 25
# define PI 3.14159265359

typedef struct	s_point
{
	int 		x;
	int 		y;
	int 		z;
	int			w;
	char		*color;
}			  	t_point;

typedef struct  s_line
{
	t_point	**points;
	int		len;
}				t_line;

typedef struct  s_map
{
	t_line	**lines;
	int		len;
}				t_map;

typedef struct	s_img
{
	void		*img_ptr;
	char		*data; 
	int			sizeline;
	int			bpp;
	int			endian;
}               t_img;

typedef struct  s_env
{
    void        *mlx;
    void        *win;
	t_map		*map;
    t_img       img;
}               t_env;

t_map   *ft_parse_map(char **argv);
int     ft_map_size(char *map);
void	ft_print_list(t_list *list);
void    ft_bresenham(void *mlx, void *win, int x1, int y1, int x2, int y2);


#endif