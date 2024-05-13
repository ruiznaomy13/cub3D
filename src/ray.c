/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:53:57 by eliagarc          #+#    #+#             */
/*   Updated: 2024/05/13 17:30:37 by eliagarc         ###   ########.fr       */
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
	game->ray_cast->moveSpeed = (2.0 / 1000.0) * 5.0;
	game->ray_cast->rotSpeed = (2.0 / 1000.0) * 3.0;
	dir_ray(game);
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
		game->ray_cast->sideDistX = (game->ray_cast->boxMapX + 1.0 - game->player->pos_x) * game->ray_cast->deltaDistX;
	}
	if(game->ray_cast->rayDirY < 0)
	{
		game->ray_cast->stepY = -1;
		game->ray_cast->sideDistY = (game->player->pos_y - game->ray_cast->boxMapY) * game->ray_cast->deltaDistY;
	}
	else
	{
		game->ray_cast->stepY = 1;
		game->ray_cast->sideDistY = (game->ray_cast->boxMapY + 1.0 - game->player->pos_y) * game->ray_cast->deltaDistY;
	}
}

static void	perfDDA(t_game *game, int *hit, int *side)
{
	*hit = 0; //was there a wall hit?
	//perform DDA
	while(*hit == 0)
	{
		if(game->ray_cast->sideDistX < game->ray_cast->sideDistY)
		{
			game->ray_cast->sideDistX += game->ray_cast->deltaDistX;
			game->ray_cast->boxMapX += game->ray_cast->stepX;
			*side = 0; //EW
		}
		else
		{
			game->ray_cast->sideDistY += game->ray_cast->deltaDistY;
			game->ray_cast->boxMapY += game->ray_cast->stepY;
			*side = 1; //NS
		}
		if (game->map->map_array[game->ray_cast->boxMapX][game->ray_cast->boxMapY] > 0)
			*hit = 1;
	}
}

void	ft_raytracing(t_game *game)
{
	int	i;
	int	hit;
	int	side;

	i = -1;
	while (++i < SCR_W)
	{
		game->ray_cast->cameraX = (2 * i / (double)SCR_W) - 1;
		game->ray_cast->rayDirX = game->ray_cast->dirX + game->ray_cast->planeX * game->ray_cast->cameraX;
		game->ray_cast->rayDirY = game->ray_cast->dirY + game->ray_cast->planeY * game->ray_cast->cameraX;
		game->ray_cast->boxMapX = game->player->pos_x;
		game->ray_cast->boxMapY = game->player->pos_y;
		game->ray_cast->deltaDistX = (game->ray_cast->rayDirX == 0) ? 1e30 : fabs(1 / game->ray_cast->rayDirX);
		game->ray_cast->deltaDistY = (game->ray_cast->rayDirY == 0) ? 1e30 : fabs(1 / game->ray_cast->rayDirY);
		
		getDirection(game);
		perfDDA(game, &hit, &side);
		if(side == 0)
			game->ray_cast->perpWallDist = (game->ray_cast->sideDistX - game->ray_cast->deltaDistX);
		else
			game->ray_cast->perpWallDist = (game->ray_cast->sideDistY - game->ray_cast->deltaDistY);

		game->ray_cast->lineHeight = (int)(SCR_H / game->ray_cast->perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		game->ray_cast->drawStart = -game->ray_cast->lineHeight / 2 + SCR_H / 2;
		if (game->ray_cast->drawStart < 0)
			game->ray_cast->drawStart = 0;
		game->ray_cast->drawEnd = game->ray_cast->lineHeight / 2 + SCR_H / 2;
		if (game->ray_cast->drawEnd >= SCR_H)
			game->ray_cast->drawEnd = SCR_H - 1;
		
		//choose wall color
		int color;
		switch(game->map->map_array[game->ray_cast->boxMapX][game->ray_cast->boxMapY])
		{
			case 1:  
				color = 0xFF0000;
				break; //red
			case 2:  
				color = 0x00FF00;
				break; //green
			case 3:
				color = 0x0000FF;
				break; //blue
			case 4:  
				color = 0xFFFFFF;
				break; //white
			default: 
				color = 0xFFFF00; 
				break; //yellow
		}
		//give x and y sides different brightness
		/* if (side == 1)
			color = color / 2; */
		//draw the pixels of the stripe as a vertical line
		verLine(i, game, color);
	}
}
