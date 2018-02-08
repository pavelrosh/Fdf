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
# define space 25
# define max_elems 10000
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define Z_LEFT 89
# define Z_RIGHT 92
# define step 50
# define CENTER 49

typedef struct 	s_coord
{
	int 		x;
	int			y;
	int			z;
	int 		w;
}				t_coord;

typedef struct 	s_mtr
{
	int 		m1;
	int 		m2;
	int 		m3;
	int 		m4;
	int 		m5;
	int 		m6;
	int 		m7;
	int 		m8;
	int 		m9;
} 				t_mtr;

typedef struct 	s_mlx
{
	void		*mlx;
	void		*win;
	int 		dx;
	int 		dy;
	int 		x;
	int 		y;
	int 		x_end;
	int 		y_end;
	int 		incx;
	int 		incy;
	int 		pdx;
	int 		pdy;
	int 		es;
	int 		el;
	int 		el_num;
	int 		lines;
	int 		elems;
	int 		x_c;
	int 		y_c;
	t_coord 	*coords;
	t_coord 	*center;
}				t_mlx;

int 	line_count(char	*argv);
int		read_fdf(int ***xy, int fd);
void	coord_in_arr(t_coord *arr, int **xy, int lines, int elems);
void	line_init(t_coord *arr, int lines, int w, t_mlx **mlx_data);
void	in_center(t_coord *arr, t_mlx *d);
int 	key_hook(int key, t_mlx *d);
void	ft_move(t_mlx *d, int dx, int dy);
#endif
