/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:06:26 by eliagarc          #+#    #+#             */
/*   Updated: 2024/03/05 20:24:50 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(t_game game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game.map->rows)
	{
		while (j < (int)ft_strlen(game.map->map_guide[i]))
		{
			if (game.map->map_guide[i][j] == '1')
				mlx_put_image_to_window(game.mlx, game.mlx_win, game.texts->wall, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}