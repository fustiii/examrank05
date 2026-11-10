#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_square
{
	int	size;
	int	y;
	int	x;
}	t_square;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
} t_map;

int parse(FILE *f, t_map *map);
int	solve(t_map *map);
void init_map(t_map *map);
void init_square(t_square *square);
void free_array(char **arr, int row);
void free_dp(int **dp, int row);

#endif