#include "../../include/cub3d.h"
#include "engine.h"

int	e_check_collision(t_map **map, int y, int x)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (map[y][x].z != WALL)
			return (0);
		i++;
	}
	return (1);
}
