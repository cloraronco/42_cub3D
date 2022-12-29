/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:45:50 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/29 12:16:06 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	rotate_left(t_map *map, t_vars *mlx)
{
	map->pa -= 0.1;

	if (map->pa < 0)
	{
		map->pa += 2 * PI;
	}
	map->pdx = cos(map->pa) * 5;
	map->pdy = sin(map->pa) * 5;
	mlx->rotate_left = 0;
}

void	rotate_right(t_map *map, t_vars *mlx)
{
	map->pa += 0.1;

	if (map->pa > 2 * PI)
	{
		map->pa += 2 * PI;
	}
	map->pdx = cos(map->pa) * 5;
	map->pdy = sin(map->pa) * 5;
	mlx->rotate_right = 0;
}