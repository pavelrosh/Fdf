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

int		main(int argc, char **argv)
{
	int 	**xy;
	int 	fd;

	t_coord coords[max_elems];
	t_mlx *mlx_d;
	mlx_d = malloc(sizeof(t_mlx));
	mlx_d->coords = coords;
	if (argc == 2 && mlx_d != NULL)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			mlx_d->lines = line_count(argv[1]);
			if ((xy = (int **)malloc(sizeof(int *) * (mlx_d->lines))) == NULL)
			{
				ft_putstr("Malloc failed\n");
				return (0);
			}
			mlx_d->elems = read_fdf(&xy, fd);
			coord_in_arr(&coords[0], xy, mlx_d->lines, mlx_d->elems);
			mlx_d->mlx = mlx_init();
			mlx_d->win = mlx_new_window(mlx_d->mlx, width, height, "Fdf");
			mlx_d->el_num = mlx_d->elems * mlx_d->lines;
			in_center(mlx_d);
			line_init(coords, mlx_d->lines, mlx_d->elems, &mlx_d);
			mlx_hook(mlx_d->win, 2, 5, key_hook, mlx_d);
			mlx_loop(mlx_d->mlx);
			close(fd);
		}
		else
			ft_putstr("Failed to open\n");
	}
	return (0);
}
















