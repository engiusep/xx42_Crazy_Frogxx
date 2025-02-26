/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:34 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/26 16:11:14 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	flood_fill(t_map *map, char **grid, int y, int x)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (-1);
	if (grid[y][x] == 'F' || (grid[y][x] != 'P' && grid[y][x] != '0'
			&& grid[y][x] != 'C' && grid[y][x] != 'E'))
		return (1);
	grid[y][x] = 'F';
	flood_fill(map, grid, y + 1, x);
	flood_fill(map, grid, y, x + 1);
	flood_fill(map, grid, y - 1, x);
	flood_fill(map, grid, y, x - 1);
	return (0);
}

int	check_collectible_flood(t_map *map, char **grid, t_data *data, char **grid2)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (grid[i][j] == 'F' || grid[i][j] == '1')
			{
				j++;
			}
			else
			{
				write(2, "Error\n", 7);
				free_cpy(grid, map->height);
				free_cpy(grid2, map->height);
				exit_prog(data);
				exit(1);
			}
		}
		i++;
	}
	return (0);
}

int	check_collectible_flood_2(t_map *map, char **grid, t_data *data,
		char **cpy_grid2)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (grid[i][j] == 'F' || grid[i][j] == '1' || grid[i][j] == 'E'
				|| grid[i][j] == '0')
				j++;
			else
			{
				write(2, "Error\n", 7);
				free_cpy(grid, map->height);
				free_cpy(cpy_grid2, map->height);
				exit_prog(data);
				exit(1);
			}
		}
		i++;
	}
	return (0);
}

void	check_grid(t_map *map, char **grid, t_data *data, char **cpy_grid2)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (grid[i][j] == '1' || grid[i][j] == 'E' || grid[i][j] == '0'
				|| grid[i][j] == 'P' || grid[i][j] == 'C')
				j++;
			else
			{
				write(2, "Errot\n", 7);
				free_cpy(grid, map->height);
				free_cpy(cpy_grid2, map->height);
				exit_prog(data);
				exit(1);
			}
		}
		i++;
	}
}

int	check_flood(t_map *map, t_data *data)
{
	int		x;
	int		y;
	int		i;
	char	**cpy_grid;
	char	**cpy_grid2;

	i = 0;
	x = -1;
	y = -1;
	find_player_position(map, &x, &y);
	cpy_grid = cpy(map);
	cpy_grid2 = cpy(map);
	check_grid(map, cpy_grid, data, cpy_grid2);
	flood_fill(map, cpy_grid2, y, x);
	check_collectible_flood_2(map, cpy_grid2, data, cpy_grid);
	flood_fill(map, cpy_grid, y, x);
	check_collectible_flood(map, cpy_grid, data, cpy_grid2);
	free_cpy(cpy_grid, map->height);
	free_cpy(cpy_grid2, map->height);
	return (0);
}
