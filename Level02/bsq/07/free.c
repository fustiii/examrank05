#include "bsq.h"

void	free_array(char **arr, int h)
{
	if (!arr)
		return ;

	int i = 0;
	while (i < h)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

void	free_dp(int **dp, int rows)
{
	int i = 0;
	while (i < rows)
	{
		free (dp[i]);
		i++;
	}
	free (dp);
}