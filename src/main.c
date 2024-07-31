/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/31 13:46:05 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_error(t_game *game, int error)
{
	if (error == EXIT_FAILURE)
		ft_printf(MAGENTA"\nSomething went wrong!\n\n"WHITE);
	else if (error == E_SYNTAX)
	{
		ft_printf(MAGENTA"Bad map structure\n");
		ft_printf("Try with a different map 😛\n\n"WHITE);
	}
	clean_memmory(game);
	exit(error);
}

int	init_textures(t_textures **texts, t_map map, mlx_t *mlx)
{
	*texts = (t_textures *)ft_calloc(1, sizeof(t_textures));
	if (!*texts)
		return (EXIT_FAILURE);
	(*texts)->wall = mlx_load_png("textures/minimap/wall_texture.png");
	(*texts)->player = mlx_load_png("textures/minimap/player.png");
	(*texts)->walln = mlx_load_png(map.texture_no);
	(*texts)->walls = mlx_load_png(map.texture_so);
	(*texts)->wallw = mlx_load_png(map.texture_we);
	(*texts)->walle = mlx_load_png(map.texture_ea);
	(*texts)->black = mlx_load_png("textures/minimap/Black.png");
	(*texts)->hand = mlx_load_png("textures/map/gun.png");
	(*texts)->texture_n = mlx_texture_to_image(mlx, (*texts)->walln);
	(*texts)->texture_s = mlx_texture_to_image(mlx, (*texts)->walls);
	(*texts)->texture_w = mlx_texture_to_image(mlx, (*texts)->wallw);
	(*texts)->texture_e = mlx_texture_to_image(mlx, (*texts)->walle);
	(*texts)->txt_black = mlx_texture_to_image(mlx, (*texts)->black);
	(*texts)->txt_hand = mlx_texture_to_image(mlx, (*texts)->hand);
	if (!check_textures(*texts))
		return (EXIT_FAILURE);
	(*texts)->floor = get_rgba(map.floor_c[0], \
	map.floor_c[1], map.floor_c[2], 0xFF);
	(*texts)->ceiling = get_rgba(map.ceiling_c[0], \
	map.ceiling_c[1], map.ceiling_c[2], 0xFF);
	return (0);
}

static int	init_game_aux(t_game *game)
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
	game->buffer = (uint32_t **)ft_calloc(SCR_H, sizeof(uint32_t *));
	if (!game->buffer)
		return (EXIT_FAILURE);
	while (++i < SCR_H)
	{
		game->buffer[i] = (uint32_t *)ft_calloc(SCR_W, sizeof(uint32_t));
		if (!game->buffer[i])
			return (EXIT_FAILURE);
	}
	return (0);
}

int	init_game(char *map_file, t_game *game)
{
	if (init_game_aux(game))
		return (EXIT_FAILURE);
	check_input_map(map_file, game);
	if (!check_map(game->map))
		ft_error(game, 1);
	if (init_textures(&game->texts, *game->map, game->mlx))
		ft_error(game, EXIT_FAILURE);
	init_ray(game);
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_game	game;

	game = (t_game){};
	if (ac != 2 || check_resolution())
		ft_error(NULL, EXIT_FAILURE);
	if (init_game(av[1], &game))
		return (1);
	mlx_loop_hook(game.mlx, &game_update, &game);
	mlx_close_hook(game.mlx, &close_button, &game);
	mlx_key_hook(game.mlx, key_event, &game);
	mlx_loop(game.mlx);
	return (0);
}
