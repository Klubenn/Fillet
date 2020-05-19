/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:23:27 by couida            #+#    #+#             */
/*   Updated: 2019/09/08 19:32:59 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len_dst_start;
	size_t len_dst;
	size_t len_src;

	len_dst_start = ft_strlen(dst);
	len_dst = len_dst_start;
	len_src = ft_strlen(src);
	if (len_dst_start < dstsize)
	{
		while (len_dst < dstsize - 1 && *src)
		{
			dst[len_dst] = *src;
			len_dst++;
			src++;
		}
		dst[len_dst] = '\0';
		return (len_dst_start + len_src);
	}
	else
	{
		return (dstsize + ft_strlen(src));
	}
}
