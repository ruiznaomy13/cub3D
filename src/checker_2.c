/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:17:25 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/25 14:41:49 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* guarda el tamaño de la linea exacto, es decir el numero de caracteres */
int	line_length(char *line)
{
	int	i;

	i = 0;
	if (line[ft_strlen(line) - 1] == '\n')
		i = ft_strlen(line) - 2;
	else
		i = ft_strlen(line) - 1;
	while (line[i] == ' ' || line[i] == '\t')
		i--;
	return (i + 1);
}

int	skip_empty_line(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '\n')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
	}
	return (0);
}

int	inside_map_item(int item)
{
	if (item == SPACE)
		return (1);
	else if (item == P_N || item == P_S || item == P_E || item == P_W)
		return (1);
	return (0);
}

int	is_valid_path(char *line, char ***aux)
{
	int		fd;
	char	*file;

	file = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!file)
		return (free_charray(*aux), 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free_charray(*aux), 1);
	close(fd);
	free(file);
	return (free_charray(*aux), 0);
}
