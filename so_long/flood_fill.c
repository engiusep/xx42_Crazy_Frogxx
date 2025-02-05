/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:34 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/05 12:52:52 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




int	flood_fill(t_map *map,int x, int y)
{
	if(x < 0 || x >= map->height  || y < 0 || y >= map->width)
		return -1;
	if(map->grid[x][y] == 'F' || (map->grid[x][y] != 'P' && map->grid[x][y] != '0' && map->grid[x][y] != 'C' && map->grid[x][y] != 'E'))
		return 1;
	map->grid[x][y] = 'F';
	printf(" P == %c\n",map->grid[x][y]);
	flood_fill(map,x + 1, y);
	flood_fill(map,x, y + 1);
	flood_fill(map,x - 1, y);
	flood_fill(map,x,y - 1);
	return 0;
}

int check_flood(t_map *map)
{
	int x;
	int y;
	int i;
	i = 0;
	x = -1;
	y = -1;
	find_player_position(map,&x,&y);
	printf("x == %d, y == %d\n",x,y);
	flood_fill(map,x,y);
	while(map->grid[i]!= NULL)
	{
		printf("%s\n",map->grid[i++]);
	}
	return (0);
}


