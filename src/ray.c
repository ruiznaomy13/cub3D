/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:53:57 by eliagarc          #+#    #+#             */
/*   Updated: 2024/03/05 20:24:36 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dir_ray(t_game *game)
{
	if (game->player->card_p == 'N')
	{
		game->ray_cast->dirX = 0;
		game->ray_cast->dirY = 1;
	}
	if (game->player->card_p == 'S')
	{
		game->ray_cast->dirX = 0;
		game->ray_cast->dirY = -1;
	}
	if (game->player->card_p == 'W')
	{
		game->ray_cast->dirX = -1;
		game->ray_cast->dirY = 0;
	}
	if (game->player->card_p == 'O')
	{
		game->ray_cast->dirX = 1;
		game->ray_cast->dirY = 0;
	}
	game->ray_cast->planeX = 0;
	game->ray_cast->planeY = 0.66;
}

void	init_ray(t_game *game)
{
	game->ray_cast = ft_calloc(1, sizeof(t_ray));
	dir_ray(game);
}