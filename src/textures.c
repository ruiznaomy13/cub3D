/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:50:02 by eliagarc          #+#    #+#             */
/*   Updated: 2024/05/20 00:59:45 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render(t_game *game, int side, int i)
{
    double wallX; //where exactly the wall was hit
	if (side == 0)
		wallX = game->player->pos_y + game->ray_cast->perpWallDist * game->ray_cast->rayDirY;
	else
		wallX = game->player->pos_x + game->ray_cast->perpWallDist * game->ray_cast->rayDirX;
	wallX -= floor((wallX));
    int texX = (int)(wallX * (double)TEX_W);
    if(side == 0 && game->ray_cast->rayDirX > 0)
		texX = TEX_W - texX - 1;
	if(side == 1 && game->ray_cast->rayDirY < 0)
		texX = TEX_W - texX - 1;
	double step = 1.0 * TEX_H / game->ray_cast->lineHeight;
	double texPos = (game->ray_cast->drawStart - SCR_H / 2 + game->ray_cast->lineHeight / 2) * step;
	for(int y = game->ray_cast->drawStart; y < game->ray_cast->drawEnd; y++)
	{
		int texY = (int)texPos & (TEX_H - 1);
		texPos += step;
		int color_offset = texY * game->texts->size_line + texX * (game->texts->bpp / 8);
        int color = (game->texts->texture_data[color_offset + 0] & 0xFF)       | // Blue
                        ((game->texts->texture_data[color_offset + 1] & 0xFF) << 8) | // Green
                        ((game->texts->texture_data[color_offset + 2] & 0xFF) << 16) | // Red
                        ((game->texts->texture_data[color_offset + 3] & 0xFF) << 24); // Alpha
		game->buffer[y][i] = color;
	}
}
