/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:37:43 by eliagarc          #+#    #+#             */
/*   Updated: 2024/07/25 13:59:36 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	mv_rotate(t_game *game, double oldDirX, double oldPlaneX)
{
	if (game->key == LEFT)
	{
      	game->ray_cast->dirX = game->ray_cast->dirX * cos(-game->ray_cast->rotSpeed) - game->ray_cast->dirY * sin(-game->ray_cast->rotSpeed);
      	game->ray_cast->dirY = oldDirX * sin(-game->ray_cast->rotSpeed) + game->ray_cast->dirY * cos(-game->ray_cast->rotSpeed);
      	game->ray_cast->planeX = game->ray_cast->planeX * cos(-game->ray_cast->rotSpeed) - game->ray_cast->planeY * sin(-game->ray_cast->rotSpeed);
      	game->ray_cast->planeY = oldPlaneX * sin(-game->ray_cast->rotSpeed) + game->ray_cast->planeY * cos(-game->ray_cast->rotSpeed);
	}
	else if (game->key == RIGHT)
	{
		game->ray_cast->dirX = game->ray_cast->dirX * cos(game->ray_cast->rotSpeed) - game->ray_cast->dirY * sin(game->ray_cast->rotSpeed);
      	game->ray_cast->dirY = oldDirX * sin(game->ray_cast->rotSpeed) + game->ray_cast->dirY * cos(game->ray_cast->rotSpeed);
      	game->ray_cast->planeX = game->ray_cast->planeX * cos(game->ray_cast->rotSpeed) - game->ray_cast->planeY * sin(game->ray_cast->rotSpeed);
      	game->ray_cast->planeY = oldPlaneX * sin(game->ray_cast->rotSpeed) + game->ray_cast->planeY * cos(game->ray_cast->rotSpeed);
	}
}

static void	mv_straight(t_game *game)
{
	if (game->key == DOWN_S)
	{
		if (game->map->map_array[(int)(game->player->pos_x - game->ray_cast->dirX * game->ray_cast->moveSpeed)][(int)game->player->pos_y] != 1 && (game->map->map_array[(int)game->player->pos_x][(int)(game->player->pos_y - game->ray_cast->dirY * game->ray_cast->moveSpeed)] != 1))
		{
			game->player->pos_x -= game->ray_cast->dirX * game->ray_cast->moveSpeed;
			game->player->pos_y -= game->ray_cast->dirY * game->ray_cast->moveSpeed;
		}
	}
	else if (game->key == UP_W)
	{
		if (game->map->map_array[(int)(game->player->pos_x + game->ray_cast->dirX * game->ray_cast->moveSpeed)][(int)game->player->pos_y] != 1  && (game->map->map_array[(int)(game->player->pos_x)][(int)(game->player->pos_y + game->ray_cast->dirY * game->ray_cast->moveSpeed)] != 1))
		{
			game->player->pos_x += game->ray_cast->dirX * game->ray_cast->moveSpeed;
			game->player->pos_y += game->ray_cast->dirY * game->ray_cast->moveSpeed;
		}
	}
}

static void	mv_side(t_game *game)
{
	if (game->key == LEFT_A)
	{
		if (game->map->map_array[(int)(game->player->pos_x - game->ray_cast->planeX * game->ray_cast->moveSpeed)][(int)game->player->pos_y] != 1 && (game->map->map_array[(int)game->player->pos_x][(int)(game->player->pos_y - game->ray_cast->planeY * game->ray_cast->moveSpeed)] != 1))
		{
			game->player->pos_x -= game->ray_cast->planeX * game->ray_cast->moveSpeed;
			game->player->pos_y -= game->ray_cast->planeY * game->ray_cast->moveSpeed;
		}
	}
	else if (game->key == RIGHT_D)
	{
		if (game->map->map_array[(int)(game->player->pos_x + game->ray_cast->planeX * game->ray_cast->moveSpeed)][(int)game->player->pos_y] != 1  && (game->map->map_array[(int)(game->player->pos_x)][(int)(game->player->pos_y + game->ray_cast->planeY * game->ray_cast->moveSpeed)] != 1))
		{
			game->player->pos_x += game->ray_cast->planeX * game->ray_cast->moveSpeed;
			game->player->pos_y += game->ray_cast->planeY * game->ray_cast->moveSpeed;
		}
	}
}

void    move_player(t_game *game)
{
	double	oldDirX;
	double	oldPlaneX;
	
	oldPlaneX = game->ray_cast->planeX;
	oldDirX = game->ray_cast->dirX;
	mv_rotate(game, oldDirX, oldPlaneX);
	mv_straight(game);
	mv_side(game);
}
