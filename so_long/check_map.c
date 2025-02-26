/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:15:27 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/26 13:40:26 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_collectible(t_map *map)
{
    int count;
    int i;
    int j;
    i = 0;
    j = 0;
    count = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            if(map->grid[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
	if(count < 1)
        return (-1);
    return (count);
}
int check_col(t_map *map)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while(i < map->height - 1)
    {
        if(map->grid[i][0] != '1')
            return (-1);
        else if(map->grid[i][map->width - 1] != '1')
            return (-1);
        i++;
    }
    return (0);
}
int check_all_1(t_map *map)
{
    int i;
    int j;
    j = 0;
    i = 0;

    while(map->grid[0][j])
    {
        if(map->grid[0][j] != '1' && map->grid[0][j] != '\n')
            return(-1);
        j++;
    }
    j = 0;
    while(map->grid[map->height - 1][j])
    {
        if(map->grid[map->height - 1][j] != '1')
            return(-1);
        j++;
    }
    if(check_col(map) == -1)
        return(-1);
    return (0);
}

int check_map(t_map *map,t_data *data)
{
    t_count count;
    int i;
    int j;
	int x;
	int y;
	x = -1;
	y = -1;
    i = 0;
    j = 0;
    count.P = 0;
    count.E = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            if(map->grid[i][j] == 'P')
                count.P++;
            if(map->grid[i][j] == 'E')
                count.E++;
            j++;
        }
        i++;
    }
    count.C = check_collectible(map);
    if(count.P > 1 || count.E > 1 || count.C == -1)
    {
        write(1, "ERROR MAP\n",11);
        exit_prog(data);
        exit(1);
    }
	check_flood(map,data);
    return 0;
}
