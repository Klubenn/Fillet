/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:36:06 by couida            #+#    #+#             */
/*   Updated: 2019/09/15 17:37:01 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t len_s2;
	size_t i;

	len_s2 = (size_t)ft_strlen(s2);
	i = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] && (i < (len - len_s2) + 1) && (len >= len_s2))
	{
		if (ft_memcmp(&s1[i], s2, len_s2) == 0)
		{
			return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
