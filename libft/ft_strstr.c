/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:09:45 by couida            #+#    #+#             */
/*   Updated: 2019/09/10 11:33:32 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)s1;
	i = 0;
	while (*tmp && *s2 != '\0')
	{
		while ((tmp[i] == s2[i]) && (s2[i]))
			i++;
		if (i > 0 && s2[i] == '\0')
			return (tmp);
		else
			i = 0;
		tmp++;
	}
	if (*s2 == '\0')
		return (tmp);
	return (NULL);
}
