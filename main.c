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

// int 	menu_init(t_mlx *d)
// {
// 	mlx_string_put(d->mlx, d->win, 100, 100, 0x00cc00, "move       : arrows");
// 	return (0);
// }

void 	start_coord(t_mlx *d)
{
	int k;

	k = -1;
	while (k++ < d->el_num)
	{
		d->begin[k].x = d->coords[k].x;
		d->begin[k].y = d->coords[k].y;
		d->begin[k].z = d->coords[k].z;
	}
}

int 	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		main(int argc, char **argv)
{
	int 	**xy;
	int 	fd;

	t_coord coords[max_elems];
	t_coord begin[max_elems];
	t_mlx *d;
	d = malloc(sizeof(t_mlx));
	d->coords = coords;
	d->begin = begin;
	if (argc == 2 && d != NULL)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			d->lines = line_count(argv[1]);
			if ((xy = (int **)malloc(sizeof(int *) * (d->lines))) == NULL)
				ft_error("Malloc failed\n");
			d->elems = read_fdf(&xy, fd);
			d->el_num = d->elems * d->lines;
			coord_in_arr(d, xy);
			d->mlx = mlx_init();
			d->win = mlx_new_window(d->mlx, width, height, "Fdf");
			in_center(d);
			ft_zoom(d, 35);
			start_coord(d);
			// mlx_expose_hook(mlx_d->win, menu_init, mlx_d);
			mlx_hook(d->win, 2, 5, key_hook, d);
			mlx_loop(d->mlx);
			close(fd);
		}
	}
	ft_error("Failed to open\n");
	return (0);
}
















