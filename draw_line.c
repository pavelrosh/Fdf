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

void	draw_h_line(t_coord *arr, int k, t_mlx *mlx_data)
{
	int dx;
	int dy;
	int x;
	int y;
	int x1;
	int y1;

	x = arr[k].x;
	x1 = arr[k + 1].x;
	y = arr[k].y;
	y1 = arr[k + 1].y;
	dx = abs(x - x1);
	dy = abs(y - y1);

	// printf("%d %d %d %d\n",x, x1, dx, dy);
	// printf("%d %d\n",arr[k + 1].x, arr[k + 1].y);
	mlx_pixel_put(mlx_data->mlx, mlx_data->win, x, y, 0xFFFFFF);
	if (dy <= dx)
	{
		while (x <= x1)
		{
			x++;
			y = y + ((x - arr[k].x) * ((y1 - y) / (x1 - arr[k].x)));
			mlx_pixel_put(mlx_data->mlx, mlx_data->win, x, y, 0xFFFFFF);
			// printf("H_LINE IF x: %d y: %d\n",x, y);
		}
	}
	else
	{
		while (y <= y1)
		{
			y++;
			x = x + ((y - arr[k].y) * ((x1 - x) / (y1 - arr[k].y)));
			mlx_pixel_put(mlx_data->mlx, mlx_data->win, x, y, 0xFFFFFF);
			// printf("H_LINE ELSE x: %d y: %d\n",x, y);
		}
	}
	// printf("draw_H_line k: %d\n", k);
}

// 0 0 
// 5 10

void	draw_v_line(t_coord *arr, int k, int w, t_mlx *mlx_data)
{
	int dx;
	int dy;
	int x;
	int y;
	int x1;
	int y1;

	x = arr[k].x;
	x1 = arr[k + w].x;
	y = arr[k].y;
	y1 = arr[k + w].y;
	dx = abs(x - x1);
	dy = abs(y - y1);

	mlx_pixel_put(mlx_data->mlx, mlx_data->win, x, y, 0xFFFFFF);
	if (dy <= dx)
	{
		while (x <= x1)
		{
			x++;
			y = y + ((x - arr[k].x) * ((y1 - y) / (x1 - arr[k].x)));
			mlx_pixel_put(mlx_data->mlx, mlx_data->win, x, y, 0xFFFFFF);
			// printf("V_LINE ELSE x: %d y: %d\n",x, y);
		}
	}
	else
	{
		while (y <= y1)
		{
			y++;
			x = x + ((y - arr[k].y) * ((x1 - x) / (y1 - arr[k].y)));
			mlx_pixel_put(mlx_data->mlx, mlx_data->win, x, y, 0xFFFFFF);
			// printf("V_LINE ELSE x: %d y: %d\n",x, y);
		}
	}
	// printf("draw_v_line k: %d\n", k);
}

void	line_init(t_coord *arr, int lines, int w, t_mlx **mlx_data)
{
	int 	i;
	int 	k;
	int 	index;
	int 	tmp;
	int 	w_tmp;

	i = 0;
	index = lines * w;
	tmp = index;
	w_tmp = 0;
	k = 0;
	while (index > 0)
	{
		if (w_tmp < (w - 1))
		{
			draw_h_line(arr, k, *mlx_data);
			w_tmp++;
			// printf("IF :%d %d\n", arr[k].x, arr[k + 1].x);
		}
		if (w_tmp >= (w - 1))
				w_tmp = 0;
		if ((k + w) <= tmp)
		{
			// printf("ELSE %d %d\n", arr[k].x, arr[k + w].x);
			draw_v_line(arr, k, w, *mlx_data);
		}
		// printf("INDEX :%d\n", index);
		index--;
		k++;
	}
}
