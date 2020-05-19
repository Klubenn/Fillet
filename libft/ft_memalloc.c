/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:36:25 by couida            #+#    #+#             */
/*   Updated: 2019/09/10 16:14:49 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *p;

	p = (char*)malloc(size);
	if (!p)
		return (NULL);
	while (size > 0)
	{
		size--;
		p[size] = '\0';
	}
	return (p);
}
