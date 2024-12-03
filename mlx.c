/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:16:39 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/10 18:16:45 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	num = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (-2147483648 < n && n <= 2147483647)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n / 10 != 0)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		num = n % 10 + '0';
		write(fd, &num, 1);
	}
}

void	draw1(t_vars *vars, t_data *mlx, int i, int j)
{
	if (vars->map[i][j] == 'P' && vars->c == 'r')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/Pr.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else if (vars->map[i][j] == 'V')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/E1.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else if (vars->map[i][j] == 'C' && vars->s == '1')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/c1.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else if (vars->map[i][j] == 'E' && vars->count_coins == vars->current_coins)
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/exit1.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else if (vars->map[i][j] == 'E' && vars->count_coins != vars->current_coins)
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/exit2.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else
		draw2(vars, mlx, i, j);
}

void	draw(t_vars *vars, t_data *mlx, int i, int j)
{
	char	*res;

	res = ft_itoa(vars->step);
	if (vars->map[i][j] == 'P' && i == vars->exit_row && j == vars->exit_col)
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/e3.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else if (vars->map[i][j] == '1')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/1.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else if (vars->map[i][j] == '0')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx1,
				"./textures/0.xpm", &(mlx->img_width),
				&(mlx->img_height));
	else
		draw1(vars, mlx, i, j);
	mlx_put_image_to_window(mlx->mlx1, mlx->win,
		mlx->img, 100 * j, 100 * i);
	mlx_string_put(mlx->mlx1, mlx->win,
		50, 50, 0x000000, res);
	free(res);
	mlx_destroy_image(mlx->mlx1, mlx->img);
}

void	change_map(t_vars *vars, t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			draw(vars, mlx, i, j);
			j++;
		}
		i++;
	}
}

void	draw_win(t_vars *vars, t_data *mlx)
{
	vars->current_coins = 0;
	vars->step = 0;
	vars->c = 'p';
	vars->s = '1';
	vars->mlx = mlx;
	mlx->mlx1 = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx1, 100 * vars->size_column,
			100 * vars->size_row, "so_long");
	change_map(vars, vars->mlx);
	mlx_loop_hook(mlx->mlx1, render_next_frame, vars);
	mlx_hook(mlx->win, 2, 0, key_hook, vars);
	mlx_hook(mlx->win, 17, 0, exit_map, vars);
	mlx_loop(mlx->mlx1);
}
