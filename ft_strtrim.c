/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:36:55 by ykisibek          #+#    #+#             */
/*   Updated: 2024/01/25 17:11:08 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (ft_strlen(src) < size)
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (ft_strlen(src));
	}
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*nolength(char *str)
{
	char	*no;

	(void)str;
	no = (char *)malloc(1);
	no[0] = '\0';
	return (no);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (nolength(s1));
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	while (ft_strchr(set, s1[ft_strlen(s1) - end - 1])
		&& (ft_strlen(s1) - end - 1) > start)
		end++;
	ptr = (char *)malloc((ft_strlen(s1) - start - end + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, ft_strlen(s1) - start - end + 1);
	free(s1);
	return (ptr);
}

char	*ft_trimend(char *s1, char *set)
{
	char	*ptr;
	size_t	end;

	end = 0;
	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (nolength(s1));
	while (ft_strchr(set, s1[ft_strlen(s1) - end - 1])
		&& (ft_strlen(s1) - end - 1) > 0)
		end++;
	ptr = (char *)malloc((ft_strlen(s1) - end + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) - end + 1);
	free(s1);
	return (ptr);
}
