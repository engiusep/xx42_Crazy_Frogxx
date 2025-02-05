/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:02:36 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/05 14:33:42 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map,int i)
{
	int j;
	j = 0;
	while(j < i)
	{
		free(map->grid[j]);
		j++;
	}
	free(map->grid);
}
void	free_cpy(char **cpy,int i)
{
	int j;
	j = 0;
	while(j < i)
	{
		free(cpy[j]);
		j++;
	}
	free(cpy);
}