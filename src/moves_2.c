/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:37:43 by eliagarc          #+#    #+#             */
/*   Updated: 2024/08/12 17:55:23 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_move_aux(t_player player, t_ray ray, t_map map, int option)
{
	if (option == 3)
	{
		if ((player.pos_x - ray.plane_x * ray.mv_speed > 1.05 && player.pos_x - \
		ray.plane_x * ray.mv_speed < map.rows - 1.05) && (player.pos_y - \
		ray.plane_y * ray.mv_speed > 1.05 && player.pos_y - ray.plane_y * \
		ray.mv_speed < map.cols - 1.05))
			return (1);
	}
	else if (option == 4)
	{
		if ((player.pos_x + ray.plane_x * ray.mv_speed > 1.05 && player.pos_x + \
		ray.plane_x * ray.mv_speed < map.rows - 1.05) && (player.pos_y + \
		ray.plane_y * ray.mv_speed > 1.05 && player.pos_y + ray.plane_y * \
		ray.mv_speed < map.cols - 1.05))
			return (1);
	}
	return (0);
}

int	check_move(t_player player, t_ray ray, t_map map, int option)
{
	if (option == 1)
	{
		if ((player.pos_x - ray.dir_x * ray.mv_speed > 1.05 && player.pos_x - \
		ray.dir_x * ray.mv_speed < map.rows - 1.05) && (player.pos_y - \
		ray.dir_y * ray.mv_speed > 1.05 && player.pos_y - ray.dir_y * \
		ray.mv_speed < map.cols - 1.05))
			return (1);
	}
	else if (option == 2)
	{
		if ((player.pos_x + ray.dir_x * ray.mv_speed > 1.05 && player.pos_x + \
		ray.dir_x * ray.mv_speed < map.rows - 1.05) && (player.pos_y + \
		ray.dir_y * ray.mv_speed > 1.05 && player.pos_y + ray.dir_y * \
		ray.mv_speed < map.cols - 1.05))
			return (1);
	}
	else
		return (check_move_aux(player, ray, map, option));
	return (0);
}
