/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:44 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/23 20:41:09 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"

int	check_map_name(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len < 4 || ft_strncmp(map_file + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

void	save_textures(char *line, t_game *game)
{
	if ()
	{
		/* code */
	}
	
}

int	check_input_map(char *map_file, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (check_map_name(map_file) || fd < 0)
		return (EXIT_FAILURE);
	// fd = read_dimension(fd, game->map, map_file);
	line = get_next_line(fd);
	(void)game;
	while (line)
	{
		if (game->checker == 0)
			save_textures(line, game);
		// else (game->checker == 2)
		// 	save_map(map_file, game);
		else
			ft_error(EXIT_FAILURE);
	}
	ft_printf("Game saved correctly!");
	return (EXIT_SUCCESS);
}