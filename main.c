/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:05:14 by clora-ro          #+#    #+#             */
/*   Updated: 2022/12/30 15:13:12 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_vars	mlx;
	t_vars	lenght;

	(void)ac;
	(void)av;
	if (ac != 2)
		return (0);
	map = ft_calloc(1, sizeof(t_map));
	if (check_name(av[1], map) != 1)
		return (0);
	lenght.lenght = 44;
	init_mlx(&mlx);
	mlx.mlx = mlx_init();
	init_map(av[1], map);
	map->pa = 0;
	map->pdx = cos(map->pa) * 5;
	map->pdy = sin(map->pa) * 5;
	// mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "cub3D");
	mlx.win = mlx_new_window(mlx.mlx, 1000, 500, "cub3D");
	// if (load_image(&mlx, lenght) != 0)
		// return (0);
	check_map(&mlx, map);
	build_map(&mlx, map);
	events_hooks(&mlx);
	change_map(&mlx, map);
	mlx.map = map;
	mlx_loop(mlx.mlx);
	ft_close(&mlx);
	return (0);
}
