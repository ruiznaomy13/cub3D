/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:53:57 by eliagarc          #+#    #+#             */
/*   Updated: 2024/06/26 04:28:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_ray_aux(t_game *game)
{
	
	if (game->player->card_p == 'W')
	{
		game->ray_cast->dirX = -1.0;
		game->ray_cast->dirY = 0.0;
		game->ray_cast->planeX = 0;
		game->ray_cast->planeY = -0.66;
	}
	if (game->player->card_p == 'E')
	{
		game->ray_cast->dirX = 1.0;
		game->ray_cast->dirY = 0.0;
		game->ray_cast->planeX = 0;
		game->ray_cast->planeY = 0.66;
	}
}

void	init_ray(t_game *game)
{
	game->ray_cast = ft_calloc(1, sizeof(t_ray));
	game->ray_cast->moveSpeed = 0.15;
	game->ray_cast->rotSpeed = 0.15;
	if (game->player->card_p == 'N')
	{
		game->ray_cast->dirX = 0.0;
		game->ray_cast->dirY = -1.0;
		game->ray_cast->planeX = 0.66;
		game->ray_cast->planeY = 0;
	}
	if (game->player->card_p == 'S')
	{
		game->ray_cast->dirX = 0.0;
		game->ray_cast->dirY = 1.0;
		game->ray_cast->planeX = -0.66;
		game->ray_cast->planeY = 0;
	}
	init_ray_aux(game);
}

static void	getDirection(t_game *game)
{
	if(game->ray_cast->rayDirX < 0)
	{
		game->ray_cast->stepX = -1;
		game->ray_cast->sideDistX = (game->player->pos_x - game->ray_cast->boxMapX) * game->ray_cast->deltaDistX;
	}
	else
	{
		game->ray_cast->stepX = 1;
		game->ray_cast->sideDistX = ((double)game->ray_cast->boxMapX + 1.0 - game->player->pos_x) * game->ray_cast->deltaDistX;
	}
	if(game->ray_cast->rayDirY < 0)
	{
		game->ray_cast->stepY = -1;
		game->ray_cast->sideDistY = (game->player->pos_y - game->ray_cast->boxMapY) * game->ray_cast->deltaDistY;
	}
	else
	{
		game->ray_cast->stepY = 1;
		game->ray_cast->sideDistY = ((double)game->ray_cast->boxMapY + 1.0 - game->player->pos_y) * game->ray_cast->deltaDistY;
	}
}

static void	perfDDA(t_game *game, int *hit, int *side)
{
	*hit = 0;
	while(*hit == 0)
	{
		if(game->ray_cast->sideDistX < game->ray_cast->sideDistY)
		{
			game->ray_cast->sideDistX += game->ray_cast->deltaDistX;
			game->ray_cast->boxMapX += game->ray_cast->stepX;
			*side = 0;
		}
		else
		{
			game->ray_cast->sideDistY += game->ray_cast->deltaDistY;
			game->ray_cast->boxMapY += game->ray_cast->stepY;
			*side = 1;
		}
		if (game->ray_cast->boxMapY < 0 || game->ray_cast->boxMapX < 0
			|| game->ray_cast->boxMapY > SCR_W || game->ray_cast->boxMapX > SCR_H)
			break ;
		if (game->map->map_array[game->ray_cast->boxMapX][game->ray_cast->boxMapY] == 1)
			*hit = 1;
	}
}

void	ft_raytracing(t_game *game)
{
	int	i;
	int	hit;
	int	side;

	if (game->moves != 0)
		drawBuffer(game, game->buffer);
	i = 0;
	while (i < SCR_W)
	{
		game->ray_cast->cameraX = 2 * i / (double)SCR_W - 1;
		game->ray_cast->rayDirX = game->ray_cast->dirX + game->ray_cast->planeX * game->ray_cast->cameraX;
		game->ray_cast->rayDirY = game->ray_cast->dirY + game->ray_cast->planeY * game->ray_cast->cameraX;
		game->ray_cast->boxMapX = (int)game->player->pos_x;
		game->ray_cast->boxMapY = (int)game->player->pos_y;
		game->ray_cast->deltaDistX = fabs(1 / game->ray_cast->rayDirX);
		game->ray_cast->deltaDistY = fabs(1 / game->ray_cast->rayDirY);
		getDirection(game);
		perfDDA(game, &hit, &side);
		if (side == 0)
			game->ray_cast->perpWallDist = game->ray_cast->sideDistX - game->ray_cast->deltaDistX;
		else
			game->ray_cast->perpWallDist = game->ray_cast->sideDistY - game->ray_cast->deltaDistY;
		game->ray_cast->lineHeight = (int)(SCR_H / game->ray_cast->perpWallDist);
		game->ray_cast->drawStart = -game->ray_cast->lineHeight / 2 + SCR_H / 2;
		if (game->ray_cast->drawStart < 0)
			game->ray_cast->drawStart = 0;
		game->ray_cast->drawEnd = game->ray_cast->drawStart + game->ray_cast->lineHeight;
		if (game->ray_cast->drawEnd >= SCR_H)
			game->ray_cast->drawEnd = SCR_H - 1;
		render(game, side, i);
		i++;
    }
}
