/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:00:03 by psatin            #+#    #+#             */
/*   Updated: 2021/04/26 15:38:15 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_str(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		count++;
	}
	return (count);
}

static char	*ft_getstring(char const *s, char c)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s[size] && s[size] != c)
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	**ft_free(char **tab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(tab[n]);
		i++;
	}
	free(tab);
	return (0);
}

static char	**ft_getstrings(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		tab[j] = ft_getstring(s + i, c);
		if (!tab[j])
			return (ft_free(tab, j));
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;

	if (!s)
		return (0);
	count = ft_count_str(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (0);
	result = ft_getstrings(result, s, c);
	return (result);
}
