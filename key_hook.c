/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:36:42 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/22 13:10:38 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_hook(int key, t_mlx *d)
{
	if (key == INCR)
		ft_zoom(d, P_ZOOM);
	else if (key == DECR)
		ft_zoom(d, N_ZOOM);
}

void	rotate_hook(int key, t_mlx *d)
{
	if (key == X_UP)
		ft_rotate(d, 'x', P_ALPHA);
	else if (key == X_DOWN)
		ft_rotate(d, 'x', N_ALPHA);
	else if (key == Y_RIGHT)
		ft_rotate(d, 'y', N_ALPHA);
	else if (key == Y_LEFT)
		ft_rotate(d, 'y', P_ALPHA);
	else if (key == Z_LEFT || key == 83)
		ft_rotate(d, 'z', N_ALPHA);
	else if (key == Z_RIGHT || key == 85)
		ft_rotate(d, 'z', P_ALPHA);
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

void	stretch_hook(int key, t_mlx *d)
{
	if (key == PSX)
		ft_stretch('x', P_STRETCH, d);
	else if (key == PSY)
		ft_stretch('y', P_STRETCH, d);
	if (key == NSX)
		ft_stretch('x', N_STRETCH, d);
	else if (key == NSY)
		ft_stretch('y', N_STRETCH, d);
}

int		key_hook(int key, t_mlx *d)
{
	if (key == ESC)
		exit(0);
	if (key == CENTER)
	{
		in_center(d);
		start_coord(d);
	}
	stretch_hook(key, d);
	move_hook(key, d);
	rotate_hook(key, d);
	zoom_hook(key, d);
	expose_hook(d);
	return (0);
}
