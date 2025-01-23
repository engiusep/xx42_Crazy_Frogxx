#include "so_long.h"
#include <stdio.h>
#include <string.h>

int check_collectible(t_map *map)
{
    t_count count;
    int i;
    int j;
    i = 0;
    j = 0;
    count.C = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            if(map->grid[i][j] == 'C')
                count.C++;
            j++;
        }
        i++;
    }
    return (count.C);
}
int check_col(t_map *map)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while(i < map->height - 1)
    {
        if(map->grid[i][0] != '1')
            return (-1);
        else if(map->grid[i][map->width - 1] != '1')
            return (-1);
        i++;
    }
    return (0);
}
int check_all_1(t_map *map)
{
    int i;
    int j;
    j = 0;
    i = 0;

    while(map->grid[0][j])
    {
        if(map->grid[0][j] != '1' && map->grid[0][j] != '\n')
            return(-1);
        j++;
    }
    j = 0;
    while(map->grid[map->height - 1][j])
    {
        if(map->grid[map->height - 1][j] != '1')
            return(-1);
        j++;
    }
    if(check_col(map) == -1)
        return(-1);
    return (0);
}

int check_map(t_map *map)
{
    t_count count;
    int i;
    int j;
    i = 0;
    j = 0;
    count.P = 0;
    count.E = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            if(map->grid[i][j] == 'P')
                count.P++;
            if(map->grid[i][j] == 'E')
                count.E++;
            j++;
        }
        i++;
    }
    if(count.P > 1 || count.E > 1)
    {
        write(1, "ERROR MAP\n",11);
        exit(0);
    }
    return 0;
}
void read_map(const char *filename, t_map *map,t_data *data)
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
        map->grid[i] = ft_strdup(line);
        if(ft_strlen_nl(line) != map->width)
            {
                free_map(map,i);
                free(line);
                write(1,"ERROR MAP\n",11);
                exit(0);
            }
        free(line);
        i++;
    }
    map->grid[i] = NULL;
    map->height = i;
    check_map(map);
    if(check_all_1(map) == -1)
    {
       write(1,"ERROR\n",6);
       destroy_all(data);
       exit(0);
    }
    close (fd);
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
