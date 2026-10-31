#include "life.h"

int	count_vecinos(t_data *data, int y, int x)
{
	int	count;
	int	dy;
	int	dx;
	int	ny;
	int	nx;

	count = 0;
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
	int		it;
	int		y;
	int		x;
	int		n;
	char	**tmp;

	it = 0;
	while (it < data->iterations)
	{
		y = 0;
		while (y < data->height)
		{
			x = 0;
			while (x < data->width)
			{
				n = count_vecinos(data, y, x);
				if (data->cur[y][x])
					data->next[y][x] = (n == 2 || n == 3);
				else
					data->next[y][x] = (n == 3);
				x++;
			}
			y++;
		}
		tmp = data->cur;
		data->cur = data->next;
		data->next = tmp;
		it++;
	}
}