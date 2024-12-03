/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:11:48 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/04 14:11:50 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_x(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'E'))
			return (i);
		i++;
	}
	return (0);
}

int	exit_y(char **map)
{
	int	i;
	int	j;

	i = exit_x(map);
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == 'E')
			return (j);
		j++;
	}
	return (0);
}

int	count_coins(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	get_vars(t_vars *vars)
{
	vars->size_column = ft_strlen(vars->map[0]);
	vars->size_row = 0;
	while (vars->map[vars->size_row])
		vars->size_row++;
	if (vars->size_row > 11 || vars->size_column > 20)
	{
		free_array(vars->map);
		write(2, "Error\nMap is wrong for this monitor\n", 36);
		exit (1);
	}
	vars->player_row = player_x(vars->map);
	vars->player_col = player_y(vars->map);
	vars->exit_col = exit_y(vars->map);
	vars->exit_row = exit_x(vars->map);
	vars->count_coins = count_coins(vars->map);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	mlx;

	if (argc != 2)
	{
		write(1, "Error\nWrong arguments\n", 22);
		return (1);
	}
	vars.map = validate(argv[1]);
	get_vars(&vars);
	draw_win(&vars, &mlx);
	return (0);
}
