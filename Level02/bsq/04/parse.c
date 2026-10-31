#include "bsq.h"

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	parse_first_line(FILE *f, t_map *map)
{
	char	s[3];
	char	nl;

	if (fscanf(f, "%d%c%c%c%c%c%c%c", &map->rows, &s[0], &map->empty, &s[1], &map->obstacle
		, &s[2], &map->full, &nl) != 8)
		return (1);

	//space, \n, rows <= 0
	if (s[0] != ' ' || s[1] != ' ' || s[2] != ' ' || nl != '\n' || map->rows <= 0)
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

int	check_line(t_map *map, char *line, ssize_t len, int row)
{
	//all lines same lenght
	if (map->cols == 0)
		map->cols = len - 1;
	else if (map-> cols != (int)len - 1)
		return (1);
	//at least 2 cols and last char \n
	if (len < 2 || line[len - 1] != '\n')
		return (1);
	//only char that are on first line
	int i = 0;
	while (i < len - 1)
	{
		if (line[i] != map->empty && line[i] != map->obstacle)
			return (1);
		i++;
	}
	//more rows than in header
	if (row >= map->rows)
		return (1);
	return (0);
}

int	parse_map(FILE *f, t_map *map)
{
	char	*line = NULL;
	size_t	size = 0;
	ssize_t	len = 0;
	int	row = 0;

	map->map = calloc(map->rows + 1, sizeof(char *));
	if (!map->map)
		return (1);

	while ((len = getline(&line, &size, f)) != -1)
	{
		if (check_line(map, line, len, row) != 0)
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
	free(line);
	if (map->rows != row)
		return (1);
	return (0);
}

int	parse(FILE *f, t_map *map)
{
	if (parse_first_line(f, map) != 0)
		return (1);
	if (parse_map(f, map) != 0)
		return (1);
	return (0);
}
