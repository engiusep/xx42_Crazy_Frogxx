/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:52:10 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/26 16:11:16 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	file_image(t_data *data, t_map *map)
{
	data->image_ptr_perso = mlx_xpm_file_to_image(data->mlx_ptr,
			"image/player.xpm", &map->width, &map->height);
	data->image_ptr_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"image/sol.xpm", &map->width, &map->height);
	data->image_ptr_mur = mlx_xpm_file_to_image(data->mlx_ptr, "image/wall.xpm",
			&map->height, &map->width);
	data->image_ptr_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"image/zaap.xpm", &map->width, &map->height);
	data->image_ptr_collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"image/collecte.xpm", &map->width, &map->height);
	data->image_ptr_end = mlx_xpm_file_to_image(data->mlx_ptr, "image/end.xpm",
			&map->width, &map->height);
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
