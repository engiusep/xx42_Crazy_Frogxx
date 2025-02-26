#include "so_long.h"
#include <stdio.h>
#include <string.h>


int read_map(const char *filename, t_map *map,t_data *data)
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
        if(ft_strlen_nl(line) != map->width)
        {
            free_map(map,i);
            free(line);
            write(1,"ERROR MAp\n",11);
            return -1;
        }
        map->grid[i] = ft_strdup(line);
        free(line);
        i++;
    }
    map->grid[i] = NULL;
    map->height = i;
    check_map(map,data);
    if(check_all_1(map) == -1)
    {
       write(1,"ERROR\n",6);
       destroy_all(data);
       return -1;
    }
    close (fd);
    return 0;
}

void draw_map(t_map *map, t_data *data)
{
    int i;
    int j;
    int x;
    int y;
    t_count count;
    count.P = 1;
    count.E = 1;
    i = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            x = j * 200;
            y = i * 200;
            if(map->grid[i][j] == 'P')
                mlx_put_image_to_window(data->mlx_ptr,data->window_ptr,data->image_ptr_perso, x, y);
            else if(map->grid[i][j] == '0')
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->image_ptr_floor, x, y);
            else if(map->grid[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,data->image_ptr_mur, x, y);
            else if(map->grid[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->image_ptr_exit, x, y);
            else if(map->grid[i][j] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->image_ptr_collectible, x, y);
            j++;
        }
        i++;
    }
}
