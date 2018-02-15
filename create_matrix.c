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
		ft_error("Failed to open\n");
	return (0);
}

void	in_center(t_mlx *d)
{
	int k;

	k = -1;
	if (!(d->center = ft_memalloc(sizeof(t_center))))
		ft_error("Malloc failed in in_center()\n");
	d->center->x_c = (d->coords[d->el_num - 1].x + d->coords[0].x) / 2;
	d->center->y_c = (d->coords[d->el_num - 1].y + d->coords[0].y) / 2;
	d->center->c_x = (width / 2) - d->center->x_c;
	d->center->c_y = (height / 2) - d->center->y_c;
	while (k++ < d->el_num)
	{
		d->coords[k].x = d->coords[k].x + d->center->c_x;
		d->coords[k].y = d->coords[k].y + d->center->c_y;
	}
}

int 	in_matrix(int **xy, char **coord)
{
	int j;

	j = 0;
	while (coord[j] != '\0')
		j++;
	if (((*xy) = (int *)malloc(sizeof(int) * (j + 1))) == NULL)
		ft_error("Malloc failed in in_matrix()\n");
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
	close(fd);
	return(w);
}

void	coord_in_arr(t_mlx *d, int **xy)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (k < d->el_num)
	{
		d->coords[k].x = j;
		d->coords[k].y = i;
		d->coords[k].z = xy[i][j];
		// printf("k = %d x =%f y = %f z =%f\n", k, d->coords[k].x, d->coords[k].y, d->coords[k].z);
		// printf("k = %d x =%f y = %f z =%f\n", k, d->begin[k].x, d->begin[k].y, d->begin[k].z);
		if (j == (d->elems - 1))
		{
			j = 0;
			i++;
		}
		else
			j++;
		k++;
	}
}














