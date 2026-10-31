#include "bsq.h"

void print_map(t_map *map)
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
	//init
	t_map map;

	init_map(&map);

	//parse
	if (parse(&map, f) != 0)
	{
		free_array(map.map);
		fprintf(stderr, "map error\n");
		return (1);
	}

	//solve
	if (solve(&map) != 0)
	{
		free_array(map.map);
		fprintf(stderr, "maperror\n");
		return (1);
	}

	print_map(&map);
	
	free_array(map.map);

	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		return (process(stdin));
	else
	{
		for (int i = 1; i < argc; i++)
		{
			FILE *f = fopen(argv[1], "r");
			if (!f)
			{
				fprintf(stderr, "map error\n");
				continue;
			}
			process(f);
			fclose(f);
			if (argc > 2)
				fprintf(stdout, "\n");
		}
	}
	return (0);
}