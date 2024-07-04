/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/04 11:59:19 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_error(t_game *game, int error)
{
	(void)game;
	if (error == EXIT_FAILURE)
		ft_printf(MAGENTA"\nSomething went wrong!\n\n"WHITE);
	else if (error == E_SYNTAX)
		ft_printf(MAGENTA"Bad map structure\nTry with a different map 😛\n\n"WHITE);
	clean_memmory(game);
	exit(error);
}

int	init_game(char *map_file, t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->n_players = 0;

	check_input_map(map_file, game);
	// if (!check_map(game->map))
	// 	ft_error(game, 1);
	// printf(GREEN"\nGOOD MAP!\n"WHITE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		ft_error(NULL, EXIT_FAILURE);
	init_game(av[1], &game);
	return (0);
}
