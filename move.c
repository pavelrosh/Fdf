/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:47:40 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/08 15:47:41 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_mlx *d, int dx, int dy)
{
	int k;

	k = 0;
	while (k < d->el_num)
	{
		d->coords[k].x = d->coords[k].x + (dx * step);
		d->coords[k].y = d->coords[k].y + (dy * step);
		k++;
	}
	mlx_clear_window(d->mlx, d->win);
	start_coord(d);
	line_init(d->coords, d->lines, d->elems, &d);
}

void 	to_win_corn(t_mlx *d)
{
	int k;

	k = -1;
	if (!(d->center = ft_memalloc(sizeof(t_center))))
		ft_error("Malloc failed in to_win_corn()\n");
	d->center->x_c = (d->coords[d->el_num - 1].x + d->coords[0].x) / 2;
	d->center->y_c = (d->coords[d->el_num - 1].y + d->coords[0].y) / 2;
	while (k++ < d->el_num)
	{
		d->coords[k].x -= d->center->x_c;
		d->coords[k].y -= d->center->y_c;
	}
}

void 	to_start_pos(t_mlx *d)
{
	int k;

	k = -1;
	while (k++ < d->el_num)
	{
		d->coords[k].x += d->center->x_c;
		d->coords[k].y += d->center->y_c;
	}
}

void 	ft_zoom(t_mlx *d, double val)
{
	t_mtr *mtr;
	mtr = mtr_zoom_init(val);
	to_win_corn(d);
	mtr_mult(d, mtr);
	mlx_clear_window(d->mlx, d->win);
	to_start_pos(d);
	start_coord(d);
	line_init(d->coords, d->lines, d->elems, &d);
	free(mtr);
}

void	mtr_mult(t_mlx *d, t_mtr *mtr)
{
	int k;

	k = -1;
	while (k++ < d->el_num)
	{
		d->coords[k].x = d->coords[k].x * mtr->m1 + d->coords[k].y * mtr->m5 + d->coords[k].z * mtr->m9 + d->coords[k].w * mtr->m13;
		d->coords[k].y = d->coords[k].x * mtr->m2 + d->coords[k].y * mtr->m6 + d->coords[k].z * mtr->m10 + d->coords[k].w * mtr->m14;
		d->coords[k].z = d->coords[k].x * mtr->m3 + d->coords[k].y * mtr->m7 + d->coords[k].z * mtr->m11 + d->coords[k].w * mtr->m15;
		// printf("%f\n", d->coords[k].z);
		// d->coords[k].x = d->coords[k].x * mtr->m1 + d->coords[k].y * mtr->m2 + d->coords[k].z * mtr->m3 + d->coords[k].w * mtr->m4;
		// d->coords[k].y = d->coords[k].x * mtr->m5 + d->coords[k].y * mtr->m6 + d->coords[k].z * mtr->m7 + d->coords[k].w * mtr->m8;
		// d->coords[k].z = d->coords[k].x * mtr->m9 + d->coords[k].y * mtr->m10 + d->coords[k].z * mtr->m11 + d->coords[k].w * mtr->m12;
		// printf("x =%d y=%d z=%d\n", d->coords[k].x, d->coords[k].y, d->coords[k].z);
	}
}









