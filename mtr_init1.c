/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:00:43 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/22 15:39:32 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtr	*mtr_stretch_init(double sx, double sy)
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

int		ft_color(t_mlx *d)
{
	if (d->color == 0x9FBBFF)
		return (0xEE873E);
	else if (d->color == 0xEE873E)
		return (0xA8D70D);
	else if (d->color == 0xA8D70D)
		return (0xE10909);
	else if (d->color == 0xE10909)
		return (0x09E1DD);
	else if (d->color == 0x09E1DD)
		return (0xC809E1);
	return (0x9FBBFF);
}
