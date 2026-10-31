#include "bsq.h"

void	init_map(t_map *map)
{
	map->cols = 0;
	map->rows = 0;
	map->empty = '\0';
	map->obstacle = '\0';
	map->full = '\0';
	map->map = NULL;
}

void	init_square(t_square *square)
{
	square->size = 0;
	square->x = 0;
	square->y = 0;
}