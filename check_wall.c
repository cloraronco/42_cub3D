/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:05:06 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/29 16:01:41 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	check_up(t_map *map)
{
	int	x;
	int	y;
	float	px;
	float	py;
	int Rx;

	x = map->xx + map->pos_x;
	y = map->pos_y;
	px = map->pix_x;
	py = map->pix_y;
	dprintf(2, "pdx : %f\n", map->pdx);
	dprintf(2, "pdy : %f\n", map->pdy);
	dprintf(2, "pix_x : %f\n", map->pix_x);
	dprintf(2, "pix_y : %f\n", map->pix_y);
	dprintf(2, "pos_x : %d\n", map->pos_x);
	dprintf(2, "pos_y : %d\n", map->pos_y);
	Rx = (((map->pix_x - map->pdx) - (size_mini)) / size_mini);
	dprintf(2, "Rx : %d\n", Rx);

	if (map->pdx <= 0 && map->map[x + Rx + 1][y] != '1')
		return (1);
	if (map->pdx > 0 && map->map[x + Rx][y] != '1')
		return (1);




	dprintf(2, "ZERO\n");
	return (0);
}

int	check_down(t_map *map)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = map->xx + map->pos_x;
	y = map->pos_y;
	px = map->pix_x;
	py = map->pix_y;

	if (map->map[x + 1][y] == '0')
		return (1);
	// if (px + pixel_move < size_mini)
	// 	return (1);
	// if (!(px + pixel_move < size_mini) && map->map[x + 1][y] == '0')
	// 	return (2);
	return (0);
}

int	check_left(t_map *map)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = map->xx + map->pos_x;
	y = map->pos_y;
	px = map->pix_x;
	py = map->pix_y;

	if (py - pixel_move >= 0)
		return (1);
	if (!(py - pixel_move >= 0) && map->map[x][y - 1] == '0')
		return (2);
	return (0);
}

int	check_right(t_map *map)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = map->xx + map->pos_x;
	y = map->pos_y;
	px = map->pix_x;
	py = map->pix_y;

	if (py + pixel_move < size_mini)
		return (1);
	if (!(py + pixel_move < size_mini) && map->map[x][y + 1] == '0')
		return (2);
	return (0);
}

void	count_move(int i)
{
	static int	count;

	count = i + count;
	ft_putnbr_fd(count, 2);
	ft_putendl_fd("", 2);
}
