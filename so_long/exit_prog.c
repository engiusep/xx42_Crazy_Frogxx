/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:02:59 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/23 15:03:57 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_prog(t_data *data)
{
	free_map(data->map,data->map->height);
    mlx_destroy_window(data->mlx_ptr,data->window_ptr);
    destroy_all(data);
    free(data->mlx_ptr);
    exit(0);
}