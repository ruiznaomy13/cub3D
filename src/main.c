/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/28 18:31:56 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"

void	ft_error(t_game *game, int error)
{
	(void)game;
	if (error == EXIT_FAILURE)
		ft_printf(MAGENTA"\nSomething went wrong!\n\n"WHITE);
	else if (error == E_SYNTAX)
		ft_printf(MAGENTA"Bad map structure\nTry with a different map 😛\n\n"WHITE);
	// free_game(game);
	exit(error);
}

int	init_game(char *map_file, t_game *game)
{
	game = ft_calloc(1, sizeof(t_game));
	game->map = ft_calloc(1, sizeof(t_map));
	game->map->rows = 0;

	check_input_map(map_file, game);
		// save_map(map_file, game->map);
	// store_map();
	return (EXIT_SUCCESS);
}
int	main(int ac, char *av[])
{
	t_game	game;

	/* void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_new_window(mlx, SCR_W, SCR_H, "cubu3D");
	mlx_loop(mlx);*/
	if (ac != 2)
		ft_error(NULL, EXIT_FAILURE);
	init_game(av[1], &game);
	return (0);
}
