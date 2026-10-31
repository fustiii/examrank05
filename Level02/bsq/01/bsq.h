#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_square
{
	int size;
	int x;
	int y;
} t_square;

typedef struct t_map
{
	int		cols;
	int		rows;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
} t_map;

int		parse(t_map *map, FILE *f);
int		solve(t_map *map);
void	free_dp(int **dp, int rows);
void	free_array(char **array);
void	init_map(t_map *map);
void	init_square(t_square *square);

#endif