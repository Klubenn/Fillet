/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_figs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <gtristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:25:29 by gtristan          #+#    #+#             */
/*   Updated: 2019/10/07 16:14:11 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*get_map_root(void)
{
	static t_map	*map = NULL;

	if (!map)
	{
		map = (t_map *)malloc(sizeof(t_map));
		map->next_lev = NULL;
		map->next_fig = NULL;
		map->i = -1;
		map->f = 0;
	}
	return (map);
}

t_map	*new_map_fig(void)
{
	t_map *tmp;

	tmp = get_map_root();
	while (tmp->next_fig)
		tmp = tmp->next_fig;
	if (!(tmp->next_fig = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	tmp->next_fig->f = tmp->f + 1;
	tmp->next_fig->i = -1;
	tmp = tmp->next_fig;
	tmp->next_fig = NULL;
	tmp->next_lev = NULL;
	return (tmp);
}

int		include_value_into_map(int arr[][4])
{
	int		x;
	int		y;
	int		i;
	t_map	*tmp_map;

	y = -1;
	i = 0;
	if (!(tmp_map = new_map_fig()))
		return (0);
	while (++y < 4 && (x = -1))
		while (++x < 4)
			if (arr[y][x] == 1)
			{
				tmp_map->x[i] = x;
				tmp_map->y[i] = y;
				i++;
			}
	return (1);
}

void	align_figs(t_map *sh)
{
	int x;
	int y;
	int i;

	while (sh)
	{
		i = -1;
		x = ft_find_min(sh->x[0], sh->x[1], sh->x[2], sh->x[3]);
		y = ft_find_min(sh->y[0], sh->y[1], sh->y[2], sh->y[3]);
		while (++i < 4)
		{
			sh->x[i] -= x;
			sh->y[i] -= y;
		}
		sh = sh->next_fig;
	}
}
