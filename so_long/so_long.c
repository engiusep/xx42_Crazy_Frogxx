#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

int destroy_all(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr,data->window_ptr);
    free(data->mlx_ptr);
    exit (0);
    return (0);
}
void    find_player_position(t_map *map, int *player_x,int *player_y)
{
    int i;
    int j;
    i = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            if(map->grid[i][j] == 'P')
            {
                *player_x = j;
                *player_y = i;
                return;
            }
            j++;
        }
        i++;
    }
}
void move_player(t_map *map,int new_x,int new_y,int old_x,int old_y)
{
    if(map->grid[new_y][new_x] == '0')
    {
        map->grid[old_y][old_x] = '0';
        map->grid[new_y][new_x] = 'P';
    }
}
int on_keypress(int keysym, t_data *data)
{
    t_map *map;
    int player_x = -1;
    int player_y = -1;
    int new_x;
    int new_y;
    find_player_position(data->map, &player_x, &player_y);
    new_x = player_x;
    new_y = player_y;

    if(keysym == 123) //fleche de gauche
        new_x -= 1;
    else if(keysym == 126) // fleche haut
        new_y -= 1;
    else if(keysym == 124) // fleche droite
        new_x += 1;
    else if(keysym == 125) //fleche bas
        new_y += 1;
    if(new_x >= 0 && new_x < data->map->width && new_y >= 0 && new_y < data->map->width)
    {
        move_player(data->map, new_x, new_y, player_x, player_y);
    }
    mlx_clear_window(data->mlx_ptr,data->window_ptr);
    draw_map(data->map,data);
    printf("Presse une touche: %d\n",keysym);
    return (0);
}



int main(void)
{

    t_data data;
    t_map map;
    int temp_x;
    int temp_y;
    data.map = &map;
    read_map("map/map.ber",&map);
    data.mlx_ptr = mlx_init();
    if(!data.mlx_ptr)
        return (1);
    data.window_ptr = mlx_new_window(data.mlx_ptr, 480, 480 ,"Salut");
    if(!data.window_ptr)
        return(free(data.mlx_ptr),1);
    
    // data.image_x = 600;
    // data.image_y = 300;
    // data.x_1 = 1100;
    // data.y_1 = 600;
    mlx_hook(data.window_ptr, DestroyNotify, StructureNotifyMask, &destroy_all, &data);
    data.image_ptr_perso = mlx_xpm_file_to_image(data.mlx_ptr,"image/player.xpm", &map.width ,&map.height);
    data.image_ptr_floor = mlx_xpm_file_to_image(data.mlx_ptr,"image/floor.xpm", &map.width,&map.height);
    data.image_ptr_mur = mlx_xpm_file_to_image(data.mlx_ptr,"image/wall.xpm", &map.height, &map.width); 
    draw_map(&map, &data);
    mlx_hook(data.window_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}

