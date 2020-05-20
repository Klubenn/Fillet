/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupl_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <gtristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:12:14 by gtristan          #+#    #+#             */
/*   Updated: 2019/10/07 10:39:33 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_min(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (a);
	else if (b <= a && b <= c && b <= d)
		return (b);
	else if (c <= a && c <= b && c <= d)
		return (c);
	else
		return (d);
}

int		ft_find_max(int a, int b, int c, int d)
{
	if (a >= b && a >= c && a >= d)
		return (a);
	else if (b >= a && b >= c && b >= d)
		return (b);
	else if (c >= a && c >= b && c >= d)
		return (c);
	else
		return (d);
}

void	finish_dupl(t_map *sh_mv, t_map *shape)
{
	sh_mv->f = shape->f;
	sh_mv->i = shape->i;
	sh_mv->next_fig = shape->next_fig;
	sh_mv->next_lev = NULL;
}

t_map	*ft_dupl(t_map *shape0, t_map *shape, int pole_size)
{
	int		x;
	int		y;
	t_map	*sh_mv;
	int		i;

	i = -1;
	x = ft_find_max(shape->x[0], shape->x[1], shape->x[2], shape->x[3]);
	y = ft_find_max(shape->y[0], shape->y[1], shape->y[2], shape->y[3]);
	if ((x + 1) >= pole_size && (y + 1) >= pole_size)
		return (NULL);
	sh_mv = (t_map *)malloc(sizeof(t_map));
	if (x + 1 >= pole_size)
		while (++i < 4)
		{
			sh_mv->x[i] = shape0->x[i];
			sh_mv->y[i] = shape->y[i] + 1;
		}
	else
		while (++i < 4)
		{
			sh_mv->x[i] = shape->x[i] + 1;
			sh_mv->y[i] = shape->y[i];
		}
	finish_dupl(sh_mv, shape);
	return (sh_mv);
}
