





#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef MAX_MAP_SIZE
# define MAX_MAP_SIZE 1000
# endif

typedef struct s_map
{
    char grid[MAX_MAP_SIZE][MAX_MAP_SIZE];
    int width;
    int height;
}t_map;

typedef struct s_data
{
    void *mlx_ptr;
    void  *window_ptr;
    void *image_ptr_monster;
    void *image_ptr_perso;
    void *image_ptr_floor;
    void *image_ptr_mur;
    int image_x;
    int image_y;
    int x_1;
    int y_1;
    t_map *map;
}t_data;

void draw_map(t_map *map, t_data *data);
int read_map(const char *filename,t_map *map);
#endif