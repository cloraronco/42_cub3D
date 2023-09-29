#include "../../include/cub3d.h"
#include "draw.h"
#include "../engine/engine.h"

void	draw(t_data *data)
{
	d_my_pixel_clear(data);
	e_raycasting(data, &data->engine);
	e_minimap(data, data->minimap, data->map2d);
	mlx_put_image_to_window(data->window.mlx_ptr, data->window.win_ptr,
		data->window.img, 0, 0);
}
