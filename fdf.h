/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:53:40 by minh              #+#    #+#             */
/*   Updated: 2017/12/23 16:56:11 by minh             ###   ########.fr       */
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

typedef struct s_env
{
    void *mlx;
    void *win;
}              t_env;

typedef struct s_point
{
    int         x;
    int         x2;
    int         y;
    int         y2;
}              t_point;

typedef struct s_elem
{
    t_point         *data;
    struct s_elem   *next;
}              t_elem;

typedef struct s_list
{
    t_point         *data;
    struct s_elem   *first;
}              t_list;

#endif