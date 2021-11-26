/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:45:48 by psatin            #+#    #+#             */
/*   Updated: 2021/04/26 13:41:01 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*last;

	if (*lst)
	{
		current = *lst;
		while (current->next)
		{
			last = current->next;
			del(current->content);
			free(current);
			current = last;
		}
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
