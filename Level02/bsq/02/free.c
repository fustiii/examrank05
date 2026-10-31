#include "bsq.h"

void free_dp(int **dp, int rows)
{
	int i = 0;
	while (i < rows)
	{
		free (dp[i]);
		i++;
	}
	free (dp);
}

void free_array(char **array)
{
	if (!array)
		return ;
	int i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
}