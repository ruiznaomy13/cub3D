/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:06:26 by eliagarc          #+#    #+#             */
/*   Updated: 2024/07/06 16:23:43 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(t_game game)
{
	int	i;
	int	j;

	i = -MPSZ + (int)game.player->pos_x;
	print_border(game, MPSZ);
	while (i < (int)game.player->pos_x + MPSZ)
	{
		j = -MPSZ + (int)game.player->pos_y;
		while (j < (int)game.player->pos_y + MPSZ)
		{
			if ((i >= 0 && i < game.map->rows) && (j >= 0 && j < game.map->cols))
			{
				if (game.map->map_array[i][j] == 1)
					mlx_draw_texture(game.mlx_win, game.texts->wall, \
					(SCR_W - (SCR_W / 6)) + ((j - (int)game.player->pos_y) * SQSZ), (SCR_H / 5) + ((i - (int)game.player->pos_x) * SQSZ));
				else if (game.map->map_array[i][j] == -1)
					mlx_draw_texture(game.mlx_win, game.texts->black, \
				(SCR_W - (SCR_W / 6)) + ((j - (int)game.player->pos_y) * SQSZ), (SCR_H / 5) + ((i - (int)game.player->pos_x) * SQSZ));
			}
			else
				mlx_draw_texture(game.mlx_win, game.texts->black, \
				(SCR_W - (SCR_W / 6)) + ((j - (int)game.player->pos_y) * SQSZ), (SCR_H / 5) + ((i - (int)game.player->pos_x) * SQSZ));
			j++;
		}
		i++;
	}
	mlx_draw_texture(game.mlx_win, game.texts->player, SCR_W - (SCR_W / 6), (SCR_H / 5));
}

void mlx_draw_texture(mlx_image_t *window_image, mlx_texture_t *texture, int dest_x, int dest_y)
{
	uint32_t	x;
	uint32_t	y;
	int			window_index;
	int			texture_index;
	
	x = 0;
	y = 0;
	uint32_t *texture_data = (uint32_t *)texture->pixels;
	uint32_t *window_data = (uint32_t *)window_image->pixels;

	while (y < texture->height)
	{
		while (x < texture->width)
		{
			window_index = (dest_y + y) * window_image->width + (dest_x + x);
			texture_index = y * texture->width + x;
			if ((dest_x + x) < window_image->width && (dest_y + y) < window_image->height)
			{
				if (texture_data[texture_index] != 0)
					window_data[window_index] = texture_data[texture_index];
			}
			x++;
		}
		x = 0;
		y++;
	}
}

static void	print_bline(t_game game, int j, int i, int option)
{
	if (option == 1)
	{
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i - 2, 0);
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i - 1, 0);
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i, 0);
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i + 1, 0);
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i + 2, 0);
	}
	else if (option == 2)
	{
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j - 2, (SCR_H / 5) + i, 0);
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j - 1, (SCR_H / 5) + i, 0);
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i, 0);
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j + 1, (SCR_H / 5) + i, 0);
		mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j + 2, (SCR_H / 5) + i, 0);
	}
}

void	print_border(t_game game, int x)
{
	int i;
	int j;
	
	i = -x * SQSZ;
	while (i <= x * SQSZ)
	{
		j = -x * SQSZ;
		while (j <= x * SQSZ)
		{
			if (i == -x * SQSZ || i == x *SQSZ)
				print_bline(game, j, i, 1);
			else if (j == -x * SQSZ || j == x * SQSZ)
				print_bline(game, j, i, 2);
			else
				mlx_put_pixel(game.mlx_win, SCR_W - (SCR_W / 6) + j, (SCR_H / 5) + i, game.texts->floor);
			j++;
		}
		i++;
	}
}
