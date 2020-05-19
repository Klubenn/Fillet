/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <gtristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:35:25 by gtristan          #+#    #+#             */
/*   Updated: 2019/10/12 14:28:02 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_map	*map;
	int		pole_size;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (!read_text(read_buf(av[1])))
	{
		write(1, "error\n", 6);
		return (0);
	}
	map = get_map_root()->next_fig;
	align_figs(map);
	pole_size = min_square(map);
	pole_size = fill_square(map, pole_size);
	print_figs(map, pole_size);
	return (0);
}
