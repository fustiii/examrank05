#include "life.h"

void	free_array(char **arr, int len)
{
	if (!arr)
		return;
	int i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

char	**alloc_memory( int w, int h)
{
	char	**arr;

	arr = calloc(h + 1, sizeof(char *));
	if (!arr)
		return (NULL);

	int i = 0;
	while (i < h)
	{
		arr[i] = calloc(w, sizeof(char));
		if (!arr[i])
		{
			free_array(arr, i);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

void	print_tab(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->cur[y][x])
				putchar('O');
			else
				putchar(' ');
			x++;
		}
		putchar('\n');
		y++;
	}
}

int read_and_write(t_data *data)
{
	char	c;
	int		pen = 0;
	int		i = 0;
	int		j = 0;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else if (c == 'w' && i > 0)
			i--;
		else if (c == 's' && i < data->height - 1)
			i++;
		else if (c == 'a' && j > 0)
			j--;
		else if (c == 'd' && j < data->width - 1)
			j++;
		if (pen)
			data->cur[i][j] = 1;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	t_data	data;

	data.width = atoi(argv[1]);
	data.height = atoi(argv[2]);
	data.iterations = atoi(argv[3]);

	data.cur = alloc_memory(data.width, data.height);
	if (!data.cur)
	{
		printf("error1\n");
		return (1);
	}
	data.next = alloc_memory(data.width, data.height);
	if (!data.next)
	{
		free_array(data.cur, data.height);
		printf("error2\n");
		return (1);
	}
	
	// Read and write
	if (read_and_write(&data) != 0)
	{
		printf("error2\n");
		return (1);
	}

	// Iterations...
	run_iterations(&data);

	// Print
	print_tab(&data);

	//Free
	free_array(data.cur, data.height);
	free_array(data.next, data.height);

	return (0);
}