/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:34 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/23 16:30:12 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




int	flood_fill(t_map *map,int x, int y)
{
	// int player_x;
	// int player_y;
	// int count;
	// count = 1;
	// if(count == 1)
	// {
	// 	player_x = -1;
    // 	player_y = -1;
	// 	find_player_position(map, &player_x,&player_y);
	// 	x = player_x;
	// 	y = player_y;
	// 	count++;
	// }
	
	if(x < 0 || x > map->height - 1 || y < 0 || y > map->width - 1)
		return(1);
	
	if(map->grid[x][y] == 'F' || (map->grid[x][y] != 'P' && map->grid[x][y] != '0' && map->grid[x][y] != 'C' && map->grid[x][y] != 'E'))
		return (1);
	
	map->grid[x][y] = 'F';
	flood_fill(map,x + 1, y);
	flood_fill(map,x, y + 1);
	flood_fill(map,x - 1, y);
	flood_fill(map,x,y - 1);
	//printf("[%d][%d]",player_x,player_y);
	return (0);
}