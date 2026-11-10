#include "bsq.h"

void free_array(char **arr, int row)
{
	if (!arr)
		return ;

	int i = 0;
	while (i < row)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void free_dp(int **dp, int row)
{
	int i = 0;
	while (i < row)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}