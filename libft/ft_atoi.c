/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:16:51 by couida            #+#    #+#             */
/*   Updated: 2019/09/12 14:24:11 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t				i;
	unsigned long long	number;
	int					minus_number;

	i = 0;
	minus_number = 1;
	number = 0;
	while (str[i] && (str[i] == ' ' || (str[i] > 8 && str[i] < 14)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus_number = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + str[i++] - '0';
	if (number > 9223372036854775807 && minus_number == -1)
		return (0);
	if (number > 9223372036854775807 && minus_number == 1)
		return (-1);
	if (minus_number == -1)
		return ((int)(number * -1));
	else
		return ((int)number);
}
