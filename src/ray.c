/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:53:57 by eliagarc          #+#    #+#             */
/*   Updated: 2024/05/16 06:03:27 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dir_ray(t_game *game)
{
	if (game->player->card_p == 'N')
	{
		game->ray_cast->dirX = 0.0;
		game->ray_cast->dirY = 1.0;
	}
	if (game->player->card_p == 'S')
	{
		game->ray_cast->dirX = 0.0;
		game->ray_cast->dirY = -1.0;
	}
	if (game->player->card_p == 'W')
	{
		game->ray_cast->dirX = -1.0;
		game->ray_cast->dirY = 0.0;
	}
	if (game->player->card_p == 'O')
	{
		game->ray_cast->dirX = 1.0;
		game->ray_cast->dirY = 0.0;
	}
	game->ray_cast->planeX = 0.0;
	game->ray_cast->planeY = 0.66;
}

void	init_ray(t_game *game)
{
	game->ray_cast = ft_calloc(1, sizeof(t_ray));
	game->ray_cast->moveSpeed = 0.3;
	game->ray_cast->rotSpeed = 0.1;
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
		if (game->map->map_array[game->ray_cast->boxMapX][game->ray_cast->boxMapY] == 1)
			*hit = 1;
		mlx_pixel_put(game->mlx, game->mlx_win, SCR_W/2 + game->ray_cast->boxMapY * SQSZ, game->ray_cast->boxMapX * SQSZ, 0x00FF00);
	}
}

void	ft_raytracing(t_game *game)
{
	int	i;
	int	hit;
	int	side;

	i = 0;
	printf("%.2f\n", game->ray_cast->dirX);
	printf("%.2f\n", game->ray_cast->dirY);
	while (i < SCR_W /2)
	{
		game->ray_cast->cameraX = 2 * i / (double)SCR_W - 1;
		game->ray_cast->rayDirX = game->ray_cast->dirX + game->ray_cast->planeX * game->ray_cast->cameraX;
		game->ray_cast->rayDirY = game->ray_cast->dirY + game->ray_cast->planeY * game->ray_cast->cameraX;
		game->ray_cast->boxMapX = (int)game->player->pos_x;
		game->ray_cast->boxMapY = (int)game->player->pos_y;
		if (game->ray_cast->rayDirX == 0)
			game->ray_cast->deltaDistX = 1e30;
		else
			game->ray_cast->deltaDistX = fabs(1 / game->ray_cast->rayDirX);
		if (game->ray_cast->rayDirY == 0)
			game->ray_cast->deltaDistY = 1e30;
		else
			game->ray_cast->deltaDistY = fabs(1 / game->ray_cast->rayDirY);
		
		getDirection(game);
		perfDDA(game, &hit, &side);
		if (side == 0)
			game->ray_cast->perpWallDist = game->ray_cast->sideDistX - game->ray_cast->deltaDistX;
		else
			game->ray_cast->perpWallDist = game->ray_cast->sideDistY - game->ray_cast->deltaDistY;

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
			default: 
				color = 0xFFFF00; 
				break; //yellow
		}
		// (void)color;
		//give x and y sides different brightness
		/* if (side == 1)
			color = color / 2; */
		verLine(i, game, color);
		i++;
	}
}
