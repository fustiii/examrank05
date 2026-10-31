#include "life.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	free_array(char **arr, int row)
{
	if (!arr)
		return;
	int i = 0;
	while (i < row)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

char	**alloc_memory(int width, int height)
{
	char	**arr;

	arr = calloc(sizeof(char *), height);
	if (!arr)
		return (NULL);

	int i = 0;
	while (i < height)
	{
		arr[i] = calloc(sizeof(char), width);
		if (!arr[i])
		{
			free_array(arr, i);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

int	read_and_write(t_data *data)
{
	char	c;
	int		i = 0;
	int		j = 0;
	int		pen;

	pen = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else if (c == 'w' && i - 1 >= 0)
			i--;
		else if (c == 's' && i + 1 < data->height)
			i++;
		else if (c == 'a' && j - 1 >= 0)
			j--;
		else if (c == 'd' && j + 1 < data->width)
			j++;
		if (pen)
			data->cur[i][j] = 1;
	}
	return (0);
}

void	print_board(t_data *data)
{
	int i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->cur[i][j])
				putchar('O');
			else
				putchar(' ');
			j++;
		}
		putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	t_data data;

	data.width = atoi(argv[1]);
	data.height = atoi(argv[2]);
	data.iterations = atoi(argv[3]);

	data.cur = alloc_memory(data.width, data.height);
	if (!data.cur)
		return (1);

	data.next = alloc_memory(data.width, data.height);
	if (!data.next)
	{
		free_array(data.cur, data.height);
		return (1);
	}

	if (read_and_write(&data) != 0)
	{
		free_array(data.cur, data.height);
		free_array(data.next, data.height);
		return (1);
	}

	run_iterations(&data);

	print_board(&data);

	//freeall
	free_array(data.cur, data.height);
	free_array(data.next, data.height);

	return (0);
}