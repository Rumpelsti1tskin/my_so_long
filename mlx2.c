/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:52:48 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/15 13:52:48 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_vars *vars)
{
	static int	s;

	if (s % 15 == 0)
	{
		s++;
		vars->s = '1';
	}
	else if (s % 10 == 0)
	{
		s++;
		vars->s = '2';
	}
	else if (s % 5 == 0)
	{
		s++;
		vars->s = '3';
	}
	else
		s++;
	mlx_clear_window(vars->mlx->mlx1, vars->mlx->win);
	change_map(vars, vars->mlx);
	return (0);
}

void	print_step(t_vars *vars)
{
	vars->step += 1;
	write(1, "step = ", 7);
	ft_putnbr_fd(vars->step, 1);
	write(1, "\n", 1);
}

int	exit_map(t_vars *vars)
{
	mlx_destroy_window(vars->mlx->mlx1, vars->mlx->win);
	free_array(vars->map);
	exit (0);
}

int	exit_map_fail(t_vars *vars)
{
	mlx_destroy_window(vars->mlx->mlx1, vars->mlx->win);
	free_array(vars->map);
	write(2, "You failed\n", 11);
	exit (1);
}

int	exit_map_succes(t_vars *vars)
{
	mlx_destroy_window(vars->mlx->mlx1, vars->mlx->win);
	free_array(vars->map);
	write(2, "You won\n", 8);
	exit (0);
}
