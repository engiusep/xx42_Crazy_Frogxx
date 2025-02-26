/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:02:59 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/26 16:01:19 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_all(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image_ptr_mur);
	mlx_destroy_image(data->mlx_ptr, data->image_ptr_exit);
	mlx_destroy_image(data->mlx_ptr, data->image_ptr_collectible);
	mlx_destroy_image(data->mlx_ptr, data->image_ptr_end);
	mlx_destroy_image(data->mlx_ptr, data->image_ptr_perso);
	mlx_destroy_image(data->mlx_ptr, data->image_ptr_floor);
	mlx_destroy_display(data->mlx_ptr);
	return (0);
}

int	exit_prog(t_data *data)
{
	free_map(data->map, data->map->height);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	destroy_all(data);
	free(data->mlx_ptr);
	exit(0);
}

int	close_window(t_data *data)
{
	exit_prog(data);
	return (0);
}

void	free_map(t_map *map, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(map->grid[j]);
		j++;
	}
	free(map->grid);
}

void	free_cpy(char **cpy, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(cpy[j]);
		j++;
	}
	free(cpy);
}
