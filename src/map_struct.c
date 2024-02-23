/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:00:32 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/23 23:01:00 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"

int	save_rgb(char *line, int *color_array)
{
	char	**aux;
	int		i;

	i = 0;
	aux = ft_split(line, ',');
	if (!aux)
		return (1);
	while (aux[i])
	{
		color_array[i] = ft_atoi(aux[i]);
		i++;
	}
	free_char_array(aux);
	return (0);
}

void	save_textures(char *line, t_game *game)
{
	int	i;

	i = first_char_pos(line);
	if (ft_strncmp (&line[i], "NO",2) == 0)
		game->map->texture_no = ft_strdup(&line[first_char_pos(&line[i + 2])]);
	else if (ft_strncmp (&line[i], "SO",2) == 0)
		game->map->texture_so = ft_strdup(&line[first_char_pos(&line[i + 2])]);
	else if (ft_strncmp (&line[i], "WE",2) == 0)
		game->map->texture_we = ft_strdup(&line[first_char_pos(&line[i + 2])]);
	else if (ft_strncmp (&line[i], "EA",2) == 0)
		game->map->texture_ea = ft_strdup(&line[first_char_pos(&line[i + 2])]);
	else if (ft_strncmp (&line[i], "F",1) == 0)
	{
		if (save_rgb(&line[first_char_pos(&line[i++])], game->map->floor_c))
			ft_error(game, EXIT_FAILURE);
	}
	else if (ft_strncmp (&line[i], "C",1) == 0)
	{
		if (save_rgb(&line[first_char_pos(&line[i++])], game->map->ceiling_c))
			ft_error(game, EXIT_FAILURE);
	}
}
