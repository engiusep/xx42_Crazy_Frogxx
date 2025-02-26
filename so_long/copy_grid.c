/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:55:16 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/26 16:00:36 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*cpy_string(t_map *map, char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	(void)map;
	cpy = malloc(ft_strlen(str) + 1);
	if (!cpy)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**cpy(t_map *map)
{
	int		i;
	int		j;
	char	**cpy;

	i = 0;
	j = 0;
	cpy = malloc((map->height + 1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	while (i < map->height)
	{
		cpy[i] = cpy_string(map, map->grid[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
