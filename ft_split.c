/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:51:35 by ykisibek          #+#    #+#             */
/*   Updated: 2024/02/01 17:22:30 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count(char const *str, char letter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == letter)
			i++;
		if (str[i] != letter && str[i] != '\0')
			count++;
		while (str[i] != letter && str[i] != '\0')
			i++;
	}
	return (count);
}

char	*ft_fill_words(const char *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len > 0)
	{
		word[len - 1] = s[len - 1];
		len--;
	}
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**ptr;
	size_t	j;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_count(s, c);
	j = 0;
	ptr = (char **)malloc((size + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s)
			ptr[j] = ft_fill_words(s, c);
		while (*s != c && *s != '\0')
			s++;
		j++;
	}
	ptr[size] = NULL;
	return (ptr);
}
