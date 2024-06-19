/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:09:24 by eliagarc          #+#    #+#             */
/*   Updated: 2024/06/19 18:50:11 by marvin           ###   ########.fr       */
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
		mlx_put_pixel(game->mlx_win, x, j, 0xBB0DF3);
		j--;
	}
	while (i >= game->ray_cast->drawStart)
	{
		mlx_put_pixel(game->mlx_win, x, i, color);
		i--;
	}	
}

void	drawBuffer(t_game *game, unsigned int **buff)
{
	int	x;
	int	y;
	int	pixel;
	int	color;

	x = -1;
	y = -1;
	while (++y < SCR_H)
	{
		while (++x < SCR_W)
		{
			color = buff[y][x];
			pixel = y * SCR_W + x;
			if (game->buffer[y][x] > 0)
				;
			else if (y < SCR_H / 2)
				color = game->texts->ceiling;
			else if (y < SCR_H - 1)
				color = game->texts->floor;
			//game->mlx_win->pixels[pixel] = color & 0xFF;         // Blue
			//game->mlx_win->pixels[pixel + 1] = (color >> 8) & 0xFF;  // Green
			//game->mlx_win->pixels[pixel + 2] = (color >> 16) & 0xFF; // Red
			//game->mlx_win->pixels[pixel + 3] = (color >> 24) & 0xFF; // Alpha
			game->mlx_win->pixels[pixel] = color;
		}
		x = -1;
	}
}

int FixAng(int a)
{ 
	if(a>359)
		a-=360;
	if(a<0)
		a+=360;
	return (a);
}
