/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/02/28 18:17:01 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structures.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

int		main(int ac, char *av[]);

/* MAIN */
void	ft_error(t_game *game, int error);

/* UTILS */
void	free_char_array(char **str);
char	get_first_char(char *line);
int		first_char_pos(char *line);

/* CHECKER */
int		check_input_map(char *map_file, t_game *game);
int		check_map_name(char *map_file);
char	get_first_char(char *line);
int		read_dimension(int fd, t_map *map, char *map_file);

/* CHECKER_AUX */
int		check_line_info(char *line, t_game *game);
int		check_paths(t_game *game);

/* AUXILIAR FUNCTIONS */
int		arg_counter(char **argv);

/* MAP STRUCTURE */
void	save_textures(char *line, t_game *game);
int		save_rgb(char *line, int *color_array);

#endif