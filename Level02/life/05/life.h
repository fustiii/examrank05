#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
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