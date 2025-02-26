/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:57:01 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/26 16:05:06 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	malloc_grid(t_map *map, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error open fd\n");
		return (-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i == 0)
			map->width = ft_strlen_nl(line);
		i++;
		free(line);
	}
	map->grid = malloc(sizeof(char *) * (i + 1));
	map->grid[i] = NULL;
	close(fd);
	return (0);
}

int	check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.')
		return (1);
	else
	{
		write(2, "ERROR ARGV <map/map.ber>\n", 25);
		exit(1);
	}
}

int	create_map(t_data *data, t_map *map, char *argv_1)
{
	if (malloc_grid(map, argv_1) == -1)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		destroy_all(data);
		free(data->mlx_ptr);
		return (1);
	}
	if (read_map(argv_1, map, data) == -1)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		destroy_all(data);
		free(data->mlx_ptr);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc != 2)
		exit(1);
	data.map = &map;
	check_argv(argv[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.window_ptr = mlx_new_window(data.mlx_ptr, 3000, 2000, "so_long");
	if (!data.window_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.window_ptr, DestroyNotify, StructureNotifyMask, &destroy_all,
		&data);
	file_image(&data, &map);
	if (create_map(&data, &map, argv[1]) == 1)
		exit(1);
	draw_map(&map, &data);
	mlx_hook(data.window_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.window_ptr, 17, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
