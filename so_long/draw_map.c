#include "so_long.h"
#include <stdio.h>
#include <string.h>
//#include "../get_next_line/get_next_line.h"
int read_map(const char *filename,t_map *map)
{
    int fd;
    int i;
    int j;
    char *line;
    i = 0;
    fd = open(filename,O_RDONLY);
    if(fd < 0)
    {
        perror("Error open fd\n");
        return (0);
    }
    while((line = get_next_line(fd)) != NULL)
    {
        j = 0;
        while(line[j] != '\0' && line[j] != '\n')
        {
            map->grid[i][j] = line[j];
            j++;
        }
        map->grid[i][j] = '\0';
        free(line);
        i++; 
    }
    map->height = i;
    map->width = strlen(map->grid[0]);
    close (fd);
    return(0);
}

void draw_map(t_map *map, t_data *data)
{
    int i;
    int j;
    int x;
    int y;
    i = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            x = j * 82;
            y = i * 82;
            if(map->grid[i][j] == 'P')
                mlx_put_image_to_window(data->mlx_ptr,data->window_ptr,data->image_ptr_perso, x, y);
            else if(map->grid[i][j] == '0')
                mlx_put_image_to_window(data->mlx_ptr,data->window_ptr, data->image_ptr_floor, x, y);
            else if(map->grid[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr,data->window_ptr,data->image_ptr_mur, x, y);
            j++;
        }
        i++;
    }
}