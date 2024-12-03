/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:28:48 by ykisibek          #+#    #+#             */
/*   Updated: 2024/01/25 17:07:17 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_minint(int num)
{
	char	*min;
	char	*str;
	int		i;

	i = 0;
	num = -2147483648;
	str = "-2147483648";
	min = (char *)malloc(12 * sizeof(char));
	if (!min)
		return (NULL);
	while (str[i] != '\0')
	{
		min[i] = str[i];
		i++;
	}
	min[i] = '\0';
	return (min);
}

int	check(int nn)
{
	if (nn < 0)
		nn = -nn;
	return (nn);
}

int	minusator(int nnn)
{
	if (nnn < 0)
		return (1);
	return (0);
}

int	counter(int nnnn)
{
	int	count;

	count = 1;
	while ((nnnn / 10) > 0)
	{
		count++;
		nnnn = nnnn / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		size;
	int		number;

	if (n == -2147483648)
		return (ft_minint(n));
	number = check(n);
	size = minusator(n) + counter(number);
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (minusator(n) == 1)
		ptr[0] = '-';
	ptr[size] = '\0';
	size--;
	while (size >= minusator(n))
	{
		ptr[size] = (number % 10) + 48;
		number = number / 10;
		size--;
	}
	return (ptr);
}
