/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:09:24 by eliagarc          #+#    #+#             */
/*   Updated: 2024/07/25 12:54:23 by eliagarc         ###   ########.fr       */
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

void	drawBuffer(t_game *game, uint32_t **buff)
{
	int			x;
	int			y;
	uint32_t	color;
	
	x = -1;
	y = -1;
	while (++y < SCR_H)
	{
		while (++x < SCR_W)
		{
			color = buff[y][x];
			if (color == 0)
			{
				if (y < SCR_H / 2)
					color = game->texts->ceiling;
				else
					color = game->texts->floor;
			}
			mlx_put_pixel(game->mlx_win, x, y, color);
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
