#include "life.h"

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

void	free_array(char **arr, int rows)
{
	if (!arr)
		return ;
	int i = 0;
	while (i < rows)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}


char	**alloc_memory(int width, int height)
{
	char **arr;
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
	int		i = 0;
	int		j = 0;
	int		pen = 0;

	//! Hacer man de read: leemos de stdin(0) y 1 byte cada vez 
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
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	t_data	data;

	data.width = atoi(argv[1]);
	data.height = atoi(argv[2]);
	data.iterations = atoi(argv[3]);

	if (data.width <= 0 || data.height <= 0)
		return (1);

	data.cur = alloc_memory(data.width, data.height);
	if (!data.cur)
	{
		return (1);
	}

	data.next = alloc_memory(data.width, data.height);
	if (!data.next)
	{
		free_array(data.cur, data.height);
		return (1);
	}

	read_and_write(&data);

	run_iterations(&data);

	print_board(&data);

	free_array(data.cur, data.height);
	free_array(data.next, data.height);

	return (0);
}