#include "bsq.h"

void	print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		fprintf(stdout, "%s\n", map[i]);
		i++;
	}
}

int process(FILE *f)
{
	t_map map;

	init_map(&map);

	if (parse(&map, f) != 0)
	{
		free_array(map.map);
		fprintf(stderr, "map error\n");
		return (1);
	}

	if (solve(&map) != 0)
	{
		free_array(map.map);
		fprintf(stderr, "map error\n");
		return (1);
	}

	print_map(map.map);

	free_array(map.map);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (process(stdin));
	else
	{
		for (int i = 1; i < argc; i++)
		{
			FILE *f  = fopen(argv[i], "r");
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