/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:16:04 by ykisibek          #+#    #+#             */
/*   Updated: 2024/05/04 14:16:05 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_data
{
	void	*mlx1;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_vars
{
	char	**map;
	int		size_row;
	int		size_column;
	int		count_coins;
	int		current_coins;
	int		player_row;
	int		player_col;
	int		exit_row;
	int		exit_col;
	t_data	*mlx;
	char	c;
	int		step;
	char	s;
}	t_vars;

char	*get_next_line(int fd);
int		ft_strlcpy(char *dest, char *src, int size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*free_from_nl(char *line);
int		count_nl(char *line);
char	*fill_line(char *line, int fd);
void	free_line(char *str);
char	**validate(char *str);
char	*ft_strtrim(char *s1, char *set);
char	*nolength(char *str);
char	**ft_split(char *s, char c);
char	*ft_join(char *s1, char *s2);
char	*ft_trimend(char *s1, char *set);
char	**get_map(int fd);
int		check_nl(char *str);
char	*get_str(int fd);
int		check_spaces(char *str);
int		check_name(char *str);
int		check_characters(char *str);
int		check_chars(char *str);
void	free_array(char **map);
int		check_map(char **map);
int		check_borders(char **map);
int		check_ws(char **map);
void	simple_checks(char *str);
int		flood_fill(char **map);
void	do_fill(char ***map, int x, int y);
char	**get_copy(char **map);
int		player_x(char **map);
int		player_y(char **map);
void	draw_win(t_vars *vars, t_data *mlx);
int		exit_map(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	ft_putnbr_fd(int n, int fd);
void	draw1(t_vars *vars, t_data *mlx, int i, int j);
void	draw(t_vars *vars, t_data *mlx, int i, int j);
void	change_map(t_vars *vars, t_data *mlx);
void	print_step(t_vars *vars);
int		exit_map_fail(t_vars *vars);
int		exit_map_succes(t_vars *vars);
void	go_1(t_vars *vars);
void	go_2(t_vars *vars);
void	go_3(t_vars *vars);
void	go_4(t_vars *vars);
char	*ft_itoa(int n);
void	draw2(t_vars *vars, t_data *mlx, int i, int j);
int		render_next_frame(t_vars *vars);

#endif
