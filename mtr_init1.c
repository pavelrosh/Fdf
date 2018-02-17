/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:00:43 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/15 16:00:48 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtr 	*mtr_stretch_init(double sx, double sy)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_error("malloc failed in mtr_zoom_init()");
	mtr_init_zero(mtr);
	mtr->m1 = sx;
	mtr->m5 = sy;
	mtr->m9 = 1;
	return (mtr);
}