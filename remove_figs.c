/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_figs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <gtristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:40:58 by gtristan          #+#    #+#             */
/*   Updated: 2019/10/09 16:19:09 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*select_positions(t_map *shape)
{
	if (!shape)
		return (NULL);
	while (shape)
	{
		if (shape->i != -1)
			shape = shape->next_lev;
		if (shape && shape->i == -1)
		{
			if (!shape->next_fig)
				return (shape);
			return (remove_figs(shape, shape->next_fig));
		}
	}
	return (shape);
}

int		check_same_figs(t_map *sh, t_map *sh_m)
{
	if (sh_m->x[0] == sh->x[0] && sh_m->y[0] == sh->y[0])
		if (sh_m->x[1] == sh->x[1] && sh_m->y[1] == sh->y[1])
			if (sh_m->x[2] == sh->x[2] && sh_m->y[2] == sh->y[2])
				if (sh_m->x[3] == sh->x[3] && sh_m->y[3] == sh->y[3])
					return (1);
	return (0);
}

void	remove_figs1(t_map *shape, t_map *sh_move)
{
	int a;
	int b;

	while (sh_move)
	{
		if (sh_move->i == -1 && check_same_figs(shape, sh_move))
			sh_move->i = shape->f - 1;
		if (sh_move->i == -1)
		{
			a = -1;
			while (++a < 4 && sh_move->i == -1)
			{
				b = -1;
				while (++b < 4 && sh_move->i == -1)
					if (sh_move->x[a] == shape->x[b])
						if (sh_move->y[a] == shape->y[b])
							sh_move->i = shape->f;
			}
		}
		if (sh_move->next_lev)
			sh_move = sh_move->next_lev;
		else
			sh_move = sh_move->next_fig;
	}
}

t_map	*remove_figs(t_map *shape, t_map *sh_move)
{
	if (!sh_move)
		return (NULL);
	remove_figs1(shape, sh_move);
	if (!select_positions(shape->next_fig))
	{
		ft_restore_index(shape, shape);
		shape->i = shape->f;
		if (shape->next_lev)
		{
			while (shape && shape->i != -1)
				shape = shape->next_lev;
			if (shape)
				shape = remove_figs(shape, shape->next_fig);
			else
				return (NULL);
		}
		else
			return (NULL);
	}
	return (shape);
}
