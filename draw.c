/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:10:13 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/22 13:26:30 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		sign(double x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	return (0);
}

void		vector_init(t_mlx *data)
{
	if (data->dx > data->dy)
	{
		data->pdx = data->incx;
		data->pdy = 0;
		data->es = data->dy;
		data->el = data->dx;
	}
	else
	{
		data->pdx = 0;
		data->pdy = data->incy;
		data->es = data->dx;
		data->el = data->dy;
	}
}

void		data_init(t_coord *arr, int k, int w, t_mlx *data)
{
	data->x = arr[k].x;
	data->y = arr[k].y;
	data->color = ft_color(data);
	if (w == -1)
	{
		data->x_end = arr[k + 1].x;
		data->y_end = arr[k + 1].y;
	}
	else
	{
		data->x_end = arr[k + w].x;
		data->y_end = arr[k + w].y;
	}
	data->dx = data->x_end - data->x;
	data->dy = data->y_end - data->y;
	data->incx = sign(data->dx);
	data->incy = sign(data->dy);
	data->dx = fabs(data->dx);
	data->dy = fabs(data->dy);
	vector_init(data);
}

void		draw_line(t_mlx *data)
{
	double	err;
	int		i;

	i = 0;
	err = data->el / 2;
	mlx_pixel_put(data->mlx, data->win, data->x, data->y, data->color);
	while (i < data->el)
	{
		err -= data->es;
		if (err < 0)
		{
			err += data->el;
			data->x += data->incx;
			data->y += data->incy;
		}
		else
		{
			data->x += data->pdx;
			data->y += data->pdy;
		}
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, data->color);
		i++;
	}
}

void		line_init(t_coord *arr, t_mlx *d)
{
	int	k;
	int	line;

	k = 0;
	line = 1;
	while (k < d->el_num - 1)
	{
		if (k + 1 <= (d->elems * line) - 1)
		{
			data_init(arr, k, -1, d);
			draw_line(d);
		}
		else
			line++;
		if (k < (d->el_num - d->elems))
		{
			data_init(arr, k, d->elems, d);
			draw_line(d);
		}
		k++;
	}
}
