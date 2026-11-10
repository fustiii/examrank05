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

int	process(FILE *f)
{
	//init
	t_map map;

	init_map(&map);

	//parse
	if (parse(f, &map) != 0)
	{
		free_array(map.map, map.rows);
		fprintf(stderr, "map error\n");
		return (1);
	}

	//solve
	if (solve(&map) != 0)
	{
		free_array(map.map, map.rows);
		fprintf(stderr, "map error\n");
		return (1);
	}


	//print
	print_map(&map);


	//free
	free_array(map.map, map.rows);

	return (0);
}


int	main(int argc, char **argv)
{
	if (argc == 1)
		return (process(stdin));

	for (int i = 1; i < argc; i++)
	{
		FILE *f = fopen(argv[i], "r");
		if (!f)
		{
			fprintf(stderr, "map error");
			continue;
		}
		process(f);
		fclose(f);
		if (argc > 2)
			fprintf(stdout, "\n");
	}
	return (0);
}