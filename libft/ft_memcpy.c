/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:12:08 by couida            #+#    #+#             */
/*   Updated: 2019/09/09 19:15:10 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp_dst;
	const unsigned char *tmp_src;

	if (!dst && !src)
		return (NULL);
	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	while (n-- > 0)
		tmp_dst[n] = tmp_src[n];
	return (dst);
}
