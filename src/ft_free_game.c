/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:16:27 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/28 00:06:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	close_button(void *param)
{
	t_game	*game;

	game = param;
	mlx_close_window(game->mlx);
	clean_memmory(game);
	printf("\nGood bye!\n");
	exit(EXIT_SUCCESS);
}

static void	clean_map(t_map *map)
{
	int	i;

	i = -1;
	if (map)
	{
		if (map->map_array)
		{
			while (++i < map->rows)
			{
				if (map->map_array[i])
					free(map->map_array[i]);
			}
			free(map->map_array);
		}
		if (map->texture_no)
			free(map->texture_no);
		if (map->texture_so)
			free(map->texture_so);
		if (map->texture_we)
			free(map->texture_we);
		if (map->texture_ea)
			free(map->texture_ea);
		free(map);
	}
}

static void	free_textures(t_textures *txts, mlx_t *mlx)
{
	mlx_delete_texture(txts->wall);
	mlx_delete_texture(txts->player);
	mlx_delete_texture(txts->walln);
	mlx_delete_texture(txts->walls);
	mlx_delete_texture(txts->wallw);
	mlx_delete_texture(txts->walle);
	mlx_delete_texture(txts->black);
	mlx_delete_texture(txts->hand);
	mlx_delete_image(mlx, txts->texture_n);
	mlx_delete_image(mlx, txts->texture_s);
	mlx_delete_image(mlx, txts->texture_e);
	mlx_delete_image(mlx, txts->texture_w);
	mlx_delete_image(mlx, txts->txt_black);
	mlx_delete_image(mlx, txts->txt_hand);
}

void	clean_memmory(t_game *game)
{
	if (game)
	{
		if (game->map->line)
			free(game->map->line);
		if (game->map)
			clean_map(game->map);
		if (game->player)
		{
			free(game->player);
		}
		if (game->texts)
			free_textures(game->texts, game->mlx);
	}
}
