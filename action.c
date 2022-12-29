/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:09:02 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/29 14:40:28 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	my_key_code(int keycode, t_vars *mlx)
{
	t_map	*map;

	map = mlx->map;
	if (keycode == 53)
		ft_close(mlx);
	if (keycode == 13 && check_up(map) == 1)
		mlx->up = 1;
	// if (keycode == 13 && check_up(map) == 2)
	// 	mlx->up = 2;
	if (keycode == 1 && check_down(map) == 1)
		mlx->down = 1;
	if (keycode == 1 && check_down(map) == 2)
		mlx->down = 2;
	// if (keycode == 0 && check_left(map) == 1)
	// 	mlx->left = 1;
	// if (keycode == 0 && check_left(map) == 2)
	// 	mlx->left = 2;
	// if (keycode == 2 && check_right(map) == 1)
	// 	mlx->right = 1;
	// if (keycode == 2 && check_right(map) == 2)
	// 	mlx->right = 2;
	// if (keycode == 124)
	// 	mlx->rotate_left = 1;
	// if (keycode == 123)
	// 	mlx->rotate_right = 1;
	if (keycode == 2)
		mlx->rotate_left = 1;
	if (keycode == 0)
		mlx->rotate_right = 1;
	// raycast(mlx, map);
	change_map(mlx, map);
	return (keycode);
}

void	ft_close(t_vars *mlx)
{
	// mlx_destroy_image(mlx->mlx, mlx->img.exit);
	// mlx_destroy_image(mlx->mlx, mlx->img.floor);
	// mlx_destroy_image(mlx->mlx, mlx->img.piece);
	// mlx_destroy_image(mlx->mlx, mlx->img.position);
	// mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(1);
}

int	ft_close_hook(t_vars *mlx)
{
	// mlx_destroy_image(mlx->mlx, mlx->img.exit);
	// mlx_destroy_image(mlx->mlx, mlx->img.floor);
	// mlx_destroy_image(mlx->mlx, mlx->img.piece);
	// mlx_destroy_image(mlx->mlx, mlx->img.position);
	// mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(1);
	return (0);
}

void	ft_close_error(t_vars *mlx)
{
	// mlx_destroy_image(mlx->mlx, mlx->img.exit);
	// mlx_destroy_image(mlx->mlx, mlx->img.floor);
	// mlx_destroy_image(mlx->mlx, mlx->img.piece);
	// mlx_destroy_image(mlx->mlx, mlx->img.position);
	// mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	events_hooks(t_vars *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, my_key_code, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, ft_close_hook, mlx);
}
