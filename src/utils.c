/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:47:28 by ncastell          #+#    #+#             */
/*   Updated: 2024/05/13 17:30:45 by eliagarc         ###   ########.fr       */
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
	if (!(key == RIGHT || key == RIGHT_D || key == LEFT \
	|| key == LEFT_A || key == DOWN || key == DOWN_S \
	|| key == UP || key == UP_W))
		ft_printf("\n");
	game->key = key;
	move_player(game);
	return (0);
}

int	game_update(t_game *game)
{
	int	p_status;

	p_status = 0;
	if (game->player)
	{
		ft_raytracing(game);
		mlx_clear_window(game->mlx, game->mlx_win);
		
	}
	
	mlx_pixel_put(game->mlx, game->mlx_win, game->player->pos_x, game->player->pos_y, 0xFF0000);
	return (0);
}
