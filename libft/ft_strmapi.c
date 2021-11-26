/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:36:20 by psatin            #+#    #+#             */
/*   Updated: 2021/04/23 17:17:06 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	len;
	unsigned int	i;

	if (s)
	{
		len = ft_strlen(s);
		i = 0;
		result = (char *)malloc((len + 1) * sizeof(char));
		if (result == 0)
			return (0);
		while (i < len)
		{
			result[i] = f(i, s[i]);
			i++;
		}
		result[i] = 0;
		return (result);
	}
	return (0);
}
