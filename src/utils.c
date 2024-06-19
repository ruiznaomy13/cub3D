/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:47:28 by ncastell          #+#    #+#             */
/*   Updated: 2024/06/19 18:59:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_char_array(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}

char	get_first_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (line[i]);
}

int	first_char_pos(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

void	key_event(mlx_key_data_t key, void *param)
{
	t_game *game;

	game = param;
	ft_printf("Key pressed: %d\t", key.key);
	if (key.key == 256)
	{
		ft_printf("\nGood bye!\n");
		close_button(game);
	}
	game->key = key.key;
	if ((key.key == RIGHT || key.key == RIGHT_D || key.key == LEFT \
	|| key.key == LEFT_A || key.key == DOWN || key.key == DOWN_S \
	|| key.key == UP || key.key == UP_W))
	{
		move_player(game);
		game->moves++;
	}
	ft_printf("\n");
}

void	game_update(void *param)
{
	t_game	*game;
	int	x;
	int	y;

	game = param;
	x = 0;
	y = 0;
	if (game->player)
	{
		ft_raytracing(game);
		drawBuffer(game, game->buffer);
		clear_pixels(game->mlx_win);
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
		print_map(*game);
		mlx_image_to_window(game->mlx, game->mlx_win, 0, 0);
	}
}
