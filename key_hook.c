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

void	zoom_hook(int key, t_mlx *d)
{
	if (key == incr)
		ft_zoom(d, p_zoom);
	else if (key == decr)
		ft_zoom(d, n_zoom);
}

void 	rotate_hook(int key, t_mlx *d)
{
	if (key == X_UP)
		ft_rotate(d, 'x', p_alpha);
	else if (key == X_DOWN)
		ft_rotate(d, 'x', n_alpha);
	else if (key == Y_RIGHT)
		ft_rotate(d, 'y', n_alpha);
	else if (key == Y_LEFT)
		ft_rotate(d, 'y', p_alpha);
	else if (key == Z_LEFT)
		ft_rotate(d, 'z', n_alpha);
	else if (key == Z_RIGHT)
		ft_rotate(d, 'z', p_alpha);
}

void 	center_hook(int key, t_mlx *d)
{
	if (key == CENTER)
	{
		in_center(d);
		mlx_clear_window(d->mlx, d->win);
		line_init(d->coords, d->lines, d->elems, &d);
	}
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
	center_hook(key, d);
	rotate_hook(key, d);
	zoom_hook(key, d);
	return (0);
}
