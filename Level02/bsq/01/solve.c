#include "bsq.h"

int min3(int up, int left, int diagonal)
{
	int res = up;

	if (left < res)
		res = left;
	if (diagonal < res)
		res = diagonal;
	return (res);
}

int	find_square(t_map *map, t_square *square)
{
	int **dp;
	int	i;
	int	j;

	//Initialize the memory for dp
	dp = malloc(sizeof(int *) * map->rows);
	if (!dp)
		return (1);

	i = 0;
	while (i < map->rows)
	{
		dp[i] = malloc(sizeof(int) * map->cols);
		if (!dp[i])
		{
			free_dp(dp, i);
			return (1);
		}
		i++;
	}

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			//si es un obstaculo
			if (map->map[i][j] == map->obstacle)
			{
				dp[i][j] = 0;
			}
			//is first row or first col
			else if (i == 0 || j == 0)
			{
				dp[i][j] = 1;
			}
			//formulilla
			else
			{
				dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
			}
			//update square
			if (dp[i][j] > square->size)
			{
				square->size = dp[i][j];
				square->x = i;
				square->y = j;
			}
			j++;
		}
		i++;
	}
	free_dp(dp, i);
	return (0);
}

void fill_square(t_map *map, t_square *square)
{
	int i;
	int j;

	i = square->x - (square->size - 1);
	while (i <= square->x)
	{
		j = square->y - (square->size - 1);
		while (j <= square->y)
		{
			map->map[i][j] = map->full;
			j++;
		}
		i++;
	}
}

int solve(t_map *map)
{
	t_square square;

	init_square(&square);

	if (find_square(map, &square) != 0)
		return (1);

	fill_square(map, &square);

	return (0);
}