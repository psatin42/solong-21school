/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:56:34 by psatin            #+#    #+#             */
/*   Updated: 2021/04/23 18:49:16 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] != 0 && j < len)
	{
		if (haystack[j] == needle[0])
		{
			i = 1;
			while (needle[i] != 0 && haystack[j + i] == needle[i])
			{
				if (j + i < len)
					i++;
				else
					break ;
			}
			if (needle[i] == 0)
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (0);
}
