/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:37:43 by eliagarc          #+#    #+#             */
/*   Updated: 2024/05/15 13:49:02 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    move_player(t_game *game)
{
	double oldDirX;
	double oldPlaneX;
	
	oldPlaneX = game->ray_cast->planeX;
	oldDirX = game->ray_cast->dirX;
    if (game->key == RIGHT_D || game->key == RIGHT)
	{
      	game->ray_cast->dirX = game->ray_cast->dirX * cos(-game->ray_cast->rotSpeed) - game->ray_cast->dirY * sin(-game->ray_cast->rotSpeed);
      	game->ray_cast->dirY = oldDirX * sin(-game->ray_cast->rotSpeed) + game->ray_cast->dirY * cos(-game->ray_cast->rotSpeed);
      	game->ray_cast->planeX = game->ray_cast->planeX * cos(-game->ray_cast->rotSpeed) - game->ray_cast->planeY * sin(-game->ray_cast->rotSpeed);
      	game->ray_cast->planeY = oldPlaneX * sin(-game->ray_cast->rotSpeed) + game->ray_cast->planeY * cos(-game->ray_cast->rotSpeed);
	}
	else if (game->key == LEFT_A || game->key == LEFT)
	{
		game->ray_cast->dirX = game->ray_cast->dirX * cos(game->ray_cast->rotSpeed) - game->ray_cast->dirY * sin(game->ray_cast->rotSpeed);
      	game->ray_cast->dirY = oldDirX * sin(game->ray_cast->rotSpeed) + game->ray_cast->dirY * cos(game->ray_cast->rotSpeed);
      	game->ray_cast->planeX = game->ray_cast->planeX * cos(game->ray_cast->rotSpeed) - game->ray_cast->planeY * sin(game->ray_cast->rotSpeed);
      	game->ray_cast->planeY = oldPlaneX * sin(game->ray_cast->rotSpeed) + game->ray_cast->planeY * cos(game->ray_cast->rotSpeed);
	}
	else if (game->key == DOWN_S || game->key == DOWN)
	{
		if (game->player->pos_x - (int)(game->ray_cast->dirX * game->ray_cast->moveSpeed) > 0 && game->map->map_array[(game->player->pos_x - (int)game->ray_cast->dirX)][game->player->pos_y] != 1)
			game->player->pos_x -= (int)(game->ray_cast->dirX * game->ray_cast->moveSpeed);
		if (game->player->pos_y - (int)(game->ray_cast->dirY * game->ray_cast->moveSpeed) > 0 && game->map->map_array[game->player->pos_x][(game->player->pos_y - (int)game->ray_cast->dirY)] != 1)
			game->player->pos_y -= (int)(game->ray_cast->dirY * game->ray_cast->moveSpeed);
	}
	else if (game->key == UP_W || game->key == UP)
	{
		if (game->player->pos_x + (int)(game->ray_cast->dirX * game->ray_cast->moveSpeed) < game->map->rows &&  game->map->map_array[(game->player->pos_x + (int)game->ray_cast->dirX)][game->player->pos_y] != 1)
			game->player->pos_x += (int)(game->ray_cast->dirX * game->ray_cast->moveSpeed);
		if (game->player->pos_y + (int)(game->ray_cast->dirY * game->ray_cast->moveSpeed) < game->map->cols && game->map->map_array[game->player->pos_x][(game->player->pos_y + (int)game->ray_cast->dirY)] != 1)
			game->player->pos_y += (int)(game->ray_cast->dirY * game->ray_cast->moveSpeed);
	}
}