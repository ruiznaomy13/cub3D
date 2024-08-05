/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:53:57 by eliagarc          #+#    #+#             */
/*   Updated: 2024/08/05 19:52:56 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_ray_aux(t_game *game)
{
	if (game->player->card_p == 'N')
	{
		game->ray_cast->dir_x = -1.0;
		game->ray_cast->dir_y = 0.0;
		game->ray_cast->plane_x = 0;
		game->ray_cast->plane_y = -0.66;
	}
	if (game->player->card_p == 'S')
	{
		game->ray_cast->dir_x = 1.0;
		game->ray_cast->dir_y = 0.0;
		game->ray_cast->plane_x = 0;
		game->ray_cast->plane_y = 0.66;
	}
}

void	init_ray(t_game *game)
{
	game->ray_cast = ft_calloc(1, sizeof(t_ray));
	if (!game->ray_cast)
		ft_error(game, EXIT_FAILURE);
	game->ray_cast->mv_speed = 0.15;
	game->ray_cast->rot_speed = 0.15;
	if (game->player->card_p == 'W')
	{
		game->ray_cast->dir_x = 0.0;
		game->ray_cast->dir_y = -1.0;
		game->ray_cast->plane_x = 0.66;
		game->ray_cast->plane_y = 0;
	}
	if (game->player->card_p == 'E')
	{
		game->ray_cast->dir_x = 0.0;
		game->ray_cast->dir_y = 1.0;
		game->ray_cast->plane_x = -0.66;
		game->ray_cast->plane_y = 0;
	}
	init_ray_aux(game);
}

static void	get_direction(t_game *game)
{
	if (game->ray_cast->r_dirx < 0)
	{
		game->ray_cast->step_x = -1;
		game->ray_cast->sidedist_x = (game->player->pos_x - \
		game->ray_cast->boxmap_x) * game->ray_cast->deltadist_x;
	}
	else
	{
		game->ray_cast->step_x = 1;
		game->ray_cast->sidedist_x = ((double)game->ray_cast->boxmap_x + 1.0 - \
		game->player->pos_x) * game->ray_cast->deltadist_x;
	}
	if (game->ray_cast->r_diry < 0)
	{
		game->ray_cast->step_y = -1;
		game->ray_cast->sidedist_y = (game->player->pos_y - \
		game->ray_cast->boxmap_y) * game->ray_cast->deltadist_y;
	}
	else
	{
		game->ray_cast->step_y = 1;
		game->ray_cast->sidedist_y = ((double)game->ray_cast->boxmap_y + 1.0 - \
		game->player->pos_y) * game->ray_cast->deltadist_y;
	}
}

static void	perf_dda(t_game *game, int *hit, int *side)
{
	*hit = 0;
	while (*hit == 0)
	{
		if (game->ray_cast->sidedist_x < game->ray_cast->sidedist_y)
		{
			game->ray_cast->sidedist_x += game->ray_cast->deltadist_x;
			game->ray_cast->boxmap_x += game->ray_cast->step_x;
			*side = 0;
		}
		else
		{
			game->ray_cast->sidedist_y += game->ray_cast->deltadist_y;
			game->ray_cast->boxmap_y += game->ray_cast->step_y;
			*side = 1;
		}
		if (game->ray_cast->boxmap_y < 0 || game->ray_cast->boxmap_x < 0 || \
		game->ray_cast->boxmap_y > SCR_W || game->ray_cast->boxmap_x > SCR_H)
			break ;
		if (game->map->map_array[game->ray_cast->boxmap_x] \
		[game->ray_cast->boxmap_y] == 1)
			*hit = 1;
	}
}

void	ft_raycasting(t_game *game, t_ray **rcst)
{
	int	i;
	int	hit;
	int	side;

	if (game->moves != 0)
		draw_buffer(game, game->buffer);
	i = -1;
	while (++i < SCR_W)
	{
		get_raycast(&game->ray_cast, i, game->player);
		get_direction(game);
		perf_dda(game, &hit, &side);
		if (side == 0)
			(*rcst)->walldist = (*rcst)->sidedist_x - (*rcst)->deltadist_x;
		else
			(*rcst)->walldist = (*rcst)->sidedist_y - (*rcst)->deltadist_y;
		(*rcst)->line_h = (int)(SCR_H / (*rcst)->walldist);
		(*rcst)->draw_start = -(*rcst)->line_h / 2 + SCR_H / 2;
		if ((*rcst)->draw_start < 0)
			(*rcst)->draw_start = 0;
		(*rcst)->draw_end = (*rcst)->draw_start + (*rcst)->line_h;
		if ((*rcst)->draw_end >= SCR_H)
			(*rcst)->draw_end = SCR_H - 1;
		render(game, side, i);
	}
}
