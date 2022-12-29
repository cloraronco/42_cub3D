/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:29:53 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/29 15:23:14 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	move_up(t_vars *mlx, t_map *map)
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
			mlx_pixel_put(mlx->mlx, mlx->win, (size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x000000FF);
			y++;
		}
		x++;
	}
	x = 0;
	map->pix_x -= map->pdx;
	map->pix_y -= map->pdy;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, (size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x0000FF00);
			y++;
		}
		x++;
	}
	// if (map->pix_x < 0)
	// {
	// 	map->pos_x -= 1;
	// 	map->pix_x = size_mini + map->pix_x;
	// }
	// if (map->pix_x > size_mini)
	// {
	// 	map->pos_x += 1;
	// 	map->pix_x -= size_mini;
	// }
	mlx->up = 0;
	count_move(1);
}

void	move_down(t_vars *mlx, t_map *map)
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
			mlx_pixel_put(mlx->mlx, mlx->win, (size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x000000FF);
			y++;
		}
		x++;
	}
	x = 0;
	map->pix_x += map->pdx;
	map->pix_y += map->pdy;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, (size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x0000FF00);
			y++;
		}
		x++;
	}
	mlx->down = 0;
	count_move(1);
}

void	move_left(t_vars *mlx, t_map *map)
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
			mlx_pixel_put(mlx->mlx, mlx->win, (size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x000000FF);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y)) + y + map->pix_y - size_player,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x0000FF00);
			y++;
		}
		x++;
	}
	map->pix_y -= size_player;
	mlx->left = 0;
	count_move(1);
}

void	move_right(t_vars *mlx, t_map *map)
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
			mlx_pixel_put(mlx->mlx, mlx->win, (size_mini * (map->pos_y)) + y + map->pix_y,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x000000FF);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < size_player)
	{
		y = 0;
		while (y < size_player)
		{
			mlx_pixel_put(mlx->mlx, mlx->win,
				(size_mini * (map->pos_y)) + y + map->pix_y + size_player,
				(size_mini * (map->pos_x)) + x + map->pix_x, 0x0000FF00);
			y++;
		}
		x++;
	}
	map->pix_y += size_player;
	mlx->right = 0;
	count_move(1);
}
