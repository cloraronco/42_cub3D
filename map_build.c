/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:20:03 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/28 13:45:24 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	print_player(t_vars mlx, int i, int j, int color)
{
	int	x;
	int	y;
	int	mid;

	x = 0;
	y = 0;
	mid = size_mini / 2;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, (size_mini * (j)) + y + mid,
				(size_mini * (i)) + x + mid, color);
			y++;
		}
		x++;
	}
}

void	square(t_vars mlx, int i, int j, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < size_mini)
	{
		y = 0;
		while (y < size_mini)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, (size_mini * j) + y, (size_mini * i) + x, color);
			y++;
		}
		x++;
	}
}

void	build_map(t_vars *mlx, t_map *map, t_vars lenght)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = map->xx;
	lenght.lenght = 0;
	while (map->map[k] != '\0')
	{
		j = 0;
		while (map->map[k][j] != '\0')
		{
			if (map->map[k][j] == '1')
				square(*mlx, i, j, 0x00FF0000);
			if (map->map[k][j] == '0' || map->map[k][j] == 'N'
				|| map->map[k][j] == 'S' || map->map[k][j] == 'E'
				|| map->map[k][j] == 'W')
				square(*mlx, i, j, 0x000000FF);
			if (map->map[k][j] == 'N' || map->map[k][j] == 'S'
				|| map->map[k][j] == 'E' || map->map[k][j] == 'W')
			{
				map->pos_x = i;
				map->pos_y = j;
				map->pix_x = size_mini / 2;
				map->pix_y = size_mini / 2;
				print_player(*mlx, i, j, 0x0000FF00);
			}
			j++;
		}
		i++;
		k++;
	}
}