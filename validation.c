/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:12:15 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/04 14:12:16 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
		&& str[i + 3] == 'r' && str[i + 4] == '\0')
		return (0);
	write(2, "Error\nWrong file name\n", 22);
	exit(1);
}

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		&& ((9 <= str[i + 1] && str[i + 1] <= 13) || str[i + 1] == 32))
		i++;
	if (((9 == str[i] && str[i] <= 13) || str[i] == 32)
		&& !((9 <= str[i + 1] && str[i + 1] <= 13) || str[i + 1] == 32))
		return (-1);
	return (0);
}

char	*get_str(int fd)
{
	char	*temp;
	char	*str;

	str = NULL;
	temp = get_next_line(fd);
	if (!temp)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	while (temp)
	{
		str = ft_strjoin(str, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	temp = NULL;
	if (check_spaces(str) == -1)
	{
		write(2, "Error\nWrong map\n", 16);
		free(str);
		exit(1);
	}
	str = ft_strtrim(str, " \n\t\r\v\f");
	return (str);
}

char	**get_map(int fd)
{
	char	*str;
	int		i;
	char	**map;

	i = 0;
	str = get_str(fd);
	simple_checks(str);
	map = ft_split(str, '\n');
	if (!map)
	{
		free(str);
		write(2, "Error\n", 6);
		exit (1);
	}
	while (map[i])
	{
		map[i] = ft_trimend(map[i], " \t\r\v\f");
		i++;
	}
	free(str);
	return (map);
}

char	**validate(char *str)
{
	int		fd;
	char	**map;

	check_name(str);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFile does not exist\n", 26);
		exit (1);
	}
	map = get_map(fd);
	if (check_map(map) == -1)
	{
		write(2, "Error\nWrong map\n", 16);
		free_array(map);
		exit(1);
	}
	return (map);
}
