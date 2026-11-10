#include "life.h"

void	free_array(char **arr, int h)
{
	if (!arr)
		return;
	
	int	i = 0;
	while (i < h)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**alloc_memory(int h)
{
	char	**arr;

	arr = calloc(sizeof(char *), h);
	if (!arr)
		return (NULL);

	int i = 0;
	while (i < h)
	{
		arr[i] = calloc(sizeof(char *), h);
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

void	print_board(t_data *data)
{
	int	i;
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

	//init
	t_data	data;

	data.width = atoi(argv[1]);
	data.height = atoi(argv[2]);
	data.iterations = atoi(argv[3]);

	data.cur = alloc_memory(data.height);
	if (!data.cur)
	{
		return (1);
	}
	data.next = alloc_memory(data.height);
	if (!data.next)
	{
		free_array(data.cur, data.height);
		return (1);
	}
	read_and_write(&data);

	run_iterations(&data);

	print_board(&data);
	
	//free
	free_array(data.cur, data.height);
	free_array(data.next, data.height);

	return (0);
}