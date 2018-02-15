/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:48:25 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/15 11:49:28 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void 	start_coord(t_mlx *d)
{
	int k;

	k = 0;
	while (k < d->el_num)
	{
		d->begin[k].x = d->coords[k].x;
		d->begin[k].y = d->coords[k].y;
		d->begin[k].z = d->coords[k].z;
		k++;
	}
	d->g->degr_x = 0;
	d->g->degr_y = 0;
	d->g->degr_z = 0;
}

int 	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}
