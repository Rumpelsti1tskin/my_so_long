/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:16:13 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/15 20:16:14 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw2(t_vars *vars, t_data *mlx, int i, int j)
{
	if (vars->map[i][j] == 'C' && vars->s == '2')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/c2.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else if (vars->map[i][j] == 'C' && vars->s == '3')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/c3.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else if (vars->map[i][j] == 'P' && vars->c == 'l')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/Pl.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else if (vars->map[i][j] == 'P' && vars->c == 'p')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/P1.xpm", &(mlx->img_width),
				&(mlx->img_height));
}

void	go_1(t_vars *vars)
{
	vars->map[vars->player_row - 1][vars->player_col] = 'P';
	vars->map[vars->player_row][vars->player_col] = '0';
	vars->player_row -= 1;
}

void	go_2(t_vars *vars)
{
	vars->map[vars->player_row][vars->player_col - 1] = 'P';
	vars->map[vars->player_row][vars->player_col] = '0';
	vars->player_col -= 1;
}

void	go_3(t_vars *vars)
{
	vars->map[vars->player_row][vars->player_col + 1] = 'P';
	vars->map[vars->player_row][vars->player_col] = '0';
	vars->player_col += 1;
}

void	go_4(t_vars *vars)
{
	vars->map[vars->player_row + 1][vars->player_col] = 'P';
	vars->map[vars->player_row][vars->player_col] = '0';
	vars->player_row += 1;
}
