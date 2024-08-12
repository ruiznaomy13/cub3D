/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:26:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/08/12 16:34:15 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map_name(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len < 4 || ft_strncmp(map_file + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

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

int	is_valid_color(char *line, char ***arr)
{
	char	**aux;
	int		i;
	int		len;
	char	*color;

	color = ft_substr(line, 0, ft_strlen(line));
	i = 0;
	aux = ft_split(color, ',');
	if (!aux)
		return (free(color), 1);
	len = arg_counter(aux);
	if (len != 3)
		return (free(color), free_charray(aux), free_charray(*arr), 1);
	while (i < 3)
	{
		if (ft_atoi(aux[i]) < 0)
			return (free(color), free_charray(aux), free_charray(*arr), 1);
		i++;
	}
	return (free(color), free_charray(aux), free_charray(*arr), 0);
}

int	read_dimension(int fd, t_game *game, char *map_file)
{
	char	*line;
	int		line_ln;

	game->map->rows = 0;
	game->map->cols = 0;
	line = skip_config(&line, fd);
	while (line)
	{
		line_ln = line_length(line);
		game->map->rows++;
		if (game->map->cols < line_ln)
			game->map->cols = line_ln;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->map_array = ft_calloc(game->map->rows, sizeof(int *));
	if (game->map->map_array == NULL)
		ft_error(game, EXIT_FAILURE);
	fd = open(map_file, O_RDONLY);
	return (fd);
}

/*
int	read_dimension(int fd, t_game *game, char *map_file)
{
	char	*line;
	int		line_ln;

	game->map->rows = 0;
	game->map->cols = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (get_first_char(line) == '1')
		{
			line_ln = line_length(line);
			game->map->rows++;
			if (game->map->cols < line_ln)
				game->map->cols = line_ln;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->map_array = ft_calloc(game->map->rows, sizeof(int *));
	if (game->map->map_array == NULL)
		ft_error(game, EXIT_FAILURE);
	fd = open(map_file, O_RDONLY);
	return (fd);
}*/
