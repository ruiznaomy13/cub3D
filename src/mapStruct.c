/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapStruct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:00:32 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/31 13:25:55 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	else if (!ft_strncmp (&line[*i], "F", 1))
		ret_value = 5;
	else if (!ft_strncmp (&line[*i], "C", 1))
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

int	is_valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
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

void	save_player(t_game *game, int p_orientation, int *map_row, int *i)
{
	game->map->map_array[*map_row][*i] = p_orientation;
	if (game->n_players == 0)
	{
		game->player = ft_calloc(1, sizeof(t_player));
		if (p_orientation == P_N)
			game->player->card_p = 'N';
		else if (p_orientation == P_S)
			game->player->card_p = 'S';
		else if (p_orientation == P_E)
			game->player->card_p = 'E';
		else if (p_orientation == P_W)
			game->player->card_p = 'W';
		game->player->pos_x = *map_row;
		game->player->pos_y = *i;
	}
	game->n_players++;
}

void	save_in_array(t_game *game, char *line, int *i, int *map_row)
{
	if (line[*i] == '\n' || !line[*i])
	{
		while (*i < game->map->cols)
			game->map->map_array[*map_row][(*i)++] = OUT_MAP;
		(*i)--;
	}
	else if (line[*i] == '0')
		game->map->map_array[*map_row][*i] = SPACE;
	else if (line[*i] == '1')
		game->map->map_array[*map_row][*i] = WALL;
	else if (line[*i] == 'N')
		save_player(game, P_N, map_row, i);
	else if (line[*i] == 'S')
		save_player(game, P_S, map_row, i);
	else if (line[*i] == 'E')
		save_player(game, P_E, map_row, i);
	else if (line[*i] == 'W')
		save_player(game, P_W, map_row, i);
	else if (line[*i] == ' ' || line[*i] == '\t')
		game->map->map_array[*map_row][*i] = OUT_MAP;
}

void	save_map(char *line, t_game *game, int *map_row)
{
	int	i;

	i = -1;
	if (!is_valid_line(line))
		return (ft_error(game, EXIT_FAILURE));
	if (*map_row <= game->map->rows)
	{
		game->map->map_array[*map_row] = \
		(int *)ft_calloc(sizeof(int), game->map->cols);
		if (!game->map->map_array[*map_row])
			return (ft_error(game, 0));
		while (++i < game->map->cols)
			save_in_array(game, line, &i, map_row);
		(*map_row)++;
	}
}
