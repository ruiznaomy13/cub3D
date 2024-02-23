/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:26:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/02/23 22:57:28 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"

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
	int	fd;

	fd = open(line, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	is_valid_color(char *line)
{
	char	**aux;
	int		i;
	int		len;

	i = 0;
	aux = ft_split(line, ',');
	if (!aux)
		return (1);
	len = arg_counter(aux);
	if (len != 3)
		return (1);
	while (i < 3)
	{
		if (ft_atoi(aux[0]) < 0)
			return (1);
		if (ft_atoi(aux[1]) < 0)
			return (1);
		if (ft_atoi(aux[2]) < 0)
			return (1);
	}
	return (0);
}

int	check_line_info(char *line, t_game *game)
{
	char **aux;

	aux = ft_split(line, ' ');
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
		else
			return (1);
	}
}
