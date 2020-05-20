/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_figs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <gtristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:22:18 by gtristan          #+#    #+#             */
/*   Updated: 2019/10/07 19:45:33 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_connections(int arr[4][4])
{
	int y;
	int x;
	int n;
	int k;

	y = -1;
	n = 0;
	k = 0;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (arr[y][x] == 1)
			{
				n += (y > 0 ? arr[y - 1][x] : 0) + (x > 0 ? arr[y][x - 1] : 0) +
					(y < 3 ? arr[y + 1][x] : 0) + (x < 3 ? arr[y][x + 1] : 0);
				k++;
			}
		}
	}
	if ((n != 6 && n != 8) || k != 4)
		return (0);
	return (1);
}

int		validate_input(char *str)
{
	int arr[4][4];
	int i;
	int n;
	int y;
	int x;

	n = 0;
	i = -1;
	while (++i < 20)
	{
		if (str[i] == '\n' && ++n)
			continue ;
		y = ((i - n) / 4) % 4;
		x = (i - n) % 4;
		arr[y][x] = str[i] == '#' ? 1 : 0;
	}
	if (!check_connections(arr) || !include_value_into_map(arr))
		return (0);
	return (1);
}

int		read_text(char *str)
{
	int		i;
	char	*s;

	s = str;
	i = -1;
	while (str && str[++i])
	{
		if (str[i] != '\n' && str[i] != '#' && str[i] != '.')
			return (0);
		if (i && !(i % 19))
		{
			if (!validate_input(str) || str[i] != '\n' || (str[i + 1] != '\n'
				&& str[i + 1] != '\0'))
				return (0);
			if (str[i + 1] == '\n')
			{
				str = &str[i + 2];
				i = -1;
			}
		}
	}
	free(s);
	if (i == 20)
		return (1);
	return (0);
}

char	*read_buf(char *str)
{
	char	buf[546];
	int		ret;
	char	*s;

	ret = read(open(str, O_RDONLY), buf, 546);
	buf[ret] = '\0';
	if ((s = (char*)malloc(sizeof(char) * (ret + 1))))
	{
		if (ret > 545 || ret < 20)
			return (NULL);
		ret++;
		while (ret-- > 0)
			s[ret] = buf[ret];
	}
	return (s);
}
