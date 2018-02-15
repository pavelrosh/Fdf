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

void 	ft_color(t_mlx *d)
{
	int k;

	k = 0;
	while (k < d->el_num)
	{
		d->coords[k].color = 0x9FBBFF;
		k++;
	}
}
