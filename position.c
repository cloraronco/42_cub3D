/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:35:11 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/29 12:50:49 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	change_map(t_vars *mlx, t_map *map)
{
	// dprintf(2, "pdx : %f\n", map->pdx);
	// dprintf(2, "pdy : %f\n", map->pdy);
	// dprintf(2, "pix_x : %d\n", map->pos_x);
	// dprintf(2, "pix_y : %d\n", map->pos_y);
	if (mlx->up == 1)
		move_up(mlx, map);
	if (mlx->up == 2)
		move_square_up(mlx, map);
	if (mlx->down == 1)
		move_down(mlx, map);
	if (mlx->down == 2)
		move_square_down(mlx, map);
	if (mlx->left == 1)
		move_left(mlx, map);
	if (mlx->left == 2)
		move_square_left(mlx, map);
	if (mlx->right == 1)
		move_right(mlx, map);
	if (mlx->right == 2)
		move_square_right(mlx, map);
	if (mlx->rotate_left == 1)
		rotate_left(map, mlx);
	if (mlx->rotate_right == 1)
		rotate_right(map, mlx);
}


// char	first_position(t_map map)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (map.map || map.map[x][y] != 'P')
// 	{
// 		y = 0;
// 		while (map.map[x][y] != '\n' || map.map[x][y] != 'P')
// 			y++;
// 		x++;
// 	}
// 	return (map.map[x][y]);
// }