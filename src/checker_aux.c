/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:26:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/02/23 22:41:34 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"

int	check_paths(t_game *game)
{
	if (game->map->texture_no == NULL)
		return (0);
	if (game->map->texture_so == NULL)
		return (0);
	if (game->map->texture_we == NULL)
		return (0);
	if (game->map->texture_ea == NULL)
		return (0);
	return (1);
}

int	check_line_info(char *line, t_game *game)
{
	char **aux;

	aux = ft_split(line, ' ');
	if (!ft_strncmp(aux[0], "NO", 3))
		return (0);
	else if (!ft_strncmp(aux[0], "SO", 3))	
		return (0);
	else if (!ft_strncmp(aux[0], "WE", 3))	
		return (0);
	else if (!ft_strncmp(aux[0], "EA", 3))
		return (0);
	else
	{
		if (get_first_char(aux[0]) == '1' && check_paths(game))
			return (2);
		else
			return (1);
	}
}
