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

t_mtr 	*mtr_zoom_init(double val)
{
	t_mtr *mtr;
	if (!(mtr = ft_memalloc(sizeof(t_mtr))))
		ft_putstr("malloc failed in mtr_zoom_init()");
	mtr->m1 = val;
	mtr->m6 = val;
	mtr->m11 = val;
	mtr->m16 = 1;
	return (mtr);
}
