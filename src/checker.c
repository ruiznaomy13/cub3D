/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:44 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/04 17:00:33 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_square(t_map *map, t_point iter, int *check)
{
	if ((iter.x < 1 || iter.x >= map->rows - 1) \
	|| (iter.y < 1 || iter.y >= map->cols - 1))
	{
		*check = 1;
		return ;
	}
	if (map->map_array[iter.x - 1][iter.y] == -1 || \
	map->map_array[iter.x - 1][iter.y] == -1)
		*check = 1;
	else if (map->map_array[iter.x][iter.y - 1] == -1 || \
	map->map_array[iter.x][iter.y + 1] == -1)
		*check = 1;
	else if (map->map_array[iter.x - 1][iter.y - 1] == -1 || \
	map->map_array[iter.x - 1][iter.y + 1] == -1)
		*check = 1;
	else if (map->map_array[iter.x + 1][iter.y + 1] == -1 || \
	map->map_array[iter.x + 1][iter.y - 1] == -1)
		*check = 1;
}

int	inside_map_item(int item)
{
	if (item == SPACE)
		return (1);
	else if (item == P_N || item == P_S || item == P_E || item == P_W)
		return (1);
	return (0);
}

// x -> rows
// y -> cols
int	check_map(t_map *map)
{
	t_point	iter;
	int	check;
	
	iter.x = 0;
	iter.y = 0;
	check = 0;
	printf("rows: %d | cols: %d\n", map->rows, map->cols); // __BORRAR__
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

/* guarda el tamaño de la linea exacto, es decir el numero de caracteres */
int	line_length(char *line)
{
	int	i = 0;

	if (line[ft_strlen(line) - 1] == '\n')
		i = ft_strlen(line) - 2;
	else
		i = ft_strlen(line) - 1;
	while (line[i] == ' ' || line[i] == '\t')
		i--;
	return (i + 1);
}

int	read_dimension(int fd, t_game *game, char *map_file)
{
	char	*line;
	int		line_ln;

	game->map->rows = 0;
	game->map->cols = 0;
	line = get_next_line(fd);
	line_ln = 0;
	while (line)
	{
		line_ln = line_length(line);
		if (get_first_char(line) == '1')
		{
			ft_printf("%s", line); // __BORRAR__
			game->map->rows++;
			if (game->map->cols < line_ln)
				game->map->cols = line_ln;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf(MAGENTA"\nCOLS = %d\nROWS = %d\n\n", game->map->cols, game->map->rows); // __BORRAR__
	game->map->map_array = ft_calloc(game->map->rows, sizeof(int *));
	if (game->map->map_array == NULL)
		ft_error(game, EXIT_FAILURE);
	fd = open(map_file, O_RDONLY);
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

int	skip_empty_line(char *str)
{
	int	i = -1;

	while (str[++i] && str[i] != '\n')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
	}
	return (0);
}

int	check_input_map(char *map_file, t_game *game)
{
	int		fd;
	int		map_row = 0;

	fd = open(map_file, O_RDONLY);
	if (check_map_name(map_file) || fd < 0)
		ft_error(game, E_SYNTAX);
	fd = read_dimension(fd, game, map_file);
	if (fd == -1)
		ft_error(game, EXIT_FAILURE);
	game->map->line = get_next_line(fd);
	while (game->map->line)
	{
		if (skip_empty_line(game->map->line))
		{
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
	ft_printf(GREEN"Game saved correctly!\n");
	check_players(game);
	return (EXIT_SUCCESS);
}
