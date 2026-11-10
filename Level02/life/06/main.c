#include "life.h"

char	**alloc_memory(char **arr, int h, int w)
{
	arr = calloc(h, sizeof(char *));
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

void	read_and_write(t_data *data)
{
	char	c;
	int		i;
	int		j;
	int		pen = 0;

	while (read(1, &c, 0) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else if (c == 'w' && i - 1 >= 0)
			i--;
		else if (c == 's' && j + 1 < data->height)
			i++;
		else if (c == 'a' && i - 1 >= 0)
			j--;
		else if (c == 'd' && j + 1 < data->width)
			j++;
		if (pen)
			data->cur[i][j] = 1;
	}
}

int main(int argc, char **argv)
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
		//free
		return (1);
	}

	data.next = alloc_memory(data.next, data.height, data.width);
	if (!data.next)
	{
		//free
		return (1);
	}

	read_and_write(&data);

	run_iterations(&data);


	//print


	//free
}