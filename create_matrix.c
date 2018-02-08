/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:35:37 by proshchy          #+#    #+#             */
/*   Updated: 2018/01/18 13:35:39 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	line_count(char	*argv)
{
	int 	res;
	int 	fd;
	char	*str;

	fd = open(argv, O_RDONLY);
	if (fd != -1)
	{
		res = 0;
		while (get_next_line(fd, &str))
			res++;
		ft_strdel(&str);
		return (res);
	}
	else
	{
		ft_putstr("Failed to open\n");
		return (0);
	}
}

void	in_center(t_coord *arr, t_mlx *d)
{
	int k;
	int x_c;
	int y_c;

	k = 0;
	x_c = (width - arr[d->el_num - 1].x) / 2;
	y_c = (height - arr[d->el_num - 1].y) / 2;
	while (k < d->el_num)
	{
		arr[k].x = arr[k].x + x_c;
		arr[k].y = arr[k].y + y_c;
		d->center[k].x = arr[k].x;
		d->center[k].y = arr[k].y;
		k++;
	}
}

int 	in_matrix(int **xy, char **coord)
{
	int j;

	j = 0;
	while (coord[j] != '\0')
		j++;
	if (((*xy) = (int *)malloc(sizeof(int) * (j + 1))) == NULL)
		ft_putstr("Malloc failed\n");
	j = 0;
	while (coord[j] != '\0')
	{
		(*xy)[j] = ft_atoi(coord[j]);
		j++;
	}
	return (j);
}

int		read_fdf(int ***xy, int fd)
{
	char	*line;
	char	**coord;
	int 	i;
	int 	w;

	line = NULL;
	w = 0;
	i = 0;
	while (get_next_line(fd, &line))
	{
		coord = ft_strsplit(line, ' ');
		w = in_matrix(&(*xy)[i], coord);
		ft_strdel(&line);
		i++;
	}
	return(w);
}

void	coord_in_arr(t_coord *arr, int **xy, int lines, int elems)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (k < (lines * elems))
	{
		// arr[k].x = j * xy[i][j] * space;
		// arr[k].y = i * xy[i][j] * space;
		arr[k].x = j * space;
		arr[k].y = i * space;
		arr[k].z = xy[i][j];
		arr[k].w = 1;
		// printf("k = %d x =%d y = %d z =%d\n", k, arr[k].x, arr[k].y, arr[k].z);
		if (j == (elems - 1))
		{
			j = 0;
			i++;
		}
		else
			j++;
		k++;
	}
}
