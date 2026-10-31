#ifndef LIFE_H
#define LIFE_H

typedef struct s_data
{
	int		width;
	int		height;
	int		iterations;
	char	**cur;
	char	**next;
}	t_data;

void	run_iterations(t_data *data);

#endif