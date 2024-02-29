/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:16:27 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/29 16:09:02 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	clean_map(t_map *map)
{
	int	i;

	i = -1;
	if (map)
	{
		if (map->map_guide)
		{
			while (++i < map->rows)
				free(map->map_guide[i]);
			free(map->map_guide);
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
		free(game->player);
		free(game);
	}
}