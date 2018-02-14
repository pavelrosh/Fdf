/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:15:08 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/09 17:15:09 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	start_coord_init(t_mlx *d)
{
	int k;

	k = -1;
	while (k++ < d->el_num)
	{
		d->coords[k].x = d->begin[k].x;
		d->coords[k].y = d->begin[k].y;
		d->coords[k].z = d->begin[k].z;
	}
}

void 	ft_rotate(t_mlx *d, char axis, float degr)
{
	static float degr_x = 0;
	static float degr_y = 0;
	static float degr_z = 0;
	t_mtr *mtr_x;
	t_mtr *mtr_y;
	t_mtr *mtr_z;
	start_coord_init(d);
	to_win_corn(d);

	if (axis == 'x')
		degr_x += degr;
	else if (axis == 'y')
		degr_y += degr;
	else
		degr_z += degr;

	if (degr_x != 0)
	{
		mtr_x = mtr_init_x(degr_x);
		mtr_mult(d, mtr_x);
		free(mtr_x);
	}
	if (degr_y != 0)
	{
		mtr_y = mtr_init_y(degr_y);
		mtr_mult(d, mtr_y);
		free(mtr_y);
	}
	if (degr_z != 0)
	{
		mtr_z = mtr_init_z(degr_z);
		mtr_mult(d, mtr_z);
		free(mtr_z);
	}
	to_start_pos(d);
	mlx_clear_window(d->mlx, d->win);
	line_init(d->coords, d->lines, d->elems, &d);
}






















