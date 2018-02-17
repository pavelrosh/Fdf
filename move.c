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
	start_coord(d);
}

void 	to_win_corn(t_mlx *d)
{
	int k;

	k = 0;
	d->center->x_c = (d->coords[d->el_num - 1].x + d->coords[0].x) / 2;
	d->center->y_c = (d->coords[d->el_num - 1].y + d->coords[0].y) / 2;
	while (k < d->el_num)
	{
		d->coords[k].x -= d->center->x_c;
		d->coords[k].y -= d->center->y_c;
		k++;
	}
}

void 	to_start_pos(t_mlx *d)
{
	int k;

	k = 0;
	while (k < d->el_num)
	{
		d->coords[k].x += d->center->x_c;
		d->coords[k].y += d->center->y_c;
		k++;
	}
}

void 	ft_zoom(t_mlx *d, double val)
{
	t_mtr *mtr;
	mtr = mtr_zoom_init(val);
	to_win_corn(d);
	mtr_mult(d, mtr);
	to_start_pos(d);
	start_coord(d);
	free(mtr);
}

void	mtr_mult(t_mlx *d, t_mtr *mtr)
{
	int k;
	double x;
	double y;
	double z;

	k = 0;
	while (k < d->el_num)
	{
		x = d->coords[k].x;
		y = d->coords[k].y;
		z = d->coords[k].z;
		d->coords[k].x = x * mtr->m1 + y * mtr->m4 + z * mtr->m7;
		d->coords[k].y = x * mtr->m2 + y * mtr->m5 + z * mtr->m8;
		d->coords[k].z = x * mtr->m3 + y * mtr->m6 + z * mtr->m9;
		k++;
	}
}








