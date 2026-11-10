#include "life.h"

void	free_array(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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

char **alloc_memory(char **arr, int height, int width)
{
	int i;

	arr = calloc(sizeof(char *), height);
	if (!arr)
		return (NULL);

	i = 0;
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

void	read_and_write(t_data *data)
{
	char	c;
	int		i;
	int		j;
	int		pen = 0;
	while (getline(1, &c, 0) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else if (c == 'w' && i - 1 >= 0)
			i--;
		else if (c == 's' && i + 1 < data->height)
			i++;
		else if (c == 'a' && j - 1 >= 0)
			j--;
		else if (c == 'd' && j + 1 < data->height)
			j++;
		if (pen)
			data->cur[i][j] = 1;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	//init
	t_data data;

	data.width = atoi(argv[1]);
	data.height = atoi(argv[2]);
	data.iterations = atoi(argv[3]);

	data.cur = alloc_memory(data.cur, data.height, data.width);
	if (!data.cur)
	{
		return (1);
	}

	data.next = alloc_memory(data.next, data.height, data.width);
	if (!data.next)
	{
		free_array(data.cur, data.height);
		return (1);
	}


	read_and_write(&data);

	run_iterations(&data);

	print_board();

	//free

	return (0);
}