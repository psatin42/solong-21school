/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psatin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:31:34 by psatin            #+#    #+#             */
/*   Updated: 2021/04/20 21:55:57 by psatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_number(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_putnbr(char *result, int n, int len)
{
	unsigned int	num;
	int				i;

	i = len - 1;
	if (n < 0)
	{
		result[0] = '-';
		num = (unsigned int)(n * (-1));
	}
	else
		num = (unsigned int)n;
	if (num == 0)
		result[0] = '0';
	while (num != 0)
	{
		result[i] = num % 10 + 48;
		i--;
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = ft_len_number(n);
	if (n < 0)
		len++;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	ft_putnbr(result, n, len);
	result[len] = 0;
	return (result);
}
