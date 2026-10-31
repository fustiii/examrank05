#include "bsq.h"

int is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	parse_first_line(t_map *map, FILE *f)
{
	char sp[3];
	char nl;

	if (fscanf(f, "%d%c%c%c%c%c%c%c", &map->rows, &sp[0], &map->empty, &sp[1]
		, &map->obstacle, &sp[2], &map->full, &nl) != 8)
	{
		return (1);
	}
	//! Multiple validations
	//Check that the last char is \n and space exist and at least 1 row
	if (sp[0] != ' ' || sp[1] != ' ' || sp[2] != ' '
		|| nl != '\n' || map->rows <= 0)
	{
		return (1);
	}
	
	//Check repetidos
	if (map->empty == map->obstacle || map->obstacle == map->full
		|| map->full == map->empty)
	{
		return (1);
	}

	//Check printable
	if (!is_printable(map->empty)
		|| !is_printable(map->obstacle)
		|| !is_printable(map->full))
	{
		return (1);
	}
	
	return (0);
}

static int check_line(char *line, t_map *map, size_t len, int row)
{
	// More rows than indicated in the header
	if (row >= map->rows)
		return (1);

	//All rows have the same length
	if (map->cols == 0)
		map->cols = len - 1;
	else if ((int)len - 1 != map->cols)
		return (1);

	// At least 1 col and exist \n
	if (len < 2 || line[len - 1] != '\n')
		return (1);
	
	//Characters on line are the same that in the first line
	int	i = 0;
	while (i < map->cols)
	{
		if (line[i] != map->empty && line[i] != map->obstacle)
			return (1);
		i++;
	}

	return (0);
}

int	parse_map(t_map *map, FILE *f)
{
	char	*line = NULL;
	size_t	size = 0;
	ssize_t	len = 0;
	int		row = 0;

	//calloc for map->map
	map->map = calloc(map->rows + 1, sizeof(char *));
	if (!map->map)
		return (1);

	while ((len = getline(&line, &size, f)) != -1)
	{
		//check line
		if (check_line(line, map, len, row) != 0)
		{
			free (line);
			return (1);
		}

		line[len - 1] = '\0';
		map->map[row] = line;
		line = NULL;
		len = 0;
		row++;
	}
	free (line); //liberar último que queda colago cuando getline lee EOF
	if (row != map->rows)
		return (1);
	return (0);
}

int parse(t_map *map, FILE *f)
{
	//parse first line
	if (parse_first_line(map, f) != 0)
		return (1);
	//parse map
	if (parse_map(map, f) != 0)
		return (1);
	return (0);
}