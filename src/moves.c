/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:37:43 by eliagarc          #+#    #+#             */
/*   Updated: 2024/05/13 18:12:00 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    move_player(t_game *game)
{
	// mlx_pixel_put(game->mlx, game->mlx_win, game->player->pos_x, game->player->pos_y, 0x000000);
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
		game->player->pos_y -= game->ray_cast->dirY * game->ray_cast->moveSpeed;
		game->player->pos_x -= game->ray_cast->dirX * game->ray_cast->moveSpeed;
	}
	else if (game->key == UP_W || game->key == UP)
	{
		game->player->pos_y += game->ray_cast->dirY * game->ray_cast->moveSpeed;
		game->player->pos_x += game->ray_cast->dirX * game->ray_cast->moveSpeed;
	}
}