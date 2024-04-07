/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:16:27 by ncastell          #+#    #+#             */
/*   Updated: 2024/04/06 09:18:29 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_button(t_game *game, int option)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	clean_memmory(game);
	if (option == 1)
	{
		game = NULL;
		return (0);
	}
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
				free(map->map_array[i]);
			free(map->map_array);
		}
		free(map->line);
		free(map->texture_no);
		free(map->texture_so);
		free(map->texture_we);
		free(map->texture_ea);
		free(map);
	}
}

void	clean_memmory(t_game *game)
{
	if (game)
	{
		clean_map(game->map);
		// free(game->player);
	}
}
