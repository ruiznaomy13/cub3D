/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:37:43 by eliagarc          #+#    #+#             */
/*   Updated: 2024/05/16 05:35:20 by elias            ###   ########.fr       */
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
		if (game->map->map_array[(int)(game->player->pos_x - game->ray_cast->dirX * game->ray_cast->moveSpeed)][(int)game->player->pos_y] == 0 && (game->map->map_array[(int)(game->player->pos_x)][(int)(game->player->pos_y - game->ray_cast->dirY * game->ray_cast->moveSpeed)] == 0))
		{
			game->player->pos_x -= game->ray_cast->dirX * game->ray_cast->moveSpeed;
		// if (game->map->map_array[(int)(game->player->pos_x)][(int)(game->player->pos_y - game->ray_cast->dirY * game->ray_cast->moveSpeed)] == 0)
			game->player->pos_y -= game->ray_cast->dirY * game->ray_cast->moveSpeed;
		}
	}
	else if (game->key == UP_W || game->key == UP)
	{
		if (game->map->map_array[(int)(game->player->pos_x + game->ray_cast->dirX * game->ray_cast->moveSpeed)][(int)game->player->pos_y] == 0 && game->map->map_array[(int)(game->player->pos_x)][(int)(game->player->pos_y + game->ray_cast->dirY * game->ray_cast->moveSpeed)] == 0)
		{
			game->player->pos_x += game->ray_cast->dirX * game->ray_cast->moveSpeed;
		// if (game->map->map_array[(int)(game->player->pos_x)][(int)(game->player->pos_y + game->ray_cast->dirY * game->ray_cast->moveSpeed)] == 0)
			game->player->pos_y += game->ray_cast->dirY * game->ray_cast->moveSpeed;
		}
	}
}