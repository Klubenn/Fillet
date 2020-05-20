/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_figs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <gtristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:47:49 by gtristan          #+#    #+#             */
/*   Updated: 2019/10/07 19:51:40 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_figs1(int pole_size, int **map)
{
	int a;
	int b;

	a = -1;
	while (++a < pole_size)
	{
		b = -1;
		while (++b < pole_size)
		{
			if (map[a][b] == 0)
				ft_putchar('.');
			else
				ft_putchar(map[a][b]);
		}
		ft_putchar('\n');
	}
	while (--b >= 0)
		free(map[b]);
	free(map);
}

void	print_figs(t_map *shape, int pole_size)
{
	int **map;
	int a;
	int b;

	a = -1;
	map = (int **)malloc(sizeof(int *) * pole_size);
	while (++a < pole_size)
	{
		map[a] = (int *)malloc(sizeof(int) * pole_size);
		b = -1;
		while (++b < pole_size)
			map[a][b] = 0;
	}
	while (shape)
	{
		a = -1;
		while (shape->i != -1)
			shape = shape->next_lev;
		while (++a < 4)
			map[shape->y[a]][shape->x[a]] = shape->f + 64;
		shape = shape->next_fig;
	}
	print_figs1(pole_size, map);
}
