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

void 	ft_rotate(t_mlx *d, char axis, double degr)
{
	t_mtr *mtr;
	to_win_corn(d);
	if (axis == 'x')
		mtr = mtr_init_x(degr);
	else if (axis == 'y')
		mtr = mtr_init_y(degr);
	else
		mtr = mtr_init_z(degr);
	mtr_mult(d, mtr);
	in_center(d);
	mlx_clear_window(d->mlx, d->win);
	line_init(d->coords, d->lines, d->elems, &d);
	free(mtr);
}

t_mtr 	*mtr_init_x(double degr)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_putstr("malloc failed in mtr_init()");
	mtr->m1 = 1;
	mtr->m6 = cos(degr);
	// printf("m6=%f\n", mtr->m6);
	mtr->m7 = sin(degr);
	// printf("m7=%f\n", mtr->m7);
	mtr->m10 = -sin(degr);
	// printf("m10=%f\n", mtr->m10);
	mtr->m11 = cos(degr);
	// printf("m11=%f\n", mtr->m11);
	mtr->m16 = 1;
	return (mtr);
}

t_mtr 	*mtr_init_y(double degr)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_putstr("malloc failed in mtr_init()");
	mtr->m1 = cos(degr);
	mtr->m3 = sin(degr);
	mtr->m6 = 1;
	mtr->m9 = -sin(degr);
	mtr->m11 = cos(degr);
	mtr->m16 = 1;
	return (mtr);
}

t_mtr 	*mtr_init_z(double degr)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_putstr("malloc failed in mtr_init()");
	mtr->m1 = cos(degr);
	mtr->m2 = sin(degr);
	mtr->m5 = -sin(degr);
	mtr->m6 = cos(degr);
	mtr->m11 = 1;
	mtr->m16 = 1;
	return (mtr);
}

void	mtr_mult(t_mlx *d, t_mtr *mtr)
{
	int k;

	k = 0;
	while (k < d->el_num)
	{
		d->coords[k].x = d->coords[k].x * mtr->m1 + d->coords[k].y * mtr->m5 + d->coords[k].z * mtr->m9;
		d->coords[k].y = d->coords[k].x * mtr->m2 + d->coords[k].y * mtr->m6 + d->coords[k].z * mtr->m10;
		d->coords[k].z = d->coords[k].x * mtr->m3 + d->coords[k].y * mtr->m7 + d->coords[k].z * mtr->m11;
		// printf("x =%d y=%d z=%d\n", d->coords[k].x, d->coords[k].y, d->coords[k].z);
		k++;
	}
}
