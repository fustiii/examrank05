#include "life.h"

int		count_vecinos(t_data *data, int y, int x)
{
	int	dy;
	int	dx;
	int	ny;
	int	nx;
	int	count = 0;

	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			ny = y + dy;
			nx = x + dx;
			if (!(dy == 0 && dx == 0)
				&& ny >= 0 && ny < data->height
				&& nx >= 0 && nx < data->width
				&& data->cur[ny][nx])
				count++;
			dx++;
		}
		dy++;
	}
	return (count);
}

void	run_iterations(t_data *data)
{
	int	it;
	int	i;
	int	j;
	int	n;
	char	**tmp;

	it = 0;
	while (it < data->iterations)
	{
		i = 0;
		while (i < data->height)
		{
			j = 0;
			while (j < data->width)
			{
				n = count_vecinos(data, i, j);
				if (data->cur[i][j])
					data->next[i][j] = (n == 2 || n == 3);
				else
					data->next[i][j] = (n == 3);
				j++;
			}
			i++;
		}
		tmp = data->cur;
		data->cur = data->next;
		data->next = tmp;
		it++;
	}
}