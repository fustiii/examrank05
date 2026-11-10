#include "bsq.h"

void	print_map(t_map *map)
{
	int i = 0;
	while (i < map->rows)
	{
		fprintf(stdout, "%s\n", map->map[i]);
		i++;
	}
}

int process(FILE *f)
{
	t_map map;

	init_map(&map);

	if (parse(f, &map) != 0)
	{
		fprintf(stderr, "map error\n");
		free_array(map.map, map.rows);
		return (1);
	}

	if (solve(&map) != 0)
	{
		fprintf(stderr, "map errror\n");
		free_array(map.map, map.rows);
		return (1);
	}

	print_map(&map);

	free_array(map.map, map.rows);

	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (process(stdin));

	for (int i = 1; i < argc; i++)
	{
		FILE *f = fopen(argv[i], "r");
		if (!f)
		{
			fprintf(stderr, "map error\n");
			if (argc > 2)
				fprintf(stderr, "\n");
			continue;
		}
		process(f);
		fclose(f);
		if (argc > 2)
			fprintf(stderr, "\n");
	}
	return (0);
}