/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/23 20:41:30 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"

int	ft_error(int error)
{
	if (error == EXIT_FAILURE)
		ft_printf(CYAN"\nSomething went wrong!\n\n");
	else if(error == E_SYNTAX)
		ft_printf("Bad map structure\nTry with a different map 😛");
	return (error);
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
		return (ft_error(EXIT_FAILURE));
	init_game(av[1], &game);
}
