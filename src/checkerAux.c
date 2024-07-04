/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerAux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:26:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/07/04 16:39:30 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	if (game->map->floor_c[0] == -1)
		return (0);
	if (game->map->ceiling_c[0] == -1)
		return (0);
	return (1);
}

int	is_valid_path(char *line)
{
	int		fd;
	char 	*file;

	file = ft_substr(line, 0, ft_strlen(line) - 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	free(file);
	return (0);
}

int	is_valid_color(char *line)
{
	char	**aux;
	int		i;
	int		len;
	char	*color;

	color = ft_substr(line, 0, ft_strlen(line) - 1);
	i = 0;
	aux = ft_split(color, ',');
	if (!aux)
		return (1);
	len = arg_counter(aux);
	if (len != 3)
		return (free(color), free_char_array(aux), 1);
	while (i < 3)
	{
		if ((int)ft_atoi(aux[i]) < 0)
		{
			return (free(color), free_char_array(aux), 1);
		}
		i++;
	}
	return (free(color), free_char_array(aux), 0);
}

int	check_line_info(char *line, t_game *game)
{
	char **aux;

	aux = ft_split_cub(line);
	if (!aux)
		return (1);
	if (!ft_strncmp(aux[0], "NO", 3))
		return (is_valid_path(aux[1]));
	else if (!ft_strncmp(aux[0], "SO", 3))	
		return (is_valid_path(aux[1]));
	else if (!ft_strncmp(aux[0], "WE", 3))	
		return (is_valid_path(aux[1]));
	else if (!ft_strncmp(aux[0], "EA", 3))
		return (is_valid_path(aux[1]));
	else if (!ft_strncmp(aux[0], "F", 2))
		return (is_valid_color(aux[1]));
	else if (!ft_strncmp(aux[0], "C", 2))
		return (is_valid_color(aux[1]));
	else
	{
		if (get_first_char(aux[0]) == '1' && check_paths(game))
			return (2);
	}
	return (1);
}

void	check_players(t_game *game)
{
	if (game->n_players > 1)
		ft_error(game, EXIT_FAILURE);
}
