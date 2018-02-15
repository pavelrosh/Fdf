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
}

t_mtr 	*mtr_zoom_init(double val)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_error("malloc failed in mtr_zoom_init()");
	mtr_init_zero(mtr);
	mtr->m1 = val;
	mtr->m5 = val;
	mtr->m9 = val;
	return (mtr);
}

t_mtr 	*mtr_init_x(double degr)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_putstr("malloc failed in mtr_init()");
	mtr_init_zero(mtr);
	mtr->m1 = 1;
	mtr->m5 = cos(degr);
	mtr->m6 = sin(degr);
	mtr->m8 = -sin(degr);
	mtr->m9 = cos(degr);
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
	mtr->m5 = 1;
	mtr->m7 = -sin(degr);
	mtr->m9 = cos(degr);
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
	mtr->m4 = -sin(degr);
	mtr->m5 = cos(degr);
	mtr->m9 = 1;
	return (mtr);
}




