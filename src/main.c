/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/05/20 01:37:08 by elias            ###   ########.fr       */
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
	"textures/minimap/wall_texture.xpm", &wd_width, &wd_height);
	game->texts->player = mlx_xpm_file_to_image(game->mlx, "textures/minimap/player.xpm", &wd_width, &wd_height);
	game->texts->walle = mlx_xpm_file_to_image(game->mlx, "textures/map/mossy.xpm", &wd_height, &wd_height);
	if (!game->texts->walle || !game->texts->wall || !game->texts->player)
		ft_error(game, EXIT_FAILURE);
	game->texts->texture_data = mlx_get_data_addr(game->texts->walle, &game->texts->bpp, &game->texts->size_line, &game->texts->endian);
	game->texts->floor = ((game->map->floor_c[0] & 0xff) << 16) + ((game->map->floor_c[1] & 0xff) << 8) + (game->map->floor_c[2] & 0xff);
	game->texts->ceiling = ((game->map->ceiling_c[0] & 0xff) << 16) + ((game->map->ceiling_c[1] & 0xff) << 8) + (game->map->ceiling_c[2] & 0xff);
}

int	init_game(char *map_file, t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, SCR_W, SCR_H, "cub3D");
	game->map = ft_calloc(1, sizeof(t_map));
	game->n_players = 0;
	game->moves = 0;
	game->buffer = (unsigned int **)malloc(SCR_H * sizeof(int *));
    for (int i = 0; i < SCR_H; i++)
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
	init_game(av[1], &game);
	print_map(game);
	mlx_loop_hook(game.mlx, &game_update, &game);
	mlx_hook(game.mlx_win, 17, 1L << 17, &close_button, &game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_event, &game);
	mlx_loop(game.mlx);
	clean_memmory(&game);
	return (0);
}
