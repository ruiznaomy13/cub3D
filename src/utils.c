/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:47:28 by ncastell          #+#    #+#             */
/*   Updated: 2024/08/12 17:55:33 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_event(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = param;
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
	{
		ft_printf("Key pressed: %d\t", key.key);
		if (key.key == 256)
		{
			ft_printf("\nGood bye!\n");
			close_button(game);
		}
		game->key = key.key;
		if ((key.key == RIGHT || key.key == RIGHT_D || key.key == LEFT \
		|| key.key == LEFT_A || key.key == DOWN_S \
		|| key.key == UP_W))
		{
			move_player(game);
			game->moves++;
		}
		ft_printf("\n");
	}
}

void	reset_buffer(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCR_H)
	{
		while (x < SCR_W)
		{
			game->buffer[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	print_all(t_game *game)
{
	print_border(game->mlx_win, game->texts, MPSZ);
	print_map(game->mlx_win, game->player, game->map, game->texts);
	if (SCR_H > 800 && SCR_W > 1000)
		print_hand(game);
	mlx_draw_texture(game->mlx_win, game->texts->player, \
	SCR_W - (SCR_W / 6), (SCR_H / 5));
}

void	game_update(void *param)
{
	t_game	*game;

	game = param;
	if (game->mlx_win)
	{
		mlx_delete_image(game->mlx, game->mlx_win);
		game->mlx_win = mlx_new_image(game->mlx, SCR_W, SCR_H);
	}
	ft_raycasting(game, &game->ray_cast);
	draw_buffer(game, game->buffer);
	mlx_image_to_window(game->mlx, game->mlx_win, 0, 0);
	mlx_set_instance_depth(game->mlx_win->instances, 3);
	reset_buffer(game);
	print_all(game);
}

char	*skip_config(char **line, int fd)
{
	*line = get_next_line(fd);
	while (*line && get_first_char(*line) != '1')
	{
		free(*line);
		*line = get_next_line(fd);
	}
	return (*line);
}
