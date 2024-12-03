/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:30:07 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/06 18:30:08 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			write(2, "Error\nWrong map\n", 16);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_characters(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == 32 || str[i] == 'P' || str[i] == 'E'
				|| str[i] == 'C' || str[i] == '1' || str[i] == '0'
				|| (9 <= str[i] && str[i] <= 13) || str[i] == 'V'))
		{
			write(2, "Error\nWrong map\n", 16);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_chars(char *str)
{
	int	i;
	int	count_p;
	int	count_e;
	int	count_c;

	i = 0;
	count_c = 0;
	count_e = 0;
	count_p = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			count_p++;
		else if (str[i] == 'E')
			count_e++;
		else if (str[i] == 'C')
			count_c++;
		i++;
	}
	if (count_c < 1 || count_e != 1 || count_p != 1)
	{
		write(2, "Error\nWrong map\n", 16);
		return (-1);
	}
	return (0);
}

int	check_size(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (-1);
		i++;
	}
	return (0);
}

int	check_map(char **map_main)
{
	char	**map;

	map = get_copy(map_main);
	if (check_size(map) == -1)
	{
		free_array(map);
		return (-1);
	}
	if (check_borders(map) == -1)
	{
		free_array(map);
		return (-1);
	}
	if (check_ws(map) == -1)
	{
		free_array(map);
		return (-1);
	}
	if (flood_fill(map) == -1)
	{
		free_array(map);
		return (-1);
	}
	free_array(map);
	return (0);
}
