/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:48:25 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/22 13:34:58 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_coord(t_mlx *d)
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

int		ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	in_center_help(t_mlx *d)
{
	int k;

	k = 0;
	d->center->max_x = -10000;
	d->center->max_y = -10000;
	d->center->min_x = 10000;
	d->center->min_y = 10000;
	while (k < (d->el_num - 1))
	{
		if (d->center->max_x < d->coords[k + 1].x)
			d->center->max_x = d->coords[k + 1].x;
		if (d->center->max_y < d->coords[k + 1].y)
			d->center->max_y = d->coords[k + 1].y;
		if (d->center->min_x > d->coords[k + 1].x)
			d->center->min_x = d->coords[k + 1].x;
		if (d->center->min_y > d->coords[k + 1].y)
			d->center->min_y = d->coords[k + 1].y;
		k++;
	}
}

void	menu_init(t_mlx *d)
{
	mlx_string_put(d->mlx, d->win, 40, 50, 0xF13636, "[ esc ]");
	mlx_string_put(d->mlx, d->win, 90, 75, 0xF76A40, "[ ^ ]");
	mlx_string_put(d->mlx, d->win, 40, 75, 0x40CCF7, "[ + ]");
	mlx_string_put(d->mlx, d->win, 40, 100, 0xF76A40, "[ < ]");
	mlx_string_put(d->mlx, d->win, 90, 100, 0xF76A40, "[ V ]");
	mlx_string_put(d->mlx, d->win, 140, 75, 0x40CCF7, "[ - ]");
	mlx_string_put(d->mlx, d->win, 140, 100, 0xF76A40, "[ > ]");
	mlx_string_put(d->mlx, d->win, 40, 125, 0xF76A40, "[    space    ]");
	mlx_string_put(d->mlx, d->win, 40, 170, 0xB74DE4, "[ 7 ]");
	mlx_string_put(d->mlx, d->win, 90, 170, 0xE4A839, "[ 8 ]");
	mlx_string_put(d->mlx, d->win, 140, 170, 0xB74DE4, "[ 9 ]");
	mlx_string_put(d->mlx, d->win, 40, 195, 0x5FE42F, "[ 4 ]");
	mlx_string_put(d->mlx, d->win, 140, 195, 0x5FE42F, "[ 6 ]");
	mlx_string_put(d->mlx, d->win, 40, 220, 0xB74DE4, "[ 1 ]");
	mlx_string_put(d->mlx, d->win, 90, 220, 0xE4A839, "[ 2 ]");
	mlx_string_put(d->mlx, d->win, 140, 220, 0xB74DE4, "[ 3 ]");
	mlx_string_put(d->mlx, d->win, 40, 250, 0x40CCF7, "ZOOM");
	mlx_string_put(d->mlx, d->win, 40, 275, 0xF76A40, "MOVE");
	mlx_string_put(d->mlx, d->win, 40, 300, 0xB74DE4, "Z ROTATION");
	mlx_string_put(d->mlx, d->win, 40, 325, 0xE4A839, "Y ROTATION");
	mlx_string_put(d->mlx, d->win, 40, 350, 0x5FE42F, "X ROTATION");
}

void	ft_stretch(char axis, double val, t_mlx *d)
{
	t_mtr *mtr;

	to_win_corn(d);
	if (axis == 'x')
	{
		mtr = mtr_stretch_init(val, 1);
		mtr_mult(d, mtr);
		free(mtr);
	}
	else
	{
		mtr = mtr_stretch_init(1, val);
		mtr_mult(d, mtr);
		free(mtr);
	}
	to_start_pos(d);
	start_coord(d);
}
