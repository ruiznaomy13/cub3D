/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:37:43 by eliagarc          #+#    #+#             */
/*   Updated: 2024/04/06 09:42:47 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    move_player(t_game *game)
{
    if (game->key == RIGHT_D || game->key == RIGHT)
		game->player->pos_y++;
	else if (game->key == LEFT_A || game->key == LEFT)
		game->player->pos_y--;
	else if (game->key == DOWN_S || game->key == DOWN)
		game->player->pos_x++;
	else if (game->key == UP_W || game->key == UP)
		game->player->pos_x--;
}