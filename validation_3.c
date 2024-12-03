/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:17:22 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/07 16:17:23 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_fill(char ***map, int x, int y)
{
	int	size_y;
	int	size_x;

	size_y = ft_strlen((*map)[x]);
	size_x = 0;
	while ((*map)[size_x])
		size_x++;
	if (y < 0 || y >= size_y || x < 0 || x >= size_x
		|| (*map)[x][y] == '1' || (*map)[x][y] == 'F'
		|| (*map)[x][y] == 'V')
		return ;
	(*map)[x][y] = 'F';
	do_fill(map, x + 1, y);
	do_fill(map, x, y + 1);
	do_fill(map, x - 1, y);
	do_fill(map, x, y - 1);
}

int	player_x(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'P'))
			return (i);
		i++;
	}
	return (0);
}

int	player_y(char **map)
{
	int	i;
	int	j;

	i = player_x(map);
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == 'P')
			return (j);
		j++;
	}
	return (0);
}

int	flood_fill(char **map)
{
	int	x;
	int	y;

	x = player_x(map);
	y = player_y(map);
	do_fill(&map, x, y);
	x = 0;
	while (map[x])
	{
		if (ft_strchr(map[x], 'P') || ft_strchr(map[x], 'C')
			|| ft_strchr(map[x], 'E'))
			return (-1);
		x++;
	}
	return (0);
}

char	**get_copy(char **map)
{
	char	**map_copy;
	int		size_row;
	int		i;

	size_row = 0;
	i = 0;
	while (map[size_row])
		size_row++;
	map_copy = (char **)malloc((size_row + 1) * sizeof (char *));
	if (!map_copy)
		return (NULL);
	while (i < size_row)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
