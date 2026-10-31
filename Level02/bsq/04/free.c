#include "bsq.h"

void	free_array(char **arr, int len)
{
	if (!arr)
		return ;

	int i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void free_dp(int **dp, int len)
{
	int i = 0;
	while (i < len)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
