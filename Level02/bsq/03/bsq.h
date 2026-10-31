#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>

typedef struct s_square
{
	int size;
	int x;
	int y;
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



#endif