/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:52:03 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/15 13:52:04 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_1(t_vars *vars)
{
	if (vars->map[vars->player_row - 1][vars->player_col] == '0')
	{
		go_1(vars);
		print_step(vars);
	}
	else if (vars->map[vars->player_row - 1][vars->player_col] == 'C')
	{
		go_1(vars);
		vars->current_coins += 1;
		print_step(vars);
	}
	else if (vars->map[vars->player_row - 1][vars->player_col] == 'V')
	{
		print_step(vars);
		exit_map_fail(vars);
	}
	else if (vars->map[vars->player_row - 1][vars->player_col] == 'E')
	{
		go_1(vars);
		print_step(vars);
		if (vars->current_coins == vars->count_coins)
			exit_map_succes(vars);
	}
	vars->c = 'p';
}

void	do_2(t_vars *vars)
{
	if (vars->map[vars->player_row][vars->player_col - 1] == '0')
	{
		go_2(vars);
		print_step(vars);
	}
	else if (vars->map[vars->player_row][vars->player_col - 1] == 'C')
	{
		go_2(vars);
		vars->current_coins += 1;
		print_step(vars);
	}
	else if (vars->map[vars->player_row][vars->player_col - 1] == 'V')
	{
		print_step(vars);
		exit_map_fail(vars);
	}
	else if (vars->map[vars->player_row][vars->player_col - 1] == 'E')
	{
		go_2(vars);
		print_step(vars);
		if (vars->current_coins == vars->count_coins)
			exit_map_succes(vars);
	}
	vars->c = 'l';
}

void	do_3(t_vars *vars)
{
	if (vars->map[vars->player_row][vars->player_col + 1] == '0')
	{
		go_3(vars);
		print_step(vars);
	}
	else if (vars->map[vars->player_row][vars->player_col + 1] == 'C')
	{
		go_3(vars);
		vars->current_coins += 1;
		print_step(vars);
	}
	else if (vars->map[vars->player_row][vars->player_col + 1] == 'V')
	{
		print_step(vars);
		exit_map_fail(vars);
	}
	else if (vars->map[vars->player_row][vars->player_col + 1] == 'E')
	{
		go_3(vars);
		print_step(vars);
		if (vars->current_coins == vars->count_coins)
			exit_map_succes(vars);
	}
	vars->c = 'r';
}

void	do_4(t_vars *vars)
{
	if (vars->map[vars->player_row + 1][vars->player_col] == '0')
	{
		go_4(vars);
		print_step(vars);
	}
	else if (vars->map[vars->player_row + 1][vars->player_col] == 'C')
	{
		go_4(vars);
		vars->current_coins += 1;
		print_step(vars);
	}
	else if (vars->map[vars->player_row + 1][vars->player_col] == 'V')
	{
		print_step(vars);
		exit_map_fail(vars);
	}
	else if (vars->map[vars->player_row + 1][vars->player_col] == 'E')
	{
		go_4(vars);
		print_step(vars);
		if (vars->current_coins == vars->count_coins)
			exit_map_succes(vars);
	}
	vars->c = 'p';
}

int	key_hook(int keycode, t_vars *vars)
{
	if (vars->map[vars->exit_row][vars->exit_col] != 'E'
		&& vars->map[vars->exit_row][vars->exit_col] != 'P')
		vars->map[vars->exit_row][vars->exit_col] = 'E';
	if (keycode == 53)
		exit_map(vars);
	else if (keycode == 13 || keycode == 126)
		do_1(vars);
	else if (keycode == 0 || keycode == 123)
		do_2(vars);
	else if (keycode == 2 || keycode == 124)
		do_3(vars);
	else if (keycode == 1 || keycode == 125)
		do_4(vars);
	if (vars->map[vars->exit_row][vars->exit_col] != 'E'
		&& vars->map[vars->exit_row][vars->exit_col] != 'P')
		vars->map[vars->exit_row][vars->exit_col] = 'E';
	mlx_clear_window(vars->mlx->mlx1, vars->mlx->win);
	change_map(vars, vars->mlx);
	return (0);
}
