/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:37:43 by eliagarc          #+#    #+#             */
/*   Updated: 2024/08/12 17:56:38 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	mv_rotate(t_game *game, double oldDirX, double oldPlaneX)
{
	if (game->key == LEFT)
	{
		game->ray_cast->dir_x = game->ray_cast->dir_x * cos(-game->ray_cast->\
		rot_speed) - game->ray_cast->dir_y * sin(-game->ray_cast->rot_speed);
		game->ray_cast->dir_y = oldDirX * sin(-game->ray_cast->rot_speed) + \
		game->ray_cast->dir_y * cos(-game->ray_cast->rot_speed);
		game->ray_cast->plane_x = game->ray_cast->plane_x * \
		cos(-game->ray_cast->rot_speed) - game->ray_cast->plane_y * \
		sin(-game->ray_cast->rot_speed);
		game->ray_cast->plane_y = oldPlaneX * sin(-game->ray_cast->rot_speed) \
		+ game->ray_cast->plane_y * cos(-game->ray_cast->rot_speed);
	}
	else if (game->key == RIGHT)
	{
		game->ray_cast->dir_x = game->ray_cast->dir_x * cos(game->ray_cast->\
		rot_speed) - game->ray_cast->dir_y * sin(game->ray_cast->rot_speed);
		game->ray_cast->dir_y = oldDirX * sin(game->ray_cast->rot_speed) + \
		game->ray_cast->dir_y * cos(game->ray_cast->rot_speed);
		game->ray_cast->plane_x = game->ray_cast->plane_x * \
		cos(game->ray_cast->rot_speed) - game->ray_cast->plane_y * \
		sin(game->ray_cast->rot_speed);
		game->ray_cast->plane_y = oldPlaneX * sin(game->ray_cast->rot_speed) \
		+ game->ray_cast->plane_y * cos(game->ray_cast->rot_speed);
	}
}

static void	mv_straight(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->key == DOWN_S)
	{
		if (game->map->map_array[(int)(game->player->pos_x - game->ray_cast->\
		dir_x * game->ray_cast->mv_speed)][(int)(game->player->pos_y - \
		game->ray_cast->dir_y * game->ray_cast->mv_speed)] != 1 && \
		check_move(*player, *game->ray_cast, *game->map, 1) == 1)
		{
			player->pos_x -= game->ray_cast->dir_x * game->ray_cast->mv_speed;
			player->pos_y -= game->ray_cast->dir_y * game->ray_cast->mv_speed;
		}
	}
	else if (game->key == UP_W)
	{
		if (game->map->map_array[(int)(game->player->pos_x + game->ray_cast->\
		dir_x * game->ray_cast->mv_speed)][(int)(game->player->pos_y + \
		game->ray_cast->dir_y * game->ray_cast->mv_speed)] != 1 && \
		check_move(*player, *game->ray_cast, *game->map, 2) == 1)
		{
			player->pos_x += game->ray_cast->dir_x * game->ray_cast->mv_speed;
			player->pos_y += game->ray_cast->dir_y * game->ray_cast->mv_speed;
		}
	}
}

static void	mv_side(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->key == LEFT_A)
	{
		if (game->map->map_array[(int)(game->player->pos_x - game->ray_cast->\
		plane_x * game->ray_cast->mv_speed)][(int)(game->player->pos_y - \
		game->ray_cast->plane_y * game->ray_cast->mv_speed)] != 1 \
		&& check_move(*player, *game->ray_cast, *game->map, 3) == 1)
		{
			player->pos_x -= game->ray_cast->plane_x * game->ray_cast->mv_speed;
			player->pos_y -= game->ray_cast->plane_y * game->ray_cast->mv_speed;
		}
	}
	else if (game->key == RIGHT_D)
	{
		if (game->map->map_array[(int)(game->player->pos_x + game->ray_cast->\
		plane_x * game->ray_cast->mv_speed)][(int)(game->player->pos_y + \
		game->ray_cast->plane_y * game->ray_cast->mv_speed)] != 1 \
		&& check_move(*player, *game->ray_cast, *game->map, 4) == 1)
		{
			player->pos_x += game->ray_cast->plane_x * game->ray_cast->mv_speed;
			player->pos_y += game->ray_cast->plane_y * game->ray_cast->mv_speed;
		}
	}
}

void	move_player(t_game *game)
{
	double	oldirx;
	double	oldplanex;

	oldplanex = game->ray_cast->plane_x;
	oldirx = game->ray_cast->dir_x;
	mv_rotate(game, oldirx, oldplanex);
	mv_straight(game);
	mv_side(game);
}
