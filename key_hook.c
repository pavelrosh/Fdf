/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:36:42 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/07 15:36:44 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void 	rotate_hook(int key, t_mlx *d)
// {
// 	if (key == Z_RIGHT)
// 		ft_rotate();
// 	else if (key == Z_LEFT)
// 		ft_rotate();
// }

// void 	in_center_hook(int key, t_mlx *d)
// {
// 	int k;

// 	k = -1;
// 	if (key == CENTER)
// 	{
// 		while (k++ < d->el_num)
// 		{
// 			d->coords[k].x = d->center[k].x;
// 			d->coords[k].y = d->center[k].y;
// 		}
// 		mlx_clear_window(d->mlx, d->win);
// 		line_init(d->coords, d->lines, d->elems, &d);
// 	}
// }

void 	in_center_hook()
{
	
}

void 	esc_hook(int key, t_mlx *d)
{
	if (key == ESC)
	{
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
}

void	move_hook(int key, t_mlx *d)
{
	if (key == UP)
		ft_move(d, 0, -1);
	else if (key == DOWN)
		ft_move(d, 0, 1);
	else if (key == RIGHT)
		ft_move(d, 1, 0);
	else if (key == LEFT)
		ft_move(d, -1, 0);
}

int 	key_hook(int key, t_mlx *d)
{
	esc_hook(key, d);
	move_hook(key, d);
	// in_center_hook(key, d);
	rotate_hook(key, d);
	return (0);
}
