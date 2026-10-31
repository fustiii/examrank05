#include "bsq.h"

int is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int parse_first_line(FILE *f, t_map *map)
{
	int s[3];
	int nl;

	if (fscanf(f, "%d%c%c%c%c%c%c%c", &map->rows, &s[0], &map->empty, &s[1]
		, map->obstacle, &s[2], &map->full, &nl) != 8)
		return (1);

	// \n, spaces, rows <= 0
	if (nl != '\n' || s[0] != ' ' || s[1] != ' ' || s[2] != ' '
		|| map->rows <= 0)
		return (1);
	//equals
	if (map->empty == map->obstacle
		|| map->obstacle == map->full
		|| map->full == map->empty)
		return (1);
	//printable
	if (!is_printable(map->empty)
		|| !is_printable(map->obstacle)
		|| !is_printable(map->full))
		return (1);
	
	return (0);
}

int	check_line(char *line, t_map *map, ssize_t len, int row)
{
	//All lines have the same length
	if (map->cols == 0)
		map->cols == len - 1;
	else
	{
		if (map->cols != (int)len - 1)
			return (1);
	}
	//Characters of first line
	int i = 0;
	while (i < len - 1)
	{
		if (line[i] != map->empty && line[i] != map->obstacle)
			return (1);
		i++;
	}
	//Line finish with \n && at least 1 col
	//! es or ||
	if (line[len - 1] != '\n' || len < 2)
		return (1);
	//Mas filas que indicadas en cabecera
	if (row >= map->rows)
		return (1);

	return (0);
}

int	parse_map(FILE *f, t_map *map)
{
	char 	*line = NULL;
	size_t	size = 0;
	ssize_t	len = 0;
	int		row = 0;

	//allocar memoria map
	map->map = calloc(map->rows + 1, sizeof(char *));
	if (!map->map)
	{
		return (1);
	}

	//read lines
	while ((len = getline(&line, &size, f)) != -1)
	{
		if (check_line(&line, map, len, row) != 0)
		{
			free(line);
			return (1);
		}

		line[len - 1] = '\0';
		map->map[row] = line;
		row++;
		line = NULL;
		len = 0;
	}
	free(line);

	if (map->rows != row)
		return (1);
	return (0);
}

int parse(FILE *f, t_map *map)
{
	if (parse_first_line(f, map) != 0)
		return (1);
	if (parse_map(f, map) != 0)
		return (1);
	return (0);
}