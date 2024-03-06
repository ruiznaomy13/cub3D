/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapStruct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:00:32 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/06 16:33:51 by ncastell         ###   ########.fr       */
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
		color_array[i] = ft_atoi(aux[i]);
	free_char_array(aux);
	return (0);
}

int	is_map_texture(char *line, int *i, int *aux)
{
	int	ret_value;

	ret_value = 0;
	*i = first_char_pos(line);
	if (!ft_strncmp (&line[*i], "NO", 2))
		ret_value = 1;
	else if (!ft_strncmp (&line[*i], "SO", 2))
		ret_value = 2;
	else if (!ft_strncmp (&line[*i], "WE", 2))
		ret_value = 3;
	else if (!ft_strncmp (&line[*i], "EA", 2))
		ret_value = 4;
	else if (!ft_strncmp (&line[*i], "F",1))
		ret_value = 5;
	else if (!ft_strncmp (&line[*i], "C",1))
		ret_value = 6;
	if (ret_value != 0)
	{
		*i += 2;
		if (ret_value > 4)
			*i -= 1;
		*aux = first_char_pos(&line[*i]);
	}
	return (ret_value);
}

void	save_textures(char *line, t_game *game)
{
	int	i;
	int	aux;

	if (is_map_texture(line, &i, &aux) == 1)
		game->map->texture_no = ft_substr(&line[i], aux, \
		ft_strlen(&line[aux + i]) - 1);
	else if (is_map_texture(line, &i, &aux) == 2)
		game->map->texture_so = ft_substr(&line[i], aux, \
		ft_strlen(&line[aux + i]) - 1);
	else if (is_map_texture(line, &i, &aux) == 3)
		game->map->texture_we = ft_substr(&line[i], aux, \
		ft_strlen(&line[aux + i]) - 1);
	else if (is_map_texture(line, &i, &aux) == 4)
		game->map->texture_ea = ft_substr(&line[i], aux, \
		ft_strlen(&line[aux + i]) - 1);
	if (is_map_texture(line, &i, &aux) == 5)
	{
		if (save_rgb(&line[first_char_pos(&line[i])], game->map->floor_c))
			ft_error(game, EXIT_FAILURE);
	}
	else if (is_map_texture(line, &i, &aux) == 6)
	{
		if (save_rgb(&line[first_char_pos(&line[i++])], game->map->ceiling_c))
			ft_error(game, EXIT_FAILURE);
	}
}

static int	is_valid_line(char *line, int *index)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	*index = i;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' \
		&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E' \
		&& line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	save_map(char *line, t_game *game, int *map_row)
{
	int		i;

	i = 0;
	if (!is_valid_line(line, &i))
		return (ft_error(game, EXIT_FAILURE));
	game->map->map_guide[*map_row] = ft_substr(line, 0, \
	ft_strlen(line) - 1);
	*map_row += 1;
}
