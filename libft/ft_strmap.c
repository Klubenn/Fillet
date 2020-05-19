/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:36:33 by couida            #+#    #+#             */
/*   Updated: 2019/09/10 18:55:29 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	size_t	i;
	char	*fresh;

	i = 0;
	if (s)
	{
		while (s && s[i])
			i++;
		fresh = (char*)malloc(sizeof(char) * (i + 1));
		if (fresh)
		{
			fresh[i] = '\0';
			while (i > 0)
			{
				i--;
				fresh[i] = f(s[i]);
			}
			return (fresh);
		}
	}
	return (NULL);
}
