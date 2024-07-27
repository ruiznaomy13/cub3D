/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:50:02 by eliagarc          #+#    #+#             */
/*   Updated: 2024/07/27 22:45:57 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_render(t_game *game, t_render **rd, int side, mlx_image_t **textr)
{
	if (side == 0)
	{
		(*rd)->wall_x = game->player->pos_y + \
		game->ray_cast->walldist * game->ray_cast->r_diry;
		if (game->ray_cast->step_x == 1)
			(*textr) = game->texts->texture_e;
		else
			(*textr) = game->texts->texture_w;
	}
	else
	{
		(*rd)->wall_x = game->player->pos_x + \
		game->ray_cast->walldist * game->ray_cast->r_dirx;
		if (game->ray_cast->step_y == 1)
			(*textr) = game->texts->texture_n;
		else
			(*textr) = game->texts->texture_s;
	}
	(*rd)->wall_x -= floor(((*rd)->wall_x));
	(*rd)->tex_x = (int)((*rd)->wall_x * (double)TEX_W);
	if (side == 0 && game->ray_cast->r_dirx > 0)
		(*rd)->tex_x = TEX_W - (*rd)->tex_x - 1;
	if (side == 1 && game->ray_cast->r_diry < 0)
		(*rd)->tex_x = TEX_W - (*rd)->tex_x - 1;
}

void	render(t_game *game, int side, int i)
{
	mlx_image_t		*textr;
	unsigned int	color_offset;
	int				j;

	textr = NULL;
	if (game->rd)
		free(game->rd);
	game->rd = (t_render *)ft_calloc(1, sizeof(t_render));
	init_render(game, &game->rd, side, &textr);
	game->rd->step = 1.0 * TEX_H / game->ray_cast->line_h;
	game->rd->tex_pos = (game->ray_cast->draw_start - \
	SCR_H / 2 + game->ray_cast->line_h / 2) * game->rd->step;
	j = game->ray_cast->draw_start - 1;
	while (++j < game->ray_cast->draw_end)
	{
		game->rd->tex_y = ((int)game->rd->tex_pos) & (TEX_H - 1);
		game->rd->tex_pos += game->rd->step;
		color_offset = game->rd->tex_y * TEX_W * 4 + game->rd->tex_x * 4;
		game->rd->color = (textr->pixels[color_offset + 3] & 0xFF) | \
		((textr->pixels[color_offset + 2] & 0xFF) << 8) | \
		((textr->pixels[color_offset + 1] & 0xFF) << 16) | \
		((textr->pixels[color_offset + 0] & 0xFF) << 24);
		game->buffer[j][i] = game->rd->color;
	}
}

int	check_textures(t_textures *txts)
{
	if (!txts->walle || !txts->walln || !txts->walls || !txts->wallw)
		return (0);
	if (!txts->black)
		return (0);
	if (!txts->hand)
		return (0);
	if (!txts->wall)
		return (0);
	if (!txts->player)
		return (0);
	if (!txts->walln)
		return (0);
	if (!txts->texture_n || !txts->texture_s || !txts->texture_w \
	|| !txts->texture_e || !txts->txt_black || !txts->txt_hand)
		return (0);
	return (1);
}

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
