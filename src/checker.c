/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:44 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/30 14:03:21 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	read_dimension(int fd, t_map *map, char *map_file, int *map_row)
{
	char	*line;
	int		line_ln;

	line = get_next_line(fd);
	line_ln = 0;
	while (line)
	{
		line_ln = ft_strlen(line);
		if (get_first_char(line) == '1')
			map->rows += 1;
		if (map->cols < line_ln)
			map->cols = line_ln - 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->map_array = ft_calloc(map->rows, sizeof(int *));
	fd = open(map_file, O_RDONLY);
	*map_row = 0;
	return (fd);
}

int	check_map_name(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len < 4 || ft_strncmp(map_file + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

void	show_map(t_map *map)
{
	int i;
	int j;
	int	last;

	i = 0;
	last = 1;
	while (i < map->rows)
	{
		j = 0;
		write(1, "\n", 1);
		while (j < map->cols)
		{
			
			ft_printf("%d", map->map_array[i][j]);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	check_input_map(char *map_file, t_game *game)
{
	int		fd;
	int		map_row;

	fd = open(map_file, O_RDONLY);
	if (check_map_name(map_file) || fd < 0)
		ft_error(game, E_SYNTAX);
	fd = read_dimension(fd, game->map, map_file, &map_row);
	game->map->line = get_next_line(fd);
	while (game->map->line)
	{
		if (ft_strncmp(game->map->line, "\n", 1))
		{
			game->checker = check_line_info(game->map->line, game);
			if (game->checker == 0)
				save_textures(game->map->line, game);
			else if (game->checker == 2)
				save_map(game->map->line, game, &map_row);
			else
				ft_error(game, EXIT_FAILURE);
		}
		free(game->map->line);
		game->map->line = get_next_line(fd);
	}
	ft_printf("Game saved correctly!");
	show_map(game->map);
	printf("FIN DEL MAPA\n");
	return (EXIT_SUCCESS);
}
