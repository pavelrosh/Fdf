/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:25:02 by proshchy          #+#    #+#             */
/*   Updated: 2018/01/17 18:25:05 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"

# define width 1280
# define height 720
# define p_zoom 1.1
# define n_zoom 0.9
# define max_elems 10000

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
# define incr 69
# define decr 78
# define CENTER 49

# define step 50
# define p_alpha GR(10)
# define n_alpha -GR(10)
# define GR(x) (x * 3.14) / 180 

typedef struct 	s_coord
{
	double 		x;
	double		y;
	double		z;
	int 		w;
}				t_coord;

typedef struct 	s_center
{
	double 		x_c;
	double 		y_c;
	double 		c_x;
	double 		c_y;
}				t_center;

typedef struct 	s_mtr
{
	double 		m1;
	double 		m2;
	double 		m3;
	double 		m4;
	double 		m5;
	double 		m6;
	double 		m7;
	double 		m8;
	double 		m9;
	double 		m10;
	double 		m11;
	double 		m12;
	double 		m13;
	double 		m14;
	double 		m15;
	double 		m16;
} 				t_mtr;

typedef struct 	s_mlx
{
	void		*mlx;
	void		*win;
	double 		dx;
	double 		dy;
	double 		x;
	double 		y;
	double 		x_end;
	double 		y_end;
	double 		incx;
	double 		incy;
	double 		pdx;
	double 		pdy;
	double 		es;
	double 		el;
	int 		el_num;
	int 		lines;
	int 		elems;
	t_coord 	*coords;
	t_center 	*center;
}				t_mlx;

int 	line_count(char	*argv);
int		read_fdf(int ***xy, int fd);
void	coord_in_arr(t_coord *arr, int **xy, int lines, int elems);
void	line_init(t_coord *arr, int lines, int w, t_mlx **mlx_data);
void	in_center(t_mlx *d);
int 	key_hook(int key, t_mlx *d);
void	ft_move(t_mlx *d, int dx, int dy);
void 	to_win_corn(t_mlx *d);
void 	ft_rotate(t_mlx *d, char axis, float degr);
t_mtr 	*mtr_init_x(float degr);
t_mtr 	*mtr_init_y(float degr);
t_mtr 	*mtr_init_z(float degr);
void	mtr_mult(t_mlx *d, t_mtr *mtr);
void 	to_start_pos(t_mlx *d);
void 	ft_zoom(t_mlx *d, double val);
t_mtr 	*mtr_zoom_init(double val);
void 	vect_normin(t_mlx *d);
#endif
