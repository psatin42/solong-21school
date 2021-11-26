/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:37:14 by psatin            #+#    #+#             */
/*   Updated: 2021/04/20 20:59:24 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memmory;

	memmory = (void *)malloc(count * size);
	if (memmory == 0)
		return (0);
	ft_memset(memmory, 0, count * size);
	return (memmory);
}
