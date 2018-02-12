/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:53:40 by minh              #+#    #+#             */
/*   Updated: 2018/02/12 19:06:50 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# include "math3d.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_WIDTH 25
# define TILE_HEIGHT 25
# define PI 3.14159265359

# define EXIT 53
# define CLEAR 51
# define RESET 49
# define MOVE_UP 126
# define MOVE_DOWN 125
# define MOVE_RIGHT 124
# define MOVE_LEFT 123
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define ZOOM_UP 116
# define ZOOM_DOWN 121
# define ROTATE_UP 13
# define ROTATE_DOWN 1
# define ROTATE_RIGHT 2
# define ROTATE_LEFT 0
# define ROTATE_Z1 12
# define ROTATE_Z2 14
# define COLOR_RED 15
# define COLOR_GREEN 5
# define COLOR_BLUE 11

typedef	struct		s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_color;

typedef	struct		s_matrice
{
	t_mat4			translate;
	t_mat4			scale;
	t_mat4			rotationx;
	t_mat4			rotationy;
	t_mat4			rotationz;
	t_mat4			rotation;
}					t_matrice;

typedef	struct		s_point
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				z;
	int				w;
	int				color;
}					t_point;

typedef	struct		s_coord
{
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
	int				color;
}					t_coord;

typedef	struct		s_algo
{
	int				dx;
	int				dy;
	int				dpx;
	int				dpy;
	int				xincr;
	int				yincr;
	int				ex;
	int				ey;
}					t_algo;

typedef	struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				sizeline;
	int				bpp;
	int				endian;
}					t_img;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	int				***map;
	int				***map_buffer;
	t_img			img;
	int				nb_line;
	int				nb_col;
	int				offset_x;
	int				offset_y;
	int				zoom;
	int				scale_z;
	int				angle_x;
	int				angle_y;
	int				angle_z;
	int				color_r;
	int				color_g;
	int				color_b;
}					t_env;

int					ft_checks(char **argv);
int					ft_check_valid_filename(char **argv);
int					ft_check_data_entry(int fd);
int					ft_check_data_validity(int fd);
int					ft_check_map_validity(int fd);
char				*ft_skip(char *str);
void				ft_parse_map(t_env *e, char **argv);
void				ft_get_coord(t_env *e, char *line);
void				ft_print_tab(t_env *e);
int					ft_count_column(char *map);
int					ft_count_line(char *map);
void				ft_load_map(t_env *e);
void				ft_reset_map(t_env *e);
void				ft_redraw(t_env *e);
void				ft_reset(t_env *e);
void				ft_set_coord(t_env *e, t_mat4 matrice);
void				ft_draw_horizontal(t_env *e);
void				ft_draw_vertical(t_env *e);
void				ft_bresenham(t_env *e, t_coord *coord);
void				ft_bresenham1(t_env *e, t_algo *b, t_coord *coord);
void				ft_bresenham2(t_env *e, t_algo *b, t_coord *coord);
void				ft_fill_pixel(t_env *e, int x1, int y1, t_coord *coord);
void				ft_init_img(t_env *e);
int					key_hook(int keycode, t_env *e);
void				move_hook(int keycode, t_env *e);
void				rotate_hook(int keycode, t_env *e);
void				zoom_hook(int keycode, t_env *e);
void				color_hook(int keycode, t_env *e);
t_color				ft_color_converter(t_env *e, int hexvalue);

#endif
