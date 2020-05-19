/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:14:03 by couida            #+#    #+#             */
/*   Updated: 2019/09/06 15:51:49 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	unsigned char	tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char)c;
	p_s = (unsigned char*)s;
	while (i < n)
	{
		if (p_s[i] == tmp)
			return (&p_s[i]);
		i++;
	}
	return (NULL);
}
