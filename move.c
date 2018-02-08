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

// void 	ft_rotate()
// {
	
// }

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
