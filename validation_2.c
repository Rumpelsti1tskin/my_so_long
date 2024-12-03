/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:03:48 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/06 20:03:51 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **map)
{
	char	**ptr;

	if (!map)
		return ;
	ptr = map;
	while (*ptr)
	{
		free (*ptr);
		ptr++;
	}
	free (map);
	map = NULL;
}

int	check_borders_1(char **map)
{
	int	i;
	int	size;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
		j++;
	size = ft_strlen(map[i]);
	while (i < j)
	{
		if (map[i][size - 1] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (map[j - 1][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_borders(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
		j++;
	while (i < j)
	{
		if (map[i][0] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (-1);
		i++;
	}
	if (check_borders_1(map) == -1)
		return (-1);
	return (0);
}

int	check_ws(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 9 || map[i][j] == 32
				|| (10 < map[i][j] && map[i][j] <= 13))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	simple_checks(char *str)
{
	if (check_nl(str) == -1)
	{
		free(str);
		str = NULL;
		exit(1);
	}
	if (check_characters(str) == -1)
	{
		free(str);
		str = NULL;
		exit(1);
	}
	if (check_chars(str) == -1)
	{
		free(str);
		str = NULL;
		exit(1);
	}
}
