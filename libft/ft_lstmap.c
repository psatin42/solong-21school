/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:07:19 by psatin            #+#    #+#             */
/*   Updated: 2021/04/26 13:42:26 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;

	result = 0;
	if (lst)
	{
		while (lst)
		{
			new = ft_lstnew(f(lst->content));
			if (new == 0)
			{
				ft_lstclear(&result, del);
				return (0);
			}
			ft_lstadd_back(&result, new);
			lst = lst->next;
		}
	}
	return (result);
}
