/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:06:26 by eliagarc          #+#    #+#             */
/*   Updated: 2024/07/27 23:44:28 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(mlx_image_t *win, t_player *player, t_map *map, \
t_textures *text)
{
	int	i;
	int	j;
	int	posx;
	int	posy;

	i = -MPSZ + (int)player->pos_x - 1;
	while (++i < (int)player->pos_x + MPSZ)
	{
		j = -MPSZ + (int)player->pos_y - 1;
		while (++j < (int)player->pos_y + MPSZ)
		{
			posx = (SCR_W - SCR_W / 6) + ((j - (int)player->pos_y) * SQSZ);
			posy = SCR_H / 5 + ((i - (int)player->pos_x) * SQSZ);
			if ((i >= 0 && i < map->rows) && (j >= 0 && j < map->cols))
			{
				if (map->map_array[i][j] == 1)
					mlx_draw_texture(win, text->wall, posx, posy);
				else if (map->map_array[i][j] == -1)
					mlx_draw_texture(win, text->black, posx, posy);
			}
			else
				mlx_draw_texture(win, text->black, posx, posy);
		}
	}
}

void	mlx_draw_texture(mlx_image_t *window_image, mlx_texture_t *texture,
int dest_x, int dest_y)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	*texture_data;
	uint32_t	*window_data;
	int			window_index;

	x = -1;
	y = -1;
	texture_data = (uint32_t *)texture->pixels;
	window_data = (uint32_t *)window_image->pixels;
	while (++y < texture->height)
	{
		while (++x < texture->width)
		{
			window_index = (dest_y + y) * window_image->width + (dest_x + x);
			if ((dest_x + x) < window_image->width && \
			(dest_y + y) < window_image->height)
			{
				if (texture_data[y * texture->width + x] != 0)
					window_data[window_index] = \
					texture_data[y * texture->width + x];
			}
		}
		x = -1;
	}
}

static void	print_bline(mlx_image_t *win, int j, int i, int option)
{
	if (option == 1)
	{
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i - 2, 0);
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i - 1, 0);
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i, 0);
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i + 1, 0);
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i + 2, 0);
	}
	else if (option == 2)
	{
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j - 2, (SCR_H / 5) + i, 0);
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j - 1, (SCR_H / 5) + i, 0);
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i, 0);
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j + 1, (SCR_H / 5) + i, 0);
		mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j + 2, (SCR_H / 5) + i, 0);
	}
}

void	print_border(mlx_image_t *win, t_textures *text, int x)
{
	int	i;
	int	j;

	i = -x * SQSZ;
	while (i <= x * SQSZ)
	{
		j = -x * SQSZ;
		while (j <= x * SQSZ)
		{
			if (i == -x * SQSZ || i == x * SQSZ)
				print_bline(win, j, i, 1);
			else if (j == -x * SQSZ || j == x * SQSZ)
				print_bline(win, j, i, 2);
			else
				mlx_put_pixel(win, SCR_W - (SCR_W / 6) + j, \
				(SCR_H / 5) + i, text->floor);
			j++;
		}
		i++;
	}
}

void	print_hand(t_game *game)
{
	if (game->spr > 20)
		mlx_draw_texture(game->mlx_win, game->texts->hand, SCR_W / 2, \
		SCR_H - game->texts->hand->height + 10);
	else
		mlx_draw_texture(game->mlx_win, game->texts->hand, SCR_W / 2, \
		SCR_H - game->texts->hand->height);
	game->spr++;
	if (game->spr == 40)
		game->spr = 0;
}
