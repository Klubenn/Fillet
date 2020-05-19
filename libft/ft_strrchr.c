/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:53:23 by couida            #+#    #+#             */
/*   Updated: 2019/09/08 20:09:11 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *s_i;
	char *tmp;

	s_i = (char*)s;
	tmp = NULL;
	while (*s_i)
	{
		if (*s_i == c)
			tmp = s_i;
		s_i++;
	}
	if (*s_i == c)
		tmp = s_i;
	return (tmp);
}
