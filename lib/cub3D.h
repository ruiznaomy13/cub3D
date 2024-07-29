/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/07/29 13:27:29 by ncastell         ###   ########.fr       */
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

/* MAIN */
int			main(int ac, char *av[]);
void		ft_error(t_game *game, int error);
int			init_textures(t_textures **texts, t_map map, mlx_t *mlx);
int			init_game(char *map_file, t_game *game);

/* ---------------------------- CHECKER --------------------------------*/
void		check_input_map(char *map_file, t_game *game);
int			check_line_info(char *line, t_game *game);
int			check_map(t_map *map);
void		check_players(t_game *game);

// CHECKER_1
int			check_map_name(char *map_file);
int			check_paths(t_game *game);
int			is_valid_color(char *line, char ***arr);
int			read_dimension(int fd, t_game *game, char *map_file);
void		check_square(t_map *map, t_point iter, int *check);

// CHECKER2_2
int			check_resolution(void);
int			line_length(char *line);
int			skip_empty_line(char *str);
int			inside_map_item(int item);
int			is_valid_path(char *line, char ***aux);

/* -------------------------- MAP CONFIG ------------------------------*/
/* MAP STRUCTURE 1*/
void		save_map(char *line, t_game *game, int *map_row);
int			is_map_texture(char *line, int *i, int *aux);
int			is_valid_line(char *line);
void		save_player(t_game *game, int p_orientation, int *map_row, int *i);
void		save_in_array(t_game *game, char *line, int *i, int *map_row);

/* MAP STRUCTURE 2*/
int			save_rgb(char *line, int *color_array);
void		save_textures(char *line, t_game *game);

/* -------------------------- UTILITIES ------------------------------*/
/* UTILS */
void		free_charray(char **str);
char		get_first_char(char *line);
int			first_char_pos(char *line);
void		key_event(mlx_key_data_t key, void *game);
void		game_update(void *wd);

/* UTILS 2 */
char		**ft_split_cub(const char *str);
int			arg_counter(char **argv);

/* FT_FREE_GAME */
void		clean_memmory(t_game *game);
void		close_button(void *wd);

/* ------------------------- MOVEMENT FUNCTIONS -----------------------------*/
/* MOVES */
void		move_player(t_game *game);

/* -------------------------- DRAWING FUNCTIONS ------------------------------*/
/* PRINT */
void		print_map(mlx_image_t *win, t_player *player, t_map *map,
				t_textures *text);
void		mlx_draw_texture(mlx_image_t *window_image,
				mlx_texture_t *texture, int dest_x, int dest_y);
void		print_border(mlx_image_t *win, t_textures *text, int x);
void		print_hand(t_game *game);

/* TEXTURES */
void		init_render(t_game *game, t_render **rd, int side,
				mlx_image_t **textr);
void		render(t_game *game, int side, int i);
int			check_textures(t_textures *txts);
uint32_t	get_rgba(int r, int g, int b, int a);

/* -------------------------- RAY TRACING ------------------------------*/
/* RAY */
void		init_ray(t_game *game);
void		ft_raycasting(t_game *game, t_ray **ray_cast);

/* RAY_AUX */
void		draw_buffer(t_game *game, uint32_t **buff);
void		get_raycast(t_ray **rcast, int i, t_player *player);

#endif