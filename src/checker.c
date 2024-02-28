/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:44 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/28 20:50:11 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"

int	read_dimension(int fd, t_map *map, char *map_file)
{
	char *line;

	line = get_next_line(fd);
	while (line)
	{
		if (get_first_char(line) == '1')
			map->rows += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(map_file, O_RDONLY);
	return (fd);
}

int check_map_name(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len < 4 || ft_strncmp(map_file + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	check_input_map(char *map_file, t_game *game)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (check_map_name(map_file) || fd < 0)
		ft_error(game, E_SYNTAX);
	fd = read_dimension(fd, game->map, map_file);
	game->map->line = get_next_line(fd);
	while (game->map->line) // read line by line of the file
	{
		if (ft_strncmp(game->map->line, "\n", 1))
		{
			game->checker = check_line_info(game->map->line, game);
			if (game->checker == 0)
				save_textures(game->map->line, game);
			else if (game->checker == 2)
				return (EXIT_SUCCESS); //(map_file, game);
			else
				ft_error(game, EXIT_FAILURE);
		}
		free(game->map->line);
		game->map->line = get_next_line(fd);
	}
	ft_printf("Game saved correctly!");
	return (EXIT_SUCCESS);
}