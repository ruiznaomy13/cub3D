/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/06/19 18:23:44 by marvin           ###   ########.fr       */
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
	game->texts = (t_textures *)ft_calloc(1, sizeof(t_textures));
	game->texts->wall = mlx_load_png("textures/minimap/wall_texture.png");
	game->texts->player = mlx_load_png("textures/minimap/player.png");
	game->texts->walle = mlx_load_png("textures/map/mossy.png");
	if (!game->texts->walle || !game->texts->wall || !game->texts->player)
		ft_error(game, EXIT_FAILURE);
	game->texts->texture_data = mlx_texture_to_image(game->mlx, game->texts->walle);
	game->texts->floor = ((game->map->floor_c[0] & 0xff) << 16) + ((game->map->floor_c[1] & 0xff) << 8) + (game->map->floor_c[2] & 0xff);
	game->texts->ceiling = ((game->map->ceiling_c[0] & 0xff) << 16) + ((game->map->ceiling_c[1] & 0xff) << 8) + (game->map->ceiling_c[2] & 0xff);
}

int	init_game(char *map_file, t_game *game)
{
	int	i;

	i = -1;
	game->mlx = mlx_init(SCR_W, SCR_H, "cub3D", false);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->mlx_win = mlx_new_image(game->mlx, SCR_W, SCR_H);
	game->map = ft_calloc(1, sizeof(t_map));
	game->n_players = 0;
	game->moves = 0;
	game->buffer = (unsigned int **)malloc(SCR_H * sizeof(int *));
    while (++i < SCR_H)
		game->buffer[i] = (unsigned int *)malloc(SCR_W * sizeof(int));

	check_input_map(map_file, game);
	if (!check_map(game->map))
		ft_error(game, 1);
	printf(GREEN"\nGOOD MAP!\n"WHITE);
	init_textures(game);
	init_ray(game);
	//store_map();
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		ft_error(NULL, EXIT_FAILURE);
	if (init_game(av[1], &game))
		return (1);
	mlx_loop_hook(game.mlx, &game_update, &game);
	mlx_close_hook(game.mlx, &close_button, &game);
	mlx_key_hook(game.mlx, key_event, &game);
	mlx_loop(game.mlx);
	return (0);
}
