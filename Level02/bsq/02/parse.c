#include "bsq.h"

int is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int parse_first_line(t_map *map, FILE *f)
{
	char s[3];
	char nl;

	if (fscanf(f, "%d%c%c%c%c%c%c%c", &map->rows, &s[0], &map->empty, &s[1]
		, &map->obstacle, &s[2], &map->full, &nl) != 8)
		return (1);

	//check \n, spaces, 0 or less rows
	if (s[0] != ' ' || s[1] != ' ' || s[2] != ' '
		|| nl != '\n' || map->rows <= 0)
		return (1);

	//check equal
	if (map->empty == map->obstacle
		|| map->obstacle == map->full
		|| map->full == map->empty)
		return (1);

	//check printable
	if (!is_printable(map->empty)
		|| !is_printable(map->obstacle)
		|| !is_printable(map->full))
		return (1);
	return (0);
}

int check_line(t_map *map, char *line, int row, ssize_t len)
{
	// more rows that indicated in header
	//! es mayor o igual (siempre me lio)
	if (row >= map->rows)
		return (1);

	// same length
	if (map->cols == 0)
		map->cols = len - 1;
	//! deben ser iguales...
	else if ((int)len - 1 != map->cols)
		return (1);

	//check \n
	if (len < 2 && line[len - 1] != '\n')
		return (1);

	//only chars that are in header
	int i = 0;
	//! comparativas siempre mientras i menor...
	while (i < map->cols)
	{
		if (line[i] != map->empty && line[i] != map->obstacle)
			return (1);
		i++;
	}
	return (0);
}

int parse_map(t_map *map, FILE *f)
{
	char	*line = NULL;
	size_t	size = 0;
	ssize_t	len = 0;
	int		row = 0;

	//alloc memory
	map->map = calloc(map->rows + 1, sizeof(char *));
	if (!map->map)
	{
		return (1);
	}

	while ((len = getline(&line, &size, f)) != -1)
	{
		if (check_line(map, line, row, len) != 0)
		{
			free (line);
			return (1);
		}

		line[len - 1] = '\0';
		map->map[row] = line;
		row++;
		line = NULL;
		size = 0;
	}
	free (line);
	if (row != map->rows)
		return (1);
	return (0);
}

int parse(t_map *map, FILE *f)
{
	if (parse_first_line(map, f) != 0)
		return (1);
	if (parse_map(map, f) != 0)
		return (1);
	return (0);
}