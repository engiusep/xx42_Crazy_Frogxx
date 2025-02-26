/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:45:54 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/26 16:54:49 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player_position(t_map *map, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				*player_x = j;
				*player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	move_player(t_map *map, t_move *move)
{
	int	i;

	i = 0;
	if (map->grid[move->new_y][move->new_x] == '0')
	{
		map->grid[move->player_y][move->player_x] = '0';
		map->grid[move->new_y][move->new_x] = 'P';
		return (0);
	}
	else if (map->grid[move->new_y][move->new_x] == 'C')
	{
		map->grid[move->player_y][move->player_x] = '0';
		map->grid[move->new_y][move->new_x] = 'P';
		i++;
		return (0);
	}
	else if (map->grid[move->player_y][move->new_x] == 'E'
		&& check_collectible(map) == -1)
	{
		map->grid[move->player_y][move->player_x] = '0';
		map->grid[move->new_y][move->new_x] = 'P';
		return (1);
	}
	return (0);
}

void	moving_player(t_move *move, int keysym, t_data *data)
{
	static int i;

	if (keysym == 97 || keysym == 119 || keysym == 100 || keysym == 115)
		i++;
	if (keysym == 97)
		move->new_x -= 1;
	else if (keysym == 119)
		move->new_y -= 1;
	else if (keysym == 100)
		move->new_x += 1;
	else if (keysym == 115)
		move->new_y += 1;
	else if (keysym == 65307)
		exit_prog(data);
	ft_printf("%d\n",i);
}

int	on_keypress(int keysym, t_data *data)
{
	t_move	move;
	
	move.player_x = -1;
	move.player_y = -1;
	move.end_or_not = 0;
	find_player_position(data->map, &move.player_x, &move.player_y);
	move.new_x = move.player_x;
	move.new_y = move.player_y;
	moving_player(&move, keysym, data);
	if (move.new_x >= 0 && move.new_x < data->map->width && move.new_y >= 0
		&& move.new_y < data->map->width)
		move.end_or_not = move_player(data->map, &move);
	if (move.end_or_not == 0)
		draw_map(data->map, data);
	else
		exit_prog(data);
	return (0);
}
