/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:22:58 by couida            #+#    #+#             */
/*   Updated: 2019/09/14 18:48:55 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (lst)
	{
		new = f(lst);
		if (new)
		{
			lst = lst->next;
			tmp = new;
			while (lst)
			{
				if ((tmp->next = f(lst)))
				{
					tmp = tmp->next;
					lst = lst->next;
				}
				else
					return (NULL);
			}
			return (new);
		}
	}
	return (NULL);
}
