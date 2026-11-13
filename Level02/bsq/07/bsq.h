#ifndef BSQ_H
#define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_square
{
	int size;
	int	y;
	int	x;
} t_square;

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
int solve(t_map *map);
void	free_array(char **arr, int h);
void	free_dp(int **dp, int rows);
void init_square(t_square *square);
void	init_map(t_map *map);

#endif