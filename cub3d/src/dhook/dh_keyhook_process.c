#include "../../include/cub3d.h"
#include "dhook.h"
#include "../draw/draw.h"

void	ft_keyhook_process(t_window win)
{
	mlx_clear_window(win.mlx_ptr, win.win_ptr);
	mlx_new_image(win.mlx_ptr, 1300, 900);
}
