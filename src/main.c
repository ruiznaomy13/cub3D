/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:49 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/25 14:02:19 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	show_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		ft_printf("\n");
		while (j < map->cols)
		{
			ft_printf("%d", map->map_array[i][j]);
			j++;
		}
		i++;
	}
	ft_printf("\n");
}

void	ft_error(t_game *game, int error)
{
	if (error == EXIT_FAILURE)
		ft_printf(MAGENTA"\nSomething went wrong!\n\n"WHITE);
	else if (error == E_SYNTAX)
		ft_printf(MAGENTA"Bad map structure\nTry with a different map 😛\n\n"WHITE);
	clean_memmory(game);
	exit(error);
}

/* BAD SMELL */
void	init_textures(t_game *game)
{
	game->texts = (t_textures *)ft_calloc(1, sizeof(t_textures));
	game->texts->wall = mlx_load_png("textures/minimap/wall_texture.png");
	game->texts->player = mlx_load_png("textures/minimap/player.png");
	game->texts->walln = mlx_load_png(game->map->texture_no);
	game->texts->walls = mlx_load_png(game->map->texture_so);
	game->texts->wallw = mlx_load_png(game->map->texture_we);
	game->texts->walle = mlx_load_png(game->map->texture_ea);
	game->texts->black = mlx_load_png("textures/minimap/Black.png");
	game->texts->hand = mlx_load_png("textures/map/gun.png");
	if (!check_textures(game->texts) || !game->texts->wall || !game->texts->player)
		ft_error(game, EXIT_FAILURE);
	game->texts->texture_n = mlx_texture_to_image(game->mlx, game->texts->walln);
	game->texts->texture_s = mlx_texture_to_image(game->mlx, game->texts->walls);
	game->texts->texture_w = mlx_texture_to_image(game->mlx, game->texts->wallw);
	game->texts->texture_e = mlx_texture_to_image(game->mlx, game->texts->walle);
	game->texts->txt_black = mlx_texture_to_image(game->mlx, game->texts->black);
	game->texts->txt_hand = mlx_texture_to_image(game->mlx, game->texts->hand);
	game->texts->floor = get_rgba(game->map->floor_c[0], game->map->floor_c[1], game->map->floor_c[2], 0xFF);
	game->texts->ceiling = get_rgba(game->map->ceiling_c[0], game->map->ceiling_c[1], game->map->ceiling_c[2], 0xFF);
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
	show_map(game->map);
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
