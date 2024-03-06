/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:06:26 by eliagarc          #+#    #+#             */
/*   Updated: 2024/03/06 16:17:48 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(t_game game)
{
	int	i;
	int	j;
	int mult;

	mult = 0;
	i = 0;
	j = 0;
	while (i < game.map->rows)
	{
		while (j < (int)ft_strlen(game.map->map_guide[i]))
		{
			if (game.map->map_guide[i][j] == '\t')
				mult++;
			if (game.map->map_guide[i][j] == '1')
				mlx_put_image_to_window(game.mlx, game.mlx_win, \
				game.texts->wall, (j + (mult * 3)) * SQSZ, i * SQSZ);
			j++;
		}
		mult = 0;
		j = 0;
		i++;
	}
}