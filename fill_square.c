/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <gtristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:43:05 by gtristan          #+#    #+#             */
/*   Updated: 2019/10/09 14:50:38 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_square(t_map *sh)
{
	int		x;
	int		y;
	int		pole_size;
	t_map	*tmp_sh;

	pole_size = 2;
	tmp_sh = sh;
	while (tmp_sh->next_fig)
		tmp_sh = tmp_sh->next_fig;
	while (pole_size * pole_size < (tmp_sh->f) * 4)
		pole_size++;
	if (tmp_sh->f < 3)
	{
		while (sh)
		{
			x = ft_find_max(sh->x[0], sh->x[1], sh->x[2], sh->x[3]);
			y = ft_find_max(sh->y[0], sh->y[1], sh->y[2], sh->y[3]);
			if (x + 1 > pole_size)
				pole_size = x + 1;
			if (y + 1 > pole_size)
				pole_size = y + 1;
			sh = sh->next_fig;
		}
	}
	return (pole_size);
}

void	ft_restore_index(t_map *shape, t_map *sh_mov)
{
	if (!sh_mov)
		return ;
	if (sh_mov->i >= shape->f)
		sh_mov->i = -1;
	if (!sh_mov->next_lev)
		ft_restore_index(shape, sh_mov->next_fig);
	else
		ft_restore_index(shape, sh_mov->next_lev);
}

void	ft_restore_index1(t_map *shape)
{
	while (shape)
	{
		shape->i = -1;
		shape = shape->next_fig;
	}
}

void	free_dupl(t_map *shape)
{
	t_map *tmp;

	while (shape)
	{
		tmp = shape->next_lev;
		shape->next_lev = NULL;
		shape = tmp;
		while (shape->next_lev)
		{
			tmp = shape->next_lev;
			free(shape);
			shape = tmp;
		}
		tmp = shape->next_fig;
		free(shape);
		shape = tmp;
	}
}

int		fill_square(t_map *shape, int pole_size)
{
	t_map *shape0;
	t_map *shape_init;

	shape0 = shape;
	shape_init = shape;
	while (shape0)
	{
		while ((shape->next_lev = ft_dupl(shape0, shape, pole_size)) != NULL)
			shape = shape->next_lev;
		shape0 = shape0->next_fig;
		shape = shape0;
	}
	if (shape_init->next_fig && !remove_figs(shape_init, shape_init->next_fig))
	{
		free_dupl(shape_init);
		ft_restore_index1(shape_init);
		pole_size = fill_square(shape_init, pole_size + 1);
	}
	return (pole_size);
}
