/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/07/06 16:38:34 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structures.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include "../inc/mlx42/include/MLX42/MLX42.h"
# include "libft.h"
# include "ft_printf.h"

int		main(int ac, char *av[]);

/* MAIN */
void	ft_error(t_game *game, int error);
void	init_textures(t_game *game);
int     init_game(char *map_file, t_game *game);

/* FT_FREE_GAME */
void	clean_memmory(t_game *game);
void    close_button(void *wd);

/* UTILS */
void	free_char_array(char **str);
char	get_first_char(char *line);
int		first_char_pos(char *line);
void    key_event(mlx_key_data_t key, void *game);
void    game_update(void *wd);

/* UTILS 2 */
char	**ft_split_cub(const char *str);

/* CHECKER */
void	check_input_map(char *map_file, t_game *game);
int		check_map_name(char *map_file);
char	get_first_char(char *line);
int     read_dimension(int fd, t_game *game, char *map_file);
int		check_map(t_map *map);

/* CHECKER_AUX */
int		check_line_info(char *line, t_game *game);
int		check_paths(t_game *game);
void 	check_players(t_game *game);
int		is_valid_path(char *line, char ***aux);

/* AUXILIAR FUNCTIONS */
int		arg_counter(char **argv);

/* MAP STRUCTURE */
void	save_textures(char *line, t_game *game);
int		save_rgb(char *line, int *color_array);
void	save_map(char *line, t_game *game, int *map_row);

/* PRINT */
void	print_map(t_game    wd);
void    mlx_draw_texture(mlx_image_t *window_image, mlx_texture_t *texture, int dest_x, int dest_y);
void    print_border(t_game game, int x);
void    print_hand(t_game game);

/* MOVES */
void    move_player(t_game *game);

/* RAY */
void	init_ray(t_game *game);
void	ft_raytracing(t_game *game);

/* RAY_AUX */
void	verLine(int x, t_game *game, int color);
void	drawBuffer(t_game *game, uint32_t **buff);

/* TEXTURES */
void	render(t_game *game, int side, int i);
void    fill_color(mlx_image_t *img, uint32_t color);
int		check_textures(t_textures *txts);

#endif