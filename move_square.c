/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:23:58 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/29 11:45:37 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

// void	move_square_up(t_vars *mlx, t_map *map)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x < size_player)
// 	{
// 		y = 0;
// 		while (y < size_player)
// 		{
// 			mlx_pixel_put(mlx->mlx, mlx->win,
// 				(size_mini * (map->pos_y)) + y + map->pix_y,
// 				(size_mini * (map->pos_x)) + x + map->pix_x, 0x000000FF);
// 			y++;
// 		}
// 		x++;
// 	}
// 	map->map[map->xx + map->pos_x][map->pos_y] = '0';
// 	map->pix_x = size_mini - size_player;
// 	x = 0;
// 	while (x < size_player)
// 	{
// 		y = 0;
// 		while (y < size_player)
// 		{
// 			mlx_pixel_put(mlx->mlx, mlx->win,
// 				(size_mini * (map->pos_y)) + y + map->pix_y,
// 				(size_mini * (map->pos_x - 1)) + x + map->pix_x, 0x0000FF00);
// 			y++;
// 		}
// 		x++;
// 	}
// 	// map->pix_x -= map->pdx;
// 	// map->pix_y -= map->pdy;
// 	map->pos_x -= 1;
// 	mlx->up = 0;
// 	count_move(1);
// }

void	move_square_up(t_vars *mlx, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x00FF0000);
			y++;
		}
		x++;
	}
	map->map[map->xx + map->pos_x][map->pos_y] = '0';
	// map->pix_x = size_mini - map->pdx;
	// map->pix_y = map->pdy;
	// map->pix_y = size_mini - size_player;
	x = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x - 1)) + x + map->pix_x, 0x0000FF00);
			y++;
		}
		x++;
	}
	// map->pix_x -= map->pdx;
	// map->pix_y -= map->pdy;
	map->pos_x -= 1;
	mlx->up = 0;
	count_move(1);
}

void	move_square_down(t_vars *mlx, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x000000FF);
			y++;
		}
		x++;
	}
	map->map[map->xx + map->pos_x][map->pos_y] = '0';
	map->pix_x = 0;
	x = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x + 1)) + x + map->pix_x, 0x0000FF00);
			y++;
		}
		x++;
	}
	map->pos_x += 1;
	mlx->down = 0;
	count_move(1);
}

void	move_square_left(t_vars *mlx, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x000000FF);
			y++;
		}
		x++;
	}
	map->map[map->xx + map->pos_x][map->pos_y] = '0';
	map->pix_y = size_mini - size_player;
	x = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y - 1)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x0000FF00);
			y++;
		}
		x++;
	}
	map->pos_y -= 1;
	mlx->left = 0;
	count_move(1);
}

void	move_square_right(t_vars *mlx, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x000000FF);
			y++;
		}
		x++;
	}
	map->map[map->xx + map->pos_x][map->pos_y] = '0';
	map->pix_y = 0;
	x = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y + 1)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x0000FF00);
			y++;
		}
		x++;
	}
	map->pos_y += 1;
	mlx->right = 0;
	count_move(1);
}
