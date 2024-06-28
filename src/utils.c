/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:47:28 by ncastell          #+#    #+#             */
/*   Updated: 2024/06/28 16:15:36 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_char_array(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	// str = NULL;
}

char	get_first_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (line[i]);
}

int	first_char_pos(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

// int	game_update(t_game *game)
// {
// 	int	p_status;

// 	p_status = 0;
// 	if (game->player)
// 		ft_raytracing(game);
		
// 		mlx_pixel_put(game->mlx, game->mlx_win, game->player->pos_x, game->player->pos_y, 0xFF0000);
// 	return (0);
// }
