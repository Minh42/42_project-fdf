/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:53:40 by minh              #+#    #+#             */
/*   Updated: 2018/01/05 14:42:43 by mpham            ###   ########.fr       */
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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct	s_img
{
	void		*img_ptr;
	int			*data; 
	int			size_l;
	int			bpp;
	int			endian;
}               t_img;

typedef struct  s_env
{
    void        *mlx;
    void        *win;
    t_img       img;
}               t_env;

#endif