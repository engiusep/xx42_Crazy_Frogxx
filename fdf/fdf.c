/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:30:24 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/31 15:12:06 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_linux/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include <X11/keysym.h>

typedef struct s_data {
    void *mlx;
    void *win;
    int x1; // Position actuelle du premier point du segment en X
    int y1; // Position actuelle du premier point du segment en Y
    int x2; // Position actuelle du second point du segment en X
    int y2; // Position actuelle du second point du segment en Y
} t_data;

void draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    int steps = fmax(fabs(dx), fabs(dy)); // Nombre d'étapes
    double x_inc = dx / steps;           // Incrément en x
    double y_inc = dy / steps;           // Incrément en y
    double x = x1;
    double y = y1;
	int i;
	i = 0;

    while (i <= steps)
    {
        mlx_pixel_put(mlx, win, round(x), round(y), 0xFFFFFF); // Dessiner le pixel (blanc)
        x += x_inc;
        y += y_inc;
		i++;
    }
}

int key_hook(int keycode, t_data *data)
{
    if (keycode == XK_Escape) // Touche ESC pour quitter
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (keycode == XK_Right) // Flèche droite
    {
        data->x1 -= 30;
        data->x2 -= 30;
    }
    else if (keycode == XK_Left) // Flèche left
    {
        data->x1 += 30;
        data->x2 += 30;
    }
    else if (keycode == XK_Down) // Flèche bas
    {
        data->y1 -= 30;
        data->y2 -= 30;
    }
    else if (keycode == XK_Up) // Flèche haut
    {
        data->y1 += 30;
        data->y2 += 30;
    }

    // Efface la fenêtre
    mlx_clear_window(data->mlx, data->win);

    // Redessine le segment à la nouvelle position
    draw_line(data->mlx, data->win, data->x1, data->y1, data->x2, data->y2);

    return 0;
}

int main()
{
	t_data data;	
    void *mlx;       // Pointeur pour la connexion à la minilibx
    void *window; 
	data.mlx = mlx_init();
    data.x1 = 200; // Position initiale du premier point
    data.y1 = 200;
    data.cdx2 = 400; // Position initiale du second point
    data.y2 = 400;   // Pointeur pour la fenêtre
    // Initialiser la connexion à la miniLibX
    mlx = mlx_init();
    if (!mlx)
    {
        return 1; // Gestion d'erreur si l'initialisation échoue
    }
    // Créer une fenêtre de 800x600 pixels avec le titre "Ma Fenêtre"
    data.win = mlx_new_window(mlx, 800, 600, "Ma Fenetre");
    if (!data.win)
    {
        return 1; // Gestion d'erreur si la création de la fenêtre échoue
    }
	draw_line(mlx, data.win, 100, 100, 400, 300);
    // Boucle d'événements pour garder la fenêtre ouverte
	mlx_key_hook(data.win, key_hook, &data);
    mlx_loop(mlx);
    return 0;
}
