/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:27:56 by couida            #+#    #+#             */
/*   Updated: 2019/09/16 15:53:12 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if (size > size + 1)
		return (NULL);
	s = malloc(size + 1);
	if (!s)
		return (NULL);
	return (ft_memset(s, 0, size + 1));
}
