#ifndef LIFE_H
#define LIFE_H

//#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
	int		width;
	int		height;
	int		iterations;
	char	**cur;
	char	**next;
} t_data;

void	run_iterations(t_data *data);

#endif