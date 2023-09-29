#include "../../include/cub3d.h"
#include "engine.h"
#include "../draw/draw.h"
#include "../init/init.h"

void	e_size_h_rayon(t_engine *engine, double rx, double ry, double ra)
{
	double	c;

	(void)ra;
	c = 0;
	c = sqrtf((powf(rx - engine->posx, 2) + powf(ry - engine->posy, 2)));
	engine->dist = c;
}
