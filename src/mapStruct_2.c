/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapStruct_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:38:53 by eliagarc          #+#    #+#             */
/*   Updated: 2024/08/13 18:06:15 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	save_rgb(char *line, int *color_array)
{
	char	**aux;
	int		i;

	i = -1;
	aux = ft_split(&line[first_char_pos(line)], ',');
	if (!aux)
		return (1);
	while (aux[++i])
	{
		color_array[i] = ft_atoi(aux[i]);
	}
	free_charray(aux);
	return (0);
}

void	save_textures(char *line, t_game *game)
{
	int	i;
	int	aux;

	aux = 0;
	if (is_map_texture(line, &i, &aux) == 1 && !game->map->texture_no)
		game->map->texture_no = ft_substr(&line[i], aux, \
		ft_strlen(&line[aux + i]) - 1);
	else if (is_map_texture(line, &i, &aux) == 2 && !game->map->texture_so)
		game->map->texture_so = ft_substr(&line[i], aux, \
		ft_strlen(&line[aux + i]) - 1);
	else if (is_map_texture(line, &i, &aux) == 3 && !game->map->texture_we)
		game->map->texture_we = ft_substr(&line[i], aux, \
		ft_strlen(&line[aux + i]) - 1);
	else if (is_map_texture(line, &i, &aux) == 4 && !game->map->texture_ea)
		game->map->texture_ea = ft_substr(&line[i], aux, \
		ft_strlen(&line[aux + i]) - 1);
	else if (is_map_texture(line, &i, &aux) == 5 && \
	!check_cf(game->map->floor_c))
		save_rgb(&line[first_char_pos(&line[i])], game->map->floor_c);
	else if (is_map_texture(line, &i, &aux) == 6 && \
	!check_cf(game->map->ceiling_c))
		save_rgb(&line[first_char_pos(&line[i++])], game->map->ceiling_c);
	else
		ft_error(game, EXIT_FAILURE);
}

int	check_cf(int cf[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (cf[i] != -1)
			return (1);
		i++;
	}
	return (0);
}
