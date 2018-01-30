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

void	turn_coord(t_coord *arr, int elems)
{
	int k;

	k = 0;
	while (k < elems)
	{
		arr[k].x = arr[k].x * cos(270) - arr[k].y * sin(270);
		arr[k].y = arr[k].x * sin(270) + arr[k].y * cos(270);
		// printf("%d %d %d\n", k, arr[k].x, arr[k].y);
		k++;
	}
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int 	**xy;
	int 	fd;
	int 	lines;
	int 	elems;
	int 	elem_num;

	t_coord arr[max_elems];
	t_mlx *mlx_data;
	mlx_data = malloc(sizeof(t_mlx));
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			lines = line_count(argv[1]);
			xy = (int **)malloc(sizeof(int *) * (lines));
			elems = read_fdf(&xy, fd);
			coord_in_arr(&arr[0], xy, lines, elems);
			mlx = mlx_init();
			win = mlx_new_window(mlx, width, height, "Fdf-test");
			mlx_data->mlx = mlx;
			mlx_data->win = win;
			elem_num = elems * lines;
			turn_coord(arr, elem_num);
			line_init(arr, lines, elems, &mlx_data);
			mlx_loop(mlx);
			close(fd);
		}
	}
	return (0);
}






















