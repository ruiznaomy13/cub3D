/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/30 13:37:26 by ncastell         ###   ########.fr       */
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

void	init_textures(t_game *game)
{
	int	wd_width;
	int	wd_height;

	game->texts = (t_textures *)ft_calloc(1, sizeof(t_textures));
	game->texts->wall = mlx_xpm_file_to_image(game->mlx,\
	"textures/walls/wall_texture.xpm", &wd_width, &wd_height);
}

int	init_game(char *map_file, t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, SCR_W, SCR_H, "cub3D");
	game->map = ft_calloc(1, sizeof(t_map));

	check_input_map(map_file, game);
	// init_textures(game);
	//init_ray(game);
	// store_map();
	return (EXIT_SUCCESS);
}
int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		ft_error(NULL, EXIT_FAILURE);
	init_game(av[1], &game);
	// print_map(game);
	// mlx_loop(game.mlx);
	// while(game.end == 0)
	// {
		
	// }
	//clean_memmory(&game);
	return (0);
}
