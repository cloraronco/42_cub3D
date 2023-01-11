/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:06:14 by clora-ro          #+#    #+#             */
/*   Updated: 2023/01/04 17:40:51 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

// void	raycast_main(t_vars *mlx, t_map *map)
// {
// 	int	x;
// 	int	y;
// 	float	rx;
// 	float	ry;
// 	float	dx;
// 	float	dy;
// 	float	rrx;
// 	float	rry;
// 	int	count;
// 	int	dount;

// 	x = 0;
// 	count = 0;
// 	dount = 0;
// 	// rx = (map->pdx / map->pdy) * ((map->pdy / map->pdx) * 0.01);
// 	// ry = (map->pdy / map->pdx) * ((map->pdx / map->pdy) * 0.01);
// 	ry = ((map->pdy / map->pdx) * 0.1);
// 	rx = ((map->pdx / map->pdy) * 0.1);
// 	rrx = rx;
// 	rry = ry;
// 	dprintf(2, "rx : %f\n", rx);
// 	dprintf(2, "ry : %f\n", ry);
// 	dprintf(2, "pdx : %f\n", map->pdx);
// 	dprintf(2, "pdy : %f\n", map->pdy);
// 	// while (count < 1)
// 	// {
// 	// 	while (dount < 10)
// 	// 	{
// 	// 		mlx_pixel_put(mlx->mlx, mlx->win, (size_mini * (map->pos_y)) + y + map->pix_y - dy,
// 	// 			(size_mini * (map->pos_x)) + x + map->pix_x - dx, 0x000000FF);
// 	// 			dx += map->pdx;
// 	// 			dy += map->pdy;
// 	// 		dount++;
// 	// 	}
// 	// 	count++;
// 	// }
// 	count = 0;
// 	dx = 0;
// 	dy = 0;
// 	while (count < 15)
// 	{
// 		dount = 0;
// 		y = 0;
// 		x = 0;
// 		rx = 0;
// 		ry = 0;
// 	}
// }

// int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
// {
// 	double	deltaX = endX - beginX; // 10
// 	double	deltaY = endY - beginY; // 0
// 	double	pixelX;
// 	double	pixelY;
// 	int		pixels;

// 	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// 	//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
// 	deltaX /= pixels; // 1
// 	deltaY /= pixels; // 0
// 	pixelX = beginX;
// 	pixelY = beginY;
// 	while (pixels)
// 	{
// 		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// 		pixelX += deltaX;
// 		pixelY += deltaY;
// 		--pixels;
// 	}
// }

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double	deltaX = endX - beginX; // 10
	double	deltaY = endY - beginY; // 0
	double	pixelX;
	double	pixelY;
	int		pixels;

	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	pixelX = beginX;
	pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (1);
}

void	raycast(t_vars *mlx, t_map *map)
{
	int	x;
	float	rx;
	float	ry;
	float	dx;
	float	dy;
	float	rrx;
	float	rry;
	int	count;
	int	dount;

	x = 0;
	count = 0;
	dount = 0;


	if (map->pdx >= 0 && map->pdy <= 0)
	{
		rx = (((map->pdx - 5) * -1) * 90) / 5; // angle en degrés
		ry = ((map->pdx) * 90) / 5;
		dprintf(2, "Angle x : %f\n", rx);
		dprintf(2, "Angle y : %f\n", ry);
		// dprintf(2, "pdx : %f\n", map->pdx);
		// dprintf(2, "pdy : %f\n", map->pdy);

		map->px = map->pix_x;
		map->py = map->pix_y;
		if (map->px < 0)
			map->px += 40;
		if (map->px > 40)
			map->px -= 40;
		if (map->py < 0)
			map->py += 40;
		if (map->py > 40)
			map->py -= 40;
		dprintf(2, "x : %f\n", map->px);
		dprintf(2, "y : %f\n", map->py);
		dprintf(2, "pix_x : %f\n", map->pix_x);
		dprintf(2, "pix_y : %f\n", map->pix_y);

		dx = map->px / cos(rx); // hypthenuse
		
		rx = atan(rx) * map->px;
		ry = atan(ry) * map->py;

		dprintf(2, "rx : %f\n", rx);
		dprintf(2, "ry : %f\n", ry);
		dprintf(2, "[%d,%d]\n", map->pos_x, map->pos_y);


		draw_line(mlx->mlx, mlx->win,
			(size_mini * (map->pos_y)) + map->pix_y,
			(size_mini * (map->pos_x)) + map->pix_x,
			(size_mini * (map->pos_y)) + ry,
			(size_mini * (map->pos_x)) + rx - map->pix_y,
			0x0000FF00);
	}


	// rx = (map->pdx / map->pdy) * ((map->pdy / map->pdx) * 0.01);
	// ry = (map->pdy / map->pdx) * ((map->pdx / map->pdy) * 0.01);
	map->pix_x += map->pdx;
	map->pix_y += map->pdy;
	ry = ((map->pdy / map->pdx));
	rx = ((map->pdx / map->pdy));
	rrx = rx;
	rry = ry;
	dprintf(2, "pdx : %f\n", map->pdx);
	dprintf(2, "pdy : %f\n\n", map->pdy);
	count = 0;
	dx = 0;
	dy = 0;
	// while (count < 10)
	// {
	// 	x = 0;
	// 	rx = 0;
	// 	ry = 0;
	// 	if (map->pdx >= 0 && map->pdy >= 0)
	// 	{
	// 		while (x < 10 && rx >= 0 && rx < 10 && ry >= 0 && ry < 10)
	// 		{
	// 			mlx_pixel_put(mlx->mlx, mlx->win,
	// 				(size_mini * (map->pos_y)) + map->pix_y - dy - ry,
	// 				(size_mini * (map->pos_x)) + map->pix_x + x - dx - rx,
	// 				0x0000FF00);
	// 			x++;
	// 			rx += rrx;
	// 			ry += rry;
	// 		}
	// 		dx += map->pdx;
	// 		dy += map->pdy;
	// 	}
	// 	count++;
	// }
	// count = 0;
	// dx = 0;
	// dy = 0;
	map->pix_x -= map->pdx;
	map->pix_y -= map->pdy;
	ry = ((map->pdy / map->pdx));
	rx = ((map->pdx / map->pdy));
	rrx = rx;
	rry = ry;
	while (count < 10)
	{
		x = 0;
		rx = 0;
		ry = 0;
		if (map->pdx >= 0 && map->pdy >= 0)
		{
			while (x < 10 && rx >= 0 && rx < 10 && ry >= 0 && ry < 10)
			{
				mlx_pixel_put(mlx->mlx, mlx->win,
					(size_mini * (map->pos_y)) + map->pix_y - dy - ry,
					(size_mini * (map->pos_x)) + map->pix_x + x - dx - rx,
					0x0000FF00);
				x++;
				rx += rrx;
				ry += rry;
			}
			dx += map->pdx;
			dy += map->pdy;
		}
		count++;
	}
}
