#include "bsq.h"

void	print_board(char **map, int rows)
{
	int i = 0;

	while (i < rows)
	{
		fprintf(stdout, "%s\n", map[i]);
		i++;
	}
}

int process(FILE *f)
{
	//init
	t_map	map;

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

	print_board(map.map, map.rows);

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
		if (process(f) != 0)
		{
			if (argc > 2)
				fprintf(stderr, "\n");
		}
		else
		{
			if (argc > 2)
				fprintf(stdout, "\n");
		}
		fclose(f);
	}
	return (0);
}