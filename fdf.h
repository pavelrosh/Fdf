/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:25:02 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/22 13:05:29 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "libft/get_next_line.h"
# include "mlx.h"

# define WIDTH 1280
# define HEIGHT 720
# define S_WIN width * height
# define P_ZOOM 1.1
# define N_ZOOM 0.9
# define MAX_ELEMS 100000
# define P_STRETCH 1.1
# define N_STRETCH 0.9

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define X_UP 91
# define X_DOWN 84
# define Y_RIGHT 88
# define Y_LEFT 86
# define Z_LEFT 89
# define Z_RIGHT 92
# define INCR 69
# define DECR 78
# define CENTER 49
# define PSX 106
# define PSY 79
# define NSX 64
# define NSY 80
# define STEP 50
# define P_ALPHA GR(10)
# define N_ALPHA -GR(10)
# define GR(x) (x * M_PI) / 180

typedef struct	s_degree
{
	float		degr_x;
	float		degr_y;
	float		degr_z;
}				t_degree;

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_center
{
	double		x_c;
	double		y_c;
	double		c_x;
	double		c_y;
	double		max_x;
	double		max_y;
	double		min_x;
	double		min_y;
}				t_center;

typedef struct	s_mtr
{
	double		m1;
	double		m2;
	double		m3;
	double		m4;
	double		m5;
	double		m6;
	double		m7;
	double		m8;
	double		m9;
}				t_mtr;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	double		dx;
	double		dy;
	double		x;
	double		y;
	double		x_end;
	double		y_end;
	double		incx;
	double		incy;
	double		pdx;
	double		pdy;
	double		es;
	double		el;
	int			el_num;
	int			lines;
	int			elems;
	int			color;
	t_coord		*coords;
	t_coord		*begin;
	t_center	*center;
	t_degree	*g;
}				t_mlx;

int				line_count(char	*argv);
int				read_fdf(int ***xy, int fd);
void			coord_in_arr(t_mlx *d, int **xy);
void			line_init(t_coord *arr, t_mlx *mlx_d);
void			in_center(t_mlx *d);
int				key_hook(int key, t_mlx *d);
void			ft_move(t_mlx *d, int dx, int dy);
void			to_win_corn(t_mlx *d);
void			ft_rotate(t_mlx *d, char axis, float degr);
t_mtr			*mtr_init_x(double degr);
t_mtr			*mtr_init_y(double degr);
t_mtr			*mtr_init_z(double degr);
t_mtr			*mtr_zoom_init(double val);
void			mtr_init_zero(t_mtr *mtr);
t_mtr			*mtr_stretch_init(double sx, double sy);
void			mtr_mult(t_mlx *d, t_mtr *mtr);
void			to_start_pos(t_mlx *d);
void			ft_zoom(t_mlx *d, double val);
void			start_coord(t_mlx *d);
int				ft_error(char *str);
int				ft_color(t_mlx *d);
int				expose_hook(t_mlx *d);
void			menu_init(t_mlx *d);
void			in_center_help(t_mlx *d);
void			ft_stretch(char axis, double val, t_mlx *d);
void			start_coord_init(t_mlx *d);

#endif
