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
# define x_c 640
# define y_c 360
# define space 25
# define max_elems 10000

typedef struct 	s_coord
{
	int 		x;
	int			y;
	int			z;
}				t_coord;

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
}				t_mlx;

int 	line_count(char	*argv);
int		read_fdf(int ***xy, int fd);
void	coord_in_arr(t_coord *arr, int **xy, int lines, int elems);
void	line_init(t_coord *arr, int lines, int w, t_mlx **mlx_data);

#endif
