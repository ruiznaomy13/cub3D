/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/02 16:21:45 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_error(t_game *game, int error)
{
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
	game->texts->floor = (0xff << 24) | ((game->map->floor_c[0] & 0xff) << 16) | ((game->map->floor_c[1] & 0xff) << 8) | (game->map->floor_c[2] & 0xff);
	game->texts->ceiling = (0xff << 24) | ((game->map->ceiling_c[0] & 0xff) << 16) | ((game->map->ceiling_c[1] & 0xff) << 8) | (game->map->ceiling_c[2] & 0xff);
	/* game->floor = mlx_new_image(game->mlx, SCR_W, SCR_H / 2);
	game->ceiling = mlx_new_image(game->mlx, SCR_W, SCR_H / 2);
	fill_color(game->floor, game->texts->floor);
	fill_color(game->ceiling, game->texts->ceiling);
	mlx_image_to_window(game->mlx, game->floor, 0, 0);
	mlx_image_to_window(game->mlx, game->ceiling, 0, SCR_H / 2); */
}

int	init_game(char *map_file, t_game *game)
{
	int	i;

	i = -1;
	game->mlx = mlx_init(SCR_W, SCR_H, "cub3D", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->mlx_win = mlx_new_image(game->mlx, SCR_W, SCR_H);
	if (!game->mlx_win)
		return (EXIT_FAILURE);
	game->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!game->map)
		return (EXIT_FAILURE);
	game->n_players = 0;
	game->moves = 0;
	game->buffer = (uint32_t **)ft_calloc(SCR_H, sizeof(uint32_t *));
	if (!game->buffer)
		return (EXIT_FAILURE);
    while (++i < SCR_H)
	{
		game->buffer[i] = (uint32_t *)ft_calloc(SCR_W, sizeof(uint32_t));
		if (!game->buffer[i])
			return (EXIT_FAILURE);
	}
	check_input_map(map_file, game);
	if (!check_map(game->map))
		ft_error(game, 1);
	printf(GREEN"\nGOOD MAP!\n"WHITE);
	init_textures(game);
	init_ray(game);
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_game	game;

	game = (t_game){};
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
