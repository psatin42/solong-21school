/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:18:07 by psatin            #+#    #+#             */
/*   Updated: 2021/04/26 16:12:43 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	last;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (0);
	i = start;
	j = 0;
	last = (int)ft_strlen(s);
	if (start + (int)len < last)
		last = start + (int)len;
	sub = (char *)malloc(last - start + 1);
	if (sub == 0)
		return (0);
	while (i < last)
		sub[j++] = s[i++];
	sub[j] = 0;
	return (sub);
}
