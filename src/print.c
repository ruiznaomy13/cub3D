/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:06:26 by eliagarc          #+#    #+#             */
/*   Updated: 2024/06/19 19:02:06 by marvin           ###   ########.fr       */
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
				mlx_draw_texture(game.mlx_win, game.texts->wall, \
				SCR_W/2 + (j * SQSZ) * 1, (i * SQSZ) * 1);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_draw_texture(game.mlx_win, game.texts->player, SCR_W / 2 + (int)game.player->pos_y * SQSZ, (int)game.player->pos_x * SQSZ);
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
				window_data[window_index] = texture_data[texture_index];
			x++;
		}
		x = 0;
		y++;
	}
}

void clear_pixels(mlx_image_t *image) 
{
	size_t	pixel_data_size;
	size_t	i;

	i = SCR_W / 2;
	pixel_data_size = image->width/2 * image->height * 4;
	while (i < pixel_data_size)
	{
		((uint32_t *)image->pixels)[i] = 0;
		i++;
	}
}
