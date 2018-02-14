/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:14:11 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/10 14:14:15 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	mtr_init_zero(t_mtr *mtr)
{
	mtr->m1 = 0;
	mtr->m2 = 0;
	mtr->m3 = 0;
	mtr->m4 = 0;
	mtr->m5 = 0;
	mtr->m6 = 0;
	mtr->m7 = 0;
	mtr->m8 = 0;
	mtr->m9 = 0;
	mtr->m10 = 0;
	mtr->m11 = 0;
	mtr->m12 = 0;
	mtr->m13 = 0;
	mtr->m14 = 0;
	mtr->m15 = 0;
	mtr->m16 = 0;
}

t_mtr 	*mtr_zoom_init(double val)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_error("malloc failed in mtr_zoom_init()");
	mtr_init_zero(mtr);
	mtr->m1 = val;
	mtr->m6 = val;
	mtr->m11 = val;
	mtr->m16 = 1;
	return (mtr);
}

t_mtr 	*mtr_init_x(double degr)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_putstr("malloc failed in mtr_init()");
	mtr_init_zero(mtr);
	mtr->m1 = 1;
	mtr->m6 = cos(degr);
	mtr->m7 = sin(degr);
	mtr->m10 = -sin(degr);
	mtr->m11 = cos(degr);
	mtr->m16 = 1;
	return (mtr);
}

t_mtr 	*mtr_init_y(double degr)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_error("malloc failed in mtr_init()");
	mtr_init_zero(mtr);
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
		ft_error("malloc failed in mtr_init()");
	mtr_init_zero(mtr);
	mtr->m1 = cos(degr);
	mtr->m2 = sin(degr);
	mtr->m5 = -sin(degr);
	mtr->m6 = cos(degr);
	mtr->m11 = 1;
	mtr->m16 = 1;
	return (mtr);
}




