/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:50:02 by eliagarc          #+#    #+#             */
/*   Updated: 2024/07/25 13:09:11 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render(t_game *game, int side, int i)
{
	double		wallX;
	int			texX;
	int			texY;
	double		step;
	double		texPos;
	mlx_image_t	*textr;

	if (side == 0)
	{
		wallX = game->player->pos_y + game->ray_cast->perpWallDist * game->ray_cast->rayDirY;
		if (game->ray_cast->stepX == 1)
			textr = game->texts->texture_e;
		else
			textr = game->texts->texture_w;
	}
	else
	{
		wallX = game->player->pos_x + game->ray_cast->perpWallDist * game->ray_cast->rayDirX;
		if (game->ray_cast->stepY == 1)
			textr = game->texts->texture_n;
		else
			textr = game->texts->texture_s;
	}
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)TEX_W);
	if(side == 0 && game->ray_cast->rayDirX > 0)
		texX = TEX_W - texX - 1;
	if(side == 1 && game->ray_cast->rayDirY < 0)
		texX = TEX_W - texX - 1;
	step = 1.0 * TEX_H / game->ray_cast->lineHeight;
	texPos = (game->ray_cast->drawStart - SCR_H / 2 + game->ray_cast->lineHeight / 2) * step;
	for(int y = game->ray_cast->drawStart; y < game->ray_cast->drawEnd; y++)
	{
		texY = ((int)texPos) & (TEX_H - 1);
		texPos += step;
		unsigned int color_offset = texY * TEX_W * 4 + texX * 4;
		uint32_t color = (textr->pixels[color_offset + 3] & 0xFF)       | // Blue
						((textr->pixels[color_offset + 2] & 0xFF) << 8) | // Green
						((textr->pixels[color_offset + 1] & 0xFF) << 16) | // Red
						((textr->pixels[color_offset + 0] & 0xFF) << 24); // Alpha
		game->buffer[y][i] = color;
	}
}

void	fill_color(mlx_image_t *img, uint32_t color)
{
	uint32_t		i;
	uint32_t		j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{

			mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}

int	check_textures(t_textures *txts)
{
	if (!txts->walle)
		return (0);
	if (!txts->walln)
		return (0);
	if (!txts->walls)
		return (0);
	if (!txts->wallw)
		return (0);
	if (!txts->black)
		return (0);
	if (!txts->hand)
		return (0);
	return (1);
}

uint32_t get_rgba(int r, int g, int b, int a)
{
    return ((r << 24) | (g << 16) | (b << 8) | a);
}
