/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:27:24 by couida            #+#    #+#             */
/*   Updated: 2019/09/09 20:43:08 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (i < len)
	{
		if (src[i] != '\0' && j != 0)
			dst[i] = src[i];
		else
		{
			j = 0;
			dst[i] = '\0';
		}
		i++;
	}
	return (dst);
}
