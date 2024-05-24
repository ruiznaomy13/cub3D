/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:06:26 by eliagarc          #+#    #+#             */
/*   Updated: 2024/05/24 11:35:34 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(t_game game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game.map->rows)
	{
		while (j < game.map->cols)
		{
			if (game.map->map_array[i][j] == 1)
				mlx_put_image_to_window(game.mlx, game.mlx_win, \
				game.texts->wall, SCR_W/2 + (j * SQSZ) * 1, (i * SQSZ) * 1);
			j++;
		}
		j = 0;
		i++;
	}
	// mlx_pixel_put(game.mlx, game.mlx_win, SCR_W/2 + game.player->pos_y * SQSZ, game.player->pos_x * SQSZ, 0xFF0000);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.texts->player, SCR_W / 2 + (int)game.player->pos_y * SQSZ, (int)game.player->pos_x * SQSZ);
}
