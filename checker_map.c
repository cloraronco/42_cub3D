/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:02:58 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/28 14:43:24 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_name(char *av, t_map *map)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 4] != '.' || av[i - 3] != 'c' || av[i - 2] != 'u'
		|| av[i - 1] != 'b')
	{
		free (map);
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}

// int	check_map_hori(t_map *map)
// {
// 	int	i;
// 	int	k;
// 	int	size;

// 	k = 0;
// 	while (map->map[k])
// 	{
// 		size = ft_strlen(map->map[k]);
// 		i = 0;
// 		while (map->map[i])
// 		{
// 			if (ft_strlen(map->map[i]) != size)
// 				return (0);
// 			i++;
// 		}
// 		k++;
// 	}
// 	return (1);
// }

// int	count_line_verti(t_map *map)
// {
// 	int	j;

// 	j = 0;
// 	while (map->map[j])
// 		j++;
// 	return (j);
// }

// int	check_map_verti(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	size;

// 	j = 0;
// 	while (map->map[0][j])
// 	{
// 		size = count_line_verti(map);
// 		i = 0;
// 		while (map->map[0][i])
// 		{
// 			if (count_line_verti(map) != size)
// 				return (0);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (1);
// }

// int	check_geo(t_map *map)
// {
// 	if (ft_strlen(map->map[0]) != count_line_verti(map))
// 		return (0);
// 	return (1);
// }

int	map_check_ext(char c)
{
	if (c == '1' || c == ' ')
		return (1);
	return (0);
}

int	map_check_element(t_map *map, char c)
{
	if (c == '1' || c == ' ' || c == '0')
		return (1);
	if (map->element != 1 && (c == 'N' || c == 'S' || c == 'W' || c == 'E'))
	{
		map->element = 1;
		return (1);
	}
	return (0);
}

int	map_element(t_map *map, int	i)
{
	int	j;

	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map_check_element(map, map->map[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (map->element != 1)
		return (0);
	return (1);
}

int	map_check_left(char *map, int j)
{
	while (map[j])
	{
		if (map[j] == '1')
			return (1);
		if (map[j] == ' ')
			return (0);
		j--;
	}
	return (0);
}

int	map_check_right(char *map, int j)
{
	while (map[j])
	{
		if (map[j] == '1')
			return (1);
		if (map[j] == ' ')
			return (0);
		j++;
	}
	return (0);
}

int	map_check_top(char **map, int i, int j, int n)
{
	while (i >= n)
	{
		if (map[i][j] == '1')
			return (1);
		if (map[i][j] == ' ')
			return (0);
		i--;
	}
	return (0);
}

int	map_check_bot(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] == '1')
			return (1);
		if (map[i][j] == ' ')
			return (0);
		i++;
	}
	return (0);
}

int	map_check_shield(t_map *map, int i)
{
	int	j;
	int	n;
	int	x;

	j = 0;
	n = i;
	x = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '0' && (map_check_right(map->map[i], j) == 0
				|| map_check_left(map->map[i], j) == 0
				|| map_check_bot(map->map, i, j) == 0
				|| map_check_top(map->map, i, j, n) == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_ext(t_map *map, int i)
{
	int	j;
	int	loop;
	int	temp;

	j = 0;
	loop = 0;
	temp = 0;
	map->xx = i;
	while (map->map[i][j] == ' ')
		j++;
	if (map_check_shield(map, i) == 0)
		return (0);
	return (1);
}