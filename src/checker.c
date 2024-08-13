/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:44 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/13 18:06:34 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_line_info(char *line, t_game *game)
{
	char	**aux;

	aux = ft_split_cub(line);
	if (!aux)
		return (1);
	if (!ft_strncmp(aux[0], "NO", 3))
		return (is_valid_path(aux[1], &aux));
	else if (!ft_strncmp(aux[0], "SO", 3))
		return (is_valid_path(aux[1], &aux));
	else if (!ft_strncmp(aux[0], "WE", 3))
		return (is_valid_path(aux[1], &aux));
	else if (!ft_strncmp(aux[0], "EA", 3))
		return (is_valid_path(aux[1], &aux));
	else if (!ft_strncmp(aux[0], "F", 2))
		return (is_valid_color(aux[1], &aux));
	else if (!ft_strncmp(aux[0], "C", 2))
		return (is_valid_color(aux[1], &aux));
	else
	{
		if (get_first_char(aux[0]) == '1' && check_paths(game))
			return (free_charray(aux), 2);
	}
	return (free_charray(aux), 1);
}

int	check_map(t_map *map)
{
	t_point	iter;
	int		check;

	iter.x = 0;
	iter.y = 0;
	check = 0;
	while (iter.x < map->rows && !check)
	{
		iter.y = 0;
		while (iter.y < map->cols && !check)
		{
			if (inside_map_item(map->map_array[iter.x][iter.y]))
				check_square(map, iter, &check);
			iter.y++;
		}
		iter.x++;
	}
	if (check)
		return (0);
	return (1);
}

void	check_players(t_game *game)
{
	if (game->n_players != 1)
		ft_error(game, EXIT_FAILURE);
}

void	store_map_info(t_game *game, int map_row, int fd)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		game->map->ceiling_c[i] = -1;
		game->map->floor_c[i] = -1;
		i++;
	}
	while (game->map->line)
	{
		if (skip_empty_line(game->map->line, game->checker))
		{
			if (game->checker != 2)
				game->checker = check_line_info(game->map->line, game);
			if (game->checker == 0)
				save_textures(game->map->line, game);
			else if (game->checker == 2)
				save_map(game->map->line, game, &map_row);
			else if (game->checker != 2)
				ft_error(game, EXIT_FAILURE);
		}
		free(game->map->line);
		game->map->line = get_next_line(fd);
	}
}

void	check_input_map(char *map_file, t_game *game)
{
	int		fd;
	int		map_row;

	map_row = 0;
	fd = open(map_file, O_RDONLY);
	if (check_map_name(map_file) || fd < 0)
		ft_error(game, E_SYNTAX);
	fd = read_dimension(fd, game, map_file);
	if (fd == -1)
		ft_error(game, EXIT_FAILURE);
	game->map->line = get_next_line(fd);
	store_map_info(game, map_row, fd);
	close(fd);
	check_players(game);
}
