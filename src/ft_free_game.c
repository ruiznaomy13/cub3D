/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:16:27 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/06 16:42:02 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	close_button(void *param)
{
	t_game	*game;

	game = param;
	mlx_close_window(game->mlx);
	//mlx_terminate(game->mlx);
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

void	clean_memmory(t_game *game)
{
	if (game)
	{
		if (game->map)
			clean_map(game->map);
		if (game->player)
		{
			free(game->player);
		}
	}
}
