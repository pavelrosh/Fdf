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
	line_init(d->coords, d->lines, d->elems, &d);
}

void 	to_win_corn(t_mlx *d)
{
	int k;

	k = -1;
	if (!(d->center = ft_memalloc(sizeof(t_center))))
		ft_putstr("Malloc failed in to_win_corn()\n");
	d->center->x_c = (d->coords[d->el_num - 1].x + d->coords[0].x) / 2;
	d->center->y_c = (d->coords[d->el_num - 1].y + d->coords[0].y) / 2;
	while (k < d->el_num)
	{
		d->coords[k].x -= d->center->x_c;
		d->coords[k].y -= d->center->y_c;
		k++;
	}
}
