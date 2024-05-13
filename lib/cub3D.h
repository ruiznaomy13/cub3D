/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/05/13 16:09:23 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structures.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

int		main(int ac, char *av[]);

/* MAIN */
void	ft_error(t_game *game, int error);
void	init_textures(t_game *game);
int     init_game(char *map_file, t_game *game);

/* FREE GAME */
void	clean_memmory(t_game *game);

/* FT_FREE_GAME */
void	clean_memmory(t_game *game);
int     close_button(t_game *game, int option);

/* UTILS */
void	free_char_array(char **str);
char	get_first_char(char *line);
int		first_char_pos(char *line);
int     key_event(int key, t_game *game);
int     game_update(t_game *wd);

/* UTILS 2 */
char	**ft_split_cub(const char *str);

/* CHECKER */
int		check_input_map(char *map_file, t_game *game);
int		check_map_name(char *map_file);
char	get_first_char(char *line);
int		read_dimension(int fd, t_map *map, char *map_file, int *map_row);
int		check_map(t_map *map);

/* CHECKER_AUX */
int		check_line_info(char *line, t_game *game);
int		check_paths(t_game *game);
void 	check_players(t_game *game);

/* AUXILIAR FUNCTIONS */
int		arg_counter(char **argv);

/* MAP STRUCTURE */
void	save_textures(char *line, t_game *game);
int		save_rgb(char *line, int *color_array);
void	save_map(char *line, t_game *game, int *map_row);

/* PRINT */
void	print_map(t_game    wd);

/* MOVES */
void    move_player(t_game *game);

/* RAY */
void	init_ray(t_game *game);
void	ft_raytracing(t_game *game);

/* RAY_AUX */
void	verLine(int x, t_game *game, int color);

#endif