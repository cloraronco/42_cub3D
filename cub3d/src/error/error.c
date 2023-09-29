#include "../../include/cub3d.h"
#include "error.h"

void	error(t_data *data, char *str)
{
	printf("%s\n", str);
	gc_free_all(&data->track);
	exit(0);
}
