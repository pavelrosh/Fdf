/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:10:13 by proshchy          #+#    #+#             */
/*   Updated: 2018/01/27 15:10:16 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double 	sign(double x) 
{
	return (x > 0) ? 1 : (x < 0) ? -1 : 0;
}

void 	vector_init(t_mlx *data)
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

void 	data_init(t_coord *arr, int k, int w, t_mlx *data)
{
	data->x = arr[k].x;
	data->y = arr[k].y;
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

void 	draw_line(t_mlx *data)
{
	double err;
	int i;

	i = 0;
	err = data->el / 2;
	mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0xFFFFFF);
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
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0xFFFFFF);
		i++;
	}
}

void	line_init(t_coord *arr, int lines, int w, t_mlx **data)
{
	int 	k;
	int 	points;
	int 	line;

	points = lines * w;
	k = 0;
	line = 1;
	while (k < points - 1)
	{
		if (k + 1 <= (w * line) - 1)
		{
			data_init(arr, k, -1, *data);
			draw_line(*data);
		}
		else
			line++;
		if (k < (points - w))
		{
			data_init(arr, k, w, *data);
			draw_line(*data);
		}
		k++;
	}
}
