/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:31:02 by engiusep          #+#    #+#             */
/*   Updated: 2025/02/26 16:54:31 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}			t_map;

typedef struct s_count
{
	int		p;
	int		e;
	int		c;
}			t_count;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*image_ptr_monster;
	void	*image_ptr_perso;
	void	*image_ptr_floor;
	void	*image_ptr_mur;
	void	*image_ptr_exit;
	void	*image_ptr_collectible;
	void	*image_ptr_end;
	int		image_x;
	int		image_y;
	t_map	*map;
}			t_data;

typedef struct s_move
{
	int		player_x;
	int		player_y;
	int		new_x;
	int		new_y;
	int		end_or_not;
}			t_move;

typedef struct s_check
{
	int		i;
	int		j;
	int		x;
	int		y;
	t_count	count;
}			t_check;

void		draw_map(t_map *map, t_data *data);
int			read_map(const char *filename, t_map *map, t_data *data);
int			check_collectible(t_map *map);
void		free_map(t_map *map, int i);
int			ft_strlen_nl(char *str);
int			destroy_all(t_data *data);
int			destroy_image(t_data *data);
int			creat_img(t_data *data);
int			exit_prog(t_data *data);
void		find_player_position(t_map *map, int *player_x, int *player_y);
int			flood_fill(t_map *map, char **grid, int x, int y);
int			check_map(t_map *map, t_data *data);
int			check_all_1(t_map *map);
int			check_col(t_map *map);
int			check_flood(t_map *map, t_data *data);
void		free_cpy(char **cpy, int i);
int			close_window(t_data *data);
void		find_player_position(t_map *map, int *player_x, int *player_y);
int			move_player(t_map *map, t_move *move);
void		moving_player(t_move *move, int keysym, t_data *data);
int			on_keypress(int keysym, t_data *data);
int			destroy_all(t_data *data);
void		put_image(char c, t_data *data, int x, int y);
void		file_image(t_data *data, t_map *map);
char		*cpy_string(t_map *map, char *str);
char		**cpy(t_map *map);

#endif