/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:53:40 by minh              #+#    #+#             */
/*   Updated: 2018/01/17 17:34:49 by mpham            ###   ########.fr       */
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

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define TILE_WIDTH 50
# define TILE_HEIGHT 50


typedef struct	s_point
{
	int 		x;
	int 		y;
	int 		z;
	char		*color;
}			  	t_point;

typedef struct	s_matrice
{
	int 		nb_ligne;
	int 		nb_col;
	double		**p_matrice;
}				t_matrice;

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
	t_list		*list;
    t_img       img;
}               t_env;

void	ft_print_list(t_list *list);
void 	ft_print_matrice(t_matrice *matrice);
void 	alloc_matrice(const int nb_ligne, const int nb_col, t_matrice *matrice);
void    free_matrice(const t_matrice *matrice);void    free_matrice(const t_matrice *matrice);
double  *matrice_element(const t_matrice *matrice, const int i, const int j);
void    mult_matrice(const t_matrice *matrice1, const t_matrice *matrice2, t_matrice *resultat);

#endif