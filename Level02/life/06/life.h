#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_data
{
	int		width;
	int		height;
	int		iterations;
	char	**cur;
	char	**next;
} t_data;

#endif