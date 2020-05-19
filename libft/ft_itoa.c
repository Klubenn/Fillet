/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:29:04 by couida            #+#    #+#             */
/*   Updated: 2019/09/16 15:33:37 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_digits(int n)
{
	long long	t;
	size_t		i;

	i = 0;
	t = (long long)n;
	if (n < 0)
	{
		i++;
		t = t * -1;
	}
	if (n == 0)
		return (1);
	while (t > 9)
	{
		i++;
		t /= 10;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	long long	nbr;
	size_t		i;
	char		*tmp;

	i = count_digits(n);
	nbr = (1 - 2 * (n < 0)) * (long long)n;
	if (!(tmp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	tmp[i] = '\0';
	while (i > 0)
	{
		i--;
		tmp[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		tmp[0] = '-';
	return (tmp);
}
