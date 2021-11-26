/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:40:59 by psatin            #+#    #+#             */
/*   Updated: 2021/04/21 23:40:54 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	i;
	size_t	j;

	length = ft_strlen(dst);
	i = 0;
	j = 0;
	if (dstsize > 0 && length < dstsize)
	{
		while (j < length)
			j++;
		while (i < (dstsize - length - 1) && src[i])
			dst[j++] = src[i++];
		dst[j] = 0;
	}
	if (length < dstsize)
		return (length + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}
