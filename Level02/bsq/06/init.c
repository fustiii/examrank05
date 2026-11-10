#include "bsq.h"

void init_square(t_square *square)
{
	square->size = 0;
	square->x = 0;
	square->y = 0;
}

void init_map(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->empty = '\0';
	map->obstacle = '\0';
	map->full = '\0';
	map->map = NULL;
}