#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

int destroy_all(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr,data->image_ptr_mur);
    mlx_destroy_image(data->mlx_ptr,data->image_ptr_exit);
    mlx_destroy_image(data->mlx_ptr,data->image_ptr_collectible);
    mlx_destroy_image(data->mlx_ptr,data->image_ptr_end);
    mlx_destroy_image(data->mlx_ptr,data->image_ptr_perso);
    mlx_destroy_image(data->mlx_ptr,data->image_ptr_floor);
    mlx_destroy_display(data->mlx_ptr);
    return (0);
}

void    find_player_position(t_map *map, int *player_x, int *player_y)
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

int move_player(t_map *map,int new_x,int new_y,int old_x,int old_y)
{
    int  i;
    i = 0;
    if(map->grid[new_y][new_x] == '0')
    {
        map->grid[old_y][old_x] = '0';
        map->grid[new_y][new_x] = 'P';
        return (0);
    }
    else if(map->grid[new_y][new_x] == 'C')
    {
        map->grid[old_y][old_x] = '0';
        map->grid[new_y][new_x] = 'P';
        i++;
        return (0);
    }
    else if(map->grid[new_y][new_x] == 'E' && check_collectible(map) == i)
    {
        map->grid[old_y][old_x] = '0';
        map->grid[new_y][new_x] = 'P';
        return (1);
    }
    return (0);

}

int on_keypress(int keysym, t_data *data)
{
    int player_x = -1;
    int player_y = -1;
    int new_x;
    int new_y;
    int end_or_not;
    end_or_not = 0;
    find_player_position(data->map, &player_x, &player_y);
    new_x = player_x;
    new_y = player_y;

    if(keysym == 97) //fleche de gauche
        new_x -= 1;
    else if(keysym == 119) // fleche haut
        new_y -= 1;
    else if(keysym == 100) // fleche droite
        new_x += 1;
    else if(keysym == 115) //fleche bas
        new_y += 1;
    else if(keysym == 65307)
        exit_prog(data);
    if(new_x >= 0 && new_x < data->map->width && new_y >= 0 && new_y < data->map->width)
        end_or_not = move_player(data->map, new_x, new_y, player_x, player_y);
    if(end_or_not == 0)
        draw_map(data->map,data);
    else
        exit_prog(data);
    printf("Presse une touche: %d\n",keysym);
    return (0);
}

int ft_strlen_nl(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0' && str[i] != '\n')
        i++;
    return (i);
}

void    malloc_grid(t_map *map, char *filename)
{
    int fd;
    int i;
    char *line;
    i = 0;
    fd = open(filename,O_RDONLY);
    if(fd < 0)
    {
        perror("Error open fd\n");
        exit(1);
    }
    
    while(1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        if(i == 0)
            map->width = ft_strlen_nl(line);
        i++;
        free(line);
    }
    map->grid = malloc(sizeof(char *) * (i + 1));
    map->grid[i] = NULL;
    close (fd);
}
int    close_window(t_data *data)
{
    exit_prog(data);
    return (0);
}
int main(void)
{

    t_data data;
    t_map map;
    data.map = &map;
    data.mlx_ptr = mlx_init();
    if(!data.mlx_ptr)
        return (1);
    data.window_ptr = mlx_new_window(data.mlx_ptr, 2000, 1000 ,"so_long");
    if(!data.window_ptr)
        return(free(data.mlx_ptr),1);
    mlx_hook(data.window_ptr, DestroyNotify, StructureNotifyMask, &destroy_all, &data);
    data.image_ptr_perso = mlx_xpm_file_to_image(data.mlx_ptr,"image/player.xpm", &map.width ,&map.height);
    data.image_ptr_floor = mlx_xpm_file_to_image(data.mlx_ptr,"image/sol.xpm", &map.width,&map.height);
    data.image_ptr_mur = mlx_xpm_file_to_image(data.mlx_ptr,"image/wall.xpm", &map.height, &map.width); 
    data.image_ptr_exit = mlx_xpm_file_to_image(data.mlx_ptr,"image/zaap.xpm", &map.width, &map.height);
    data.image_ptr_collectible = mlx_xpm_file_to_image(data.mlx_ptr,"image/collecte.xpm",&map.width,&map.height);
    data.image_ptr_end = mlx_xpm_file_to_image(data.mlx_ptr,"image/end.xpm",&map.width,&map.height);
    malloc_grid(&map,"map/map.ber");
    read_map("map/map.ber",&map,&data);
    draw_map(&map, &data);
    mlx_hook(data.window_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
    mlx_hook(data.window_ptr,17,0,&close_window,&data);
    mlx_loop(data.mlx_ptr);
    return (0);
}

