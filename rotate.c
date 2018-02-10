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

void 	ft_rotate(t_mlx *d, char axis, float degr)
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
	vect_normin(d);
	to_start_pos(d);
	mlx_clear_window(d->mlx, d->win);
	line_init(d->coords, d->lines, d->elems, &d);
	free(mtr);
}

t_mtr 	*mtr_init_x(float degr)
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

t_mtr 	*mtr_init_y(float degr)
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

t_mtr 	*mtr_init_z(float degr)
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























