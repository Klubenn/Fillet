/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:35:51 by couida            #+#    #+#             */
/*   Updated: 2019/09/23 21:20:44 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*fresh;

	if (!s1 || !s2)
		return (NULL);
	i = (size_t)(ft_strlen(s1) + ft_strlen(s2));
	if ((fresh = (char*)malloc(sizeof(char) * (i + 1))))
	{
		fresh[i] = '\0';
		j = 0;
		i = 0;
		while (s1[j])
		{
			fresh[j] = s1[j];
			j++;
		}
		while (s2[i])
		{
			fresh[i + j] = s2[i];
			i++;
		}
		return (fresh);
	}
	return (NULL);
}
