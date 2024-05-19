/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:47:28 by ncastell          #+#    #+#             */
/*   Updated: 2024/05/19 23:14:48 by elias            ###   ########.fr       */
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

int	key_event(int key, t_game *game)
{
	ft_printf("Key pressed: %d\t", key);
	if (key == 53)
	{
		ft_printf("\nGood bye!\n");
		close_button(game, 1);
		exit(EXIT_SUCCESS);
	}
	game->key = key;
	if (!(key == RIGHT || key == RIGHT_D || key == LEFT \
	|| key == LEFT_A || key == DOWN || key == DOWN_S \
	|| key == UP || key == UP_W))
		ft_printf("\n");
	else
	{
		move_player(game);
		game->moves++;
	}
	return (0);
}

int	game_update(t_game *game)
{
	if (game->player)
	{
		ft_raytracing(game);
		drawBuffer(game, game->buffer);
    	for(int y = 0; y < SCR_H; y++)
		{
			for(int x = 0; x < SCR_W; x++)
				game->buffer[y][x] = 0;
		}
		print_map(*game);
	}
	return (0);
}
