/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:02:09 by proshchy          #+#    #+#             */
/*   Updated: 2018/01/13 14:02:13 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	scaling(t_mlx *d)
{
	int k;
	double res_x;
	double res_y;
	int res;

	k = -1;
	res = 1;
	res_x = width / (d->coords[d->el_num - 1].x - d->coords[0].x);
	res_y = height / (d->coords[d->el_num - 1].y - d->coords[0].y);
	
	if (res_x < res_y)
		res = res_x / 2;
	else
		res = res_y / 2;
	return (res);
}

// void 	isometric(t_mlx *d)
// {
// 	ft_rotate(d, 'x', (50 * 3.14) / 180);
// 	ft_rotate(d, 'y', (30 * 3.14) / 180);
// 	ft_rotate(d, 'z', (15 * 3.14) / 180);
// }

int 	menu_init(t_mlx *d)
{
	// d->img = mlx_new_image(d->mlx, width, height);
	// mlx_put_image_to_window(d->mlx, d->win, d->img, 100, 100);
	mlx_string_put(d->mlx, d->win, 100, 100, 0x9FBBFF, "THE MENU");
	return (0);
}

void	init_data(t_mlx *d, int **xy)
{
	t_coord coords[max_elems];
	t_coord begin[max_elems];
	t_degree *g;
	g = malloc(sizeof(t_degree));
	d->coords = coords;
	d->begin = begin;
	d->g = g;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, width, height, "Fdf");
	d->el_num = d->elems * d->lines;
	coord_in_arr(d, xy);
	in_center(d);
	ft_zoom(d, scaling(d));
	start_coord(d);
	free(xy);
	menu_init(d);
	// isometric(d);
	mlx_hook(d->win, 2, 5, key_hook, d);
	mlx_loop(d->mlx);
}

int		main(int argc, char **argv)
{
	int 	**xy;
	int 	fd;

	t_mlx *d;
	d = malloc(sizeof(t_mlx));
	if (argc == 2 && d != NULL)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			d->lines = line_count(argv[1]);
			if ((xy = (int **)malloc(sizeof(int *) * (d->lines))) == NULL)
				ft_error("Malloc failed\n");
			d->elems = read_fdf(&xy, fd);
			init_data(d, xy);
			// mlx_clear_window(d->mlx, d->win);
			mlx_expose_hook(d->win, menu_init, d);
		}
	}
	ft_error("Failed to open\n");
	return (0);
}
















