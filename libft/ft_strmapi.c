/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:07:27 by couida            #+#    #+#             */
/*   Updated: 2019/09/10 19:08:17 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

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
				fresh[i] = f(i, s[i]);
			}
			return (fresh);
		}
	}
	return (NULL);
}
