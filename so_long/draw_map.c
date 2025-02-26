#include "so_long.h"
#include <stdio.h>
#include <string.h>

int	read_lines(t_map **map, int fd)
{
	int		i;
	t_map	*temp;
	char	*line;

	temp = *map;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen_nl(line) != temp->width)
		{
			free_map(*map, i);
			free(line);
			write(2, "ERROR MAP\n", 11);
			return (-1);
		}
		temp->grid[i] = ft_strdup(line);
		free(line);
		i++;
	}
	temp->grid[i] = NULL;
	temp->height = i;
	return (0);
}

int	read_map(const char *filename, t_map *map, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error open fd\n");
		exit(1);
	}
	if(read_lines(&map, fd) == -1)
		return (-1);
	check_map(map, data);
	if (check_all_1(map) == -1)
	{
		write(1, "ERR0R\n", 6);
		exit_prog(data);
		exit(1);
	}
	close(fd);
	return (0);
}
void	put_image(char c, t_data *data, int x, int y)
{
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image_ptr_perso, x, y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image_ptr_floor, x, y);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image_ptr_mur, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image_ptr_exit, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->image_ptr_collectible, x, y);
}
void	draw_map(t_map *map, t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;
	t_count	count;

	count.P = 1;
	count.E = 1;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			x = j * 200;
			y = i * 200;
			put_image(map->grid[i][j], data, x, y);
			j++;
		}
		i++;
	}
}
