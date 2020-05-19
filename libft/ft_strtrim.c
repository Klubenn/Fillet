/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:27:34 by couida            #+#    #+#             */
/*   Updated: 2019/09/12 18:48:50 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	if (j > 0)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		while (--j > i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
			;
	}
	k = 0;
	if ((tmp = (char*)ft_memalloc(j - i + 1 + (j > 0))))
		while (i <= j)
			tmp[k++] = s[i++];
	else
		return (NULL);
	tmp[k] = '\0';
	return ((char*)tmp);
}
