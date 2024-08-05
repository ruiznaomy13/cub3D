/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:09:24 by eliagarc          #+#    #+#             */
/*   Updated: 2024/08/05 19:20:58 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_buffer(t_game *game, uint32_t **buff)
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

void	get_raycast(t_ray **rcast, int i, t_player *player)
{
	(*rcast)->camera_x = 2 * i / (double)SCR_W - 1;
	(*rcast)->r_dirx = (*rcast)->dir_x + (*rcast)->plane_x * (*rcast)->camera_x;
	(*rcast)->r_diry = (*rcast)->dir_y + (*rcast)->plane_y * (*rcast)->camera_x;
	(*rcast)->boxmap_x = (int)player->pos_x;
	(*rcast)->boxmap_y = (int)player->pos_y;
	(*rcast)->deltadist_x = fabs(1 / (*rcast)->r_dirx);
	(*rcast)->deltadist_y = fabs(1 / (*rcast)->r_diry);
}
