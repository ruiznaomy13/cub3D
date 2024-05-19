/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:09:24 by eliagarc          #+#    #+#             */
/*   Updated: 2024/05/20 01:17:36 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verLine(int x, t_game *game, int color)
{
	int	i;
	int	j;

	i = game->ray_cast->drawEnd;
	j = SCR_H;
	while (j > game->ray_cast->drawStart)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x, j, 0xBB0DF3);
		j--;
	}
	while (i >= game->ray_cast->drawStart)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x, i, color);
		i--;
	}	
}

void	drawBuffer(t_game *game, unsigned int **buff)
{
	void *img_ptr;
    char *img_data;
    int bpp, size_line, endian;
    int x, y;


    img_ptr = mlx_new_image(game->mlx, SCR_W, SCR_H);
    if (!img_ptr)
		ft_error(game, EXIT_FAILURE);
    img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	for (y = 0; y < SCR_H; y++)
    {
        for (x = 0; x < SCR_W; x++)
        {
            int pixel;
            int color;
			color = buff[y][x];
			pixel = y * size_line + x * (bpp / 8);
			if (game->buffer[y][x] > 0)
			{}
			else if (y < SCR_H / 2)
        		color = game->texts->ceiling;
			else if (y < SCR_H -1)
				color = game->texts->floor;
            img_data[pixel] = color & 0xFF;         // Blue
            img_data[pixel + 1] = (color >> 8) & 0xFF;  // Green
            img_data[pixel + 2] = (color >> 16) & 0xFF; // Red
            img_data[pixel + 3] = (color >> 24) & 0xFF; // Alpha
        }
    }
    mlx_put_image_to_window(game->mlx, game->mlx_win, img_ptr, 0, 0);
    mlx_destroy_image(game->mlx, img_ptr);
}

int FixAng(int a)
{ 
	if(a>359)
		a-=360;
	if(a<0)
		a+=360;
	return (a);
}
