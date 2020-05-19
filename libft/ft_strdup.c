/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:11:21 by couida            #+#    #+#             */
/*   Updated: 2019/09/09 20:37:09 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp_s1;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	if ((tmp_s1 = (char*)malloc(sizeof(char) * (i + 1))))
	{
		tmp_s1[i] = '\0';
		while (i-- > 0)
			tmp_s1[i] = s1[i];
		return (tmp_s1);
	}
	else
		return (NULL);
}
