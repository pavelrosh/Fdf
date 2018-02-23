/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:02:09 by proshchy          #+#    #+#             */
/*   Updated: 2018/02/22 13:16:27 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		scaling(t_mlx *d)
{
	int		k;
	double	x;
	double	y;

	k = 0;
	in_center_help(d);
	d->center->max_x = d->center->max_x - d->center->min_x;
	d->center->max_y = d->center->max_y - d->center->min_y;
	x = WIDTH / (d->center->max_x * 1.5);
	y = HEIGHT / (d->center->max_y * 1.5);
	if (x > y)
		return (x);
	return (y);
}

void		isometric(t_mlx *d)
{
	ft_rotate(d, 'x', (50 * 3.14) / 180);
	ft_rotate(d, 'y', (30 * 3.14) / 180);
	ft_rotate(d, 'z', (15 * 3.14) / 180);
}

int			expose_hook(t_mlx *d)
{
	mlx_clear_window(d->mlx, d->win);
	menu_init(d);
	line_init(d->coords, d);
	return (0);
}

void		init_data(t_mlx *d, int **xy)
{
	t_coord		coords[MAX_ELEMS];
	t_coord		begin[MAX_ELEMS];
	t_degree	*g;

	if (!(g = malloc(sizeof(t_degree))))
		ft_error("Malloc failed in t_degree *g\n");
	d->coords = coords;
	d->begin = begin;
	d->g = g;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Fdf");
	d->el_num = d->elems * d->lines;
	d->color = 0x9FBBFF;
	coord_in_arr(d, xy);
	start_coord(d);
	isometric(d);
	ft_zoom(d, scaling(d));
	in_center(d);
	start_coord(d);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_hook(d->win, 2, 5, key_hook, d);
	mlx_loop(d->mlx);
}

int			main(int argc, char **argv)
{
	int		**xy;
	int		fd;
	t_mlx	*d;

	d = ft_memalloc(sizeof(t_mlx));
	if (!(d->center = ft_memalloc(sizeof(t_center))) || !d)
		ft_error("Malloc failed in d->center\n");
	if (argc == 2 && d != NULL)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			d->lines = line_count(argv[1]);
			if ((xy = (int **)malloc(sizeof(int *) * (d->lines))) == NULL)
				ft_error("Malloc failed\n");
			d->elems = read_fdf(&xy, fd);
			init_data(d, xy);
		}
	}
	ft_error("Failed to open\n");
	return (0);
}
