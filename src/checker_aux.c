/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:26:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/02/23 22:33:57 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"

int	check_paths(char *line)
{
	if (!ft_strncmp(line, "NO", 3))
		return (0);
	else if (!ft_strncmp(line, "SO", 3))	
		return (0);
	else if (!ft_strncmp(line, "WE", 3))	
		return (0);
	else if (!ft_strncmp(line, "EA", 3))
		return (0);
	else
	{
		if (get_first_char(line) == '1')
			return (2);
		else
			return (1);
	}
}

int	check_line_info(char *line, t_game *game)
{
	char **aux;

	aux = ft_split(line, ' ');
	if (!check_paths(aux[0]))
}