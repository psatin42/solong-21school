/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:47:43 by psatin            #+#    #+#             */
/*   Updated: 2021/04/17 19:51:36 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src1;
	const char	*lasts;
	char		*dst1;
	char		*lastd;

	src1 = (char *)src;
	dst1 = (char *)dst;
	if (dst1 < src1)
		while (len-- > 0)
			*dst1++ = *src1++;
	else if (dst1 == src1)
		return (dst);
	else
	{
		if (len > 0)
		{
			lasts = src1 + (len - 1);
			lastd = dst1 + (len - 1);
			while (len-- > 0)
				*lastd-- = *lasts--;
		}
	}
	return (dst);
}
