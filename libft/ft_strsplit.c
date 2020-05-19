/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:38:14 by couida            #+#    #+#             */
/*   Updated: 2019/09/13 17:25:27 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**count_words_and_return_root_array(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tmp;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	if ((tmp = (char**)malloc(sizeof(char*) * (j + 1))))
	{
		tmp[j] = 0;
		return (tmp);
	}
	return (NULL);
}

static	char	*full_array(char const *s, char c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	if (!(tmp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	tmp[i] = '\0';
	while (i-- > 0)
	{
		s--;
		tmp[i] = *s;
	}
	return (tmp);
}

static	void	free_all(char **tmp, size_t i)
{
	while (i > 0)
	{
		i--;
		free(tmp[i]);
		tmp[i] = NULL;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	j;
	char	**tmp;

	j = 0;
	if (!(tmp = count_words_and_return_root_array(s, c)))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			if ((tmp[j++] = full_array(s, c)))
			{
				while (*s != c && *s)
					s++;
			}
			else
			{
				free_all(tmp, j);
				return (NULL);
			}
		}
	}
	return (tmp);
}
