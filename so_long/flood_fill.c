/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:34 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/05 17:02:20 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_map *map,char **grid, int y, int x)
{
	if(x < 0 || x >= map->width || y < 0 || y >= map->height)
		return -1;
		
	if(grid[y][x] == 'F' || (grid[y][x] != 'P' && grid[y][x] != '0' && grid[y][x] != 'C' && grid[y][x] != 'E'))
		return 1;
		
	grid[y][x] = 'F';
	flood_fill(map,grid,y + 1, x);
	flood_fill(map,grid,y, x + 1);
	flood_fill(map,grid,y - 1, x);
	flood_fill(map,grid,y,x - 1);
	
	return 0;
}
char *cpy_string(t_map *map,char *str)
{
	int i;
	char *cpy;
	i = 0;
	(void)map;
	cpy = malloc(ft_strlen(str) + 1);
	if(!cpy)
		return (NULL);
	while(str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
char **cpy(t_map *map)
{
	int i;
	int j;
	char **cpy;
	i = 0;
	j = 0;
	cpy = malloc((map->height + 1) * sizeof(char *));
	if(!cpy)
		return (NULL);
	while(i < map->height)
	{
		cpy[i] = cpy_string(map,map->grid[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
int check_collectible_flood(t_map *map,char **grid,t_data *data)
{
    int i;
    int j;
	
    i = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            if(grid[i][j] == 'F' || grid[i][j] == '1')
            	j++;
			else
			{
				write(2,"ERRORR MAP\n",13);
				free_cpy(grid,map->height);
				exit_prog(data);
				exit(0);
			}
        }
        i++;
    }
    return (0);
}
int check_flood(t_map *map,t_data *data)
{
	int x;
	int y;
	int i;
	char **cpy_grid;
	i = 0;
	x = -1;
	y = -1;
	(void)data;
	find_player_position(map,&x,&y);
	cpy_grid = cpy(map);
	flood_fill(map, cpy_grid, y, x);
	//while(cpy_grid[i])
	//	printf("%s\n",cpy_grid[i++]);
	check_collectible_flood(map,cpy_grid,data);
	free_cpy(cpy_grid,map->height);
	return (0);
}



