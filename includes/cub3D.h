/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:55:00 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/29 15:08:39 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

#define size_mini 40
#define pixel_move 5
#define size_player 5
#define PI 3.1415926535


typedef struct s_map
{
	char	**map;
	int		pos_x;
	int		pos_y;
	float		pix_x;
	float		pix_y;
	int		xx;
	int		element;
	float	px, py, pdx, pdy, pa;
}	t_map;

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*exit;
	void	*piece;
	void	*position;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	t_img	img;
	void	*win;
	char	*move;
	t_map	*map;
	int		lenght;
	int		up;
	int		down;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		pars;
	int		NO;
	int		SO;
	int		EA;
	int		WE;
	int		F;
	int		C;
	int		xy;
	int		xwall;
}	t_vars;


int		main(int ac, char **av);

void	init_mlx(t_vars *mlx);
void	ft_free_split(char **tab);
int		count_line(char *av);
void	replace_backline(char *str);
void	init_map(char *av, t_map *map);

// int		read_map(t_vars mlx, char c, int x, int y);
// int		load_image(t_vars *mlx, t_vars lenght);
void	print_player(t_vars mlx, int i, int j, int color);
void	square(t_vars mlx, int i, int j, int color);
void	build_map(t_vars *mlx, t_map *map, t_vars lenght);
// int		co_x(t_map *map);
// int		co_y(t_map *map);

int		my_key_code(int keycode, t_vars *mlx);
void	ft_close(t_vars *mlx);
int		ft_close_hook(t_vars *mlx);
void	ft_close_error(t_vars *mlx);
void	events_hooks(t_vars *mlx);

// char	first_position(t_map map);
void	change_map(t_vars *mlx, t_map *map);

int		check_up(t_map *map);
int		check_wall_up(t_map *map);
int		check_down(t_map *map);
int		check_left(t_map *map);
int		check_right(t_map *map);
// int		check_wall_down(t_map *map);
// int		check_wall_left(t_map *map);
// int		check_wall_right(t_map *map);
void	count_move(int i);

// int		check_map_wall_hori(t_map *map);
// int		check_map_wall_verti(t_map *map);
// int		check_map_exit_player(t_map *map);
// int		check_map_coin(t_map *map);

int		ft_strncmpi(const char *s1, const char *s2, size_t n);
int		ft_strncmpix(const char *s1, const char *s2, size_t n, int x);
int		format_num(char *pos, int x);
int		pars_format(char *pos, char *s1);
int		diff_pos_loop(char *pos, char *s1, char *s2);
int		diff_pos(char *pos, t_vars *mlx);
void	check_map(t_vars *mlx, t_map *map);


int		check_name(char *av, t_map *map);
int		check_map_hori(t_map *map);
int		count_line_verti(t_map *map);
int		check_map_verti(t_map *map);
int		check_geo(t_map *map);
int		map_check_element(t_map *map, char c);
int		map_element(t_map *map, int	i);
int		map_check_ext(char c);
int		map_check_shield(t_map *map, int i);
int		map_ext(t_map *map, int i);

void	move_up(t_vars *mlx, t_map *map);
void	move_down(t_vars *mlx, t_map *map);
void	move_left(t_vars *mlx, t_map *map);
void	move_right(t_vars *mlx, t_map *map);

void	move_square_up(t_vars *mlx, t_map *map);
void	move_square_down(t_vars *mlx, t_map *map);
void	move_square_left(t_vars *mlx, t_map *map);
void	move_square_right(t_vars *mlx, t_map *map);

void	rotate_left(t_map *map, t_vars *mlx);
void	rotate_right(t_map *map, t_vars *mlx);

void	raycast(t_vars *mlx, t_map *map);

// int		ft_close_error1(t_vars *mlx);
// int		ft_close_error2(t_vars *mlx);
// int		ft_close_error3(t_vars *mlx);
// int		ft_close_error4(t_vars *mlx);
// int		ft_close_error5(t_vars *mlx);

#endif