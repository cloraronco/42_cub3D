/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:02:16 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/28 13:48:26 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

// int	check_map_wall_hori(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	j = 0;
// 	k = count_line_verti(map) - 1;
// 	while (map->map[i][j])
// 	{
// 		if (map->map[i][j] != '1')
// 			return (0);
// 		j++;
// 	}
// 	while (map->map[k][i])
// 	{
// 		if (map->map[k][i] != '1')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	check_map_wall_verti(t_map *map)
// {
// 	int	i;
// 	int	k;

// 	i = 0;
// 	k = ft_strlen(map->map[0]) - 1;
// 	while (i < count_line_verti(map))
// 	{
// 		if (map->map[i][0] != '1')
// 			return (0);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < count_line_verti(map))
// 	{
// 		if (map->map[i][k] != '1')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	check_map_exit_player(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	exit;
// 	int	player;

// 	i = 0;
// 	exit = 0;
// 	player = 0;
// 	while (map->map[i])
// 	{
// 		j = 0;
// 		while (map->map[i][j])
// 		{
// 			if (map->map[i][j] == 'E')
// 				exit++;
// 			if (map->map[i][j] == 'P')
// 				player++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (exit < 1 || player != 1)
// 		return (0);
// 	return (1);
// }

// int	check_map_coin(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	coin;

// 	i = 0;
// 	coin = 0;
// 	while (map->map[i])
// 	{
// 		j = 0;
// 		while (map->map[i][j])
// 		{
// 			if (map->map[i][j] == 'C')
// 				coin++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (coin < 1)
// 		return (0);
// 	return (1);
// }

int	ft_strncmpi(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n < 1)
		return (0);
	while (s1[j] == ' ' || s1[j] == '	')
		j++;
	while ((unsigned char)s1[j] == (unsigned char)s2[i]
		&& s1[j] != '\0' && s2[i] != '\0' && (i < n - 1))
	{
		j++;
		i++;
	}
	if (n > 0)
		return ((unsigned char)s1[j] - (unsigned char)s2[i]);
	else
		return (0);
}

int	ft_strncmpix(const char *s1, const char *s2, size_t n, int x)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	j += x;
	if (n < 1)
		return (0);
	while (s1[j] == ' ' || s1[j] == '	')
		j++;
	while ((unsigned char)s1[j] == (unsigned char)s2[i]
		&& s1[j] != '\0' && s2[i] != '\0' && (i < n - 1))
	{
		j++;
		i++;
	}
	if (n > 0)
		return ((unsigned char)s1[j] - (unsigned char)s2[i]);
	else
		return (0);
}

int	diff_pos_loop(char *pos, char *s1, char *s2)
{
	int i;
	int	check;

	i = 0;
	check = 0;
	while (pos[i] == ' ' || pos[i] == '	' || pos[i] == '\n')
		i++;
	if (ft_strncmpix(pos, s1, 2, i) == 0)
	{
		i += 2;
		check++;
	}
	else	
		return (0);
	while (pos[i] == '	' || pos[i] == ' ')
		i++;
	if (ft_strncmpix(pos, s2, 2, i) == 0)
	{
		i += 2;
		check++;
	}
	while (ft_isprint(pos[i]) != 0)
		i++;
	while (pos[i] == '	' || pos[i] == ' ')
		i++;
	if (check != 2)
		return (0);
	return (1);
}

int	format_num(char *pos, int x)
{
	int	v;
	int	n;

	v = 0;
	n = 0;
	while (v != 2)
	{
		if (pos[x] == ',')
			return (0);
		if (atoi(&pos[x]) > 255 || atoi(&pos[x]) > 2147483647)
			return (0);
		while (ft_isdigit(pos[x]) == 1 && n < 3)
		{
			n++;
			x++;
		}
		if (pos[x] != ',')
			return (0);
		x++;
		n = 0;
		v++;
	}
	if (atoi(&pos[x]) > 255 || atoi(&pos[x]) > 2147483647)
		return (0);
	while (ft_isdigit(pos[x]) != 0 && n < 3)
	{
		x++;
		n++;
	}
	while (pos[x] == '	' || pos[x] == ' ')
		x++;
	if (pos[x] != '\0')
		return (0);
	return (1);	
}

int	pars_format(char *pos, char *s1)
{
	int i;
	int	check;

	i = 0;
	check = 0;
	while (pos[i] == ' ' || pos[i] == '	' || pos[i] == '\n')
		i++;
	if (ft_strncmpix(pos, s1, 1, i) == 0)
	{
		i ++;
		check++;
	}
	else
		return (0);
	while (pos[i] == '	' || pos[i] == ' ')
		i++;
	if (format_num(pos, i) == 0)
		return (0);
	return (1);
}

int	diff_pos(char *pos, t_vars *mlx)
{
	int	i;

	i = 0;
	if (mlx->NO == 0 && ft_strncmpi(pos, "NO", 2) == 0 && diff_pos_loop(pos, "NO", "./") == 1)
	{
		mlx->NO = 1;
		return (1);
	}
	else if (mlx->SO == 0 && ft_strncmpi(pos, "SO", 2) == 0 &&  diff_pos_loop(pos, "SO", "./") == 1)
	{
		mlx->SO = 1;
		return (1);
	}
	else if (mlx->WE == 0 && ft_strncmpi(pos, "WE", 2) == 0 &&  diff_pos_loop(pos, "WE", "./") == 1)
	{
		mlx->WE = 1;
		return (1);
	}
	else if (mlx->EA == 0 && ft_strncmpi(pos, "EA", 2) == 0 &&  diff_pos_loop(pos, "EA", "./") == 1)
	{
		mlx->EA = 1;
		return (1);
	}
	else if (mlx->F == 0 && ft_strncmpi(pos, "F", 1) == 0 && pars_format(pos, "F") == 1)
	{
		mlx->F = 1;
		return (1);
	}
	else if (mlx->C == 0 && ft_strncmpi(pos, "C", 1) == 0 && pars_format(pos, "C") == 1)
	{
		mlx->C = 1;
		return (1);
	}
	return (0);
}

void	check_map(t_vars *mlx, t_map *map)
{
	int	i;

	mlx->pars = 0;
	i = 0;
	while (i < 6)
	{
		while (ft_strcmp(map->map[mlx->pars], "") == 0)
			mlx->pars++;
		if (diff_pos(map->map[mlx->pars], mlx) == 0)
			ft_close_error(mlx);
		mlx->pars++;
		i++;
	}
	if (ft_strcmp(map->map[mlx->pars], "") != 0)
		ft_close_error(mlx);
	while (ft_strcmp(map->map[mlx->pars], "") == 0)
		mlx->pars++;
	if (map_element(map, mlx->pars) == 0 || map_ext(map, mlx->pars) == 0)
		ft_close_error(mlx);
}
