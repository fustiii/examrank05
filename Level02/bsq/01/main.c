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

int	process(FILE *f)
{
	//Create map
	t_map	map;

	init_map(&map);

	//parser
	if (parse(&map, f) != 0)
	{
		free_array(map.map);
		fprintf(stderr, "msp error\n");
		return (1);
	}

	//solve
	if (solve(&map) != 0)
	{
		free_array(map.map);
		fprintf(stderr, "map error\n");
		return (1);
	}

	print_map(&map);

	free_array(map.map);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (process(stdin));
	else
	{
		int i = 1;
		while (i < argc)
		{
			//something its wrong because i'm not using continue...
			FILE *f = fopen(argv[i], "r");
			if (!f)
			{
				fprintf(stderr, "map error\n");
				i++;
				continue;
			}
			process(f);
			fclose(f);
			if (argc > 2)
    				fprintf(stdout, "\n");
			i++;
		}
	}
	return (0);
}