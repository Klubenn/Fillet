/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:43:23 by couida            #+#    #+#             */
/*   Updated: 2019/09/09 20:34:48 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	if (p_src > p_dst)
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	else
	{
		while (len-- > 0)
		{
			p_dst[len] = p_src[len];
		}
	}
	return (dst);
}
