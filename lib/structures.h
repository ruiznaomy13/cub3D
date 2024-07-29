/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:48:14 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/29 13:25:39 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "../inc/mlx42/include/MLX42/MLX42.h"

# define MAGENTA	"\033[95m"
# define GREEN		"\x1b[32m"
# define WHITE		"\e[1;37m"

# define SQSZ		20
# define MPSZ		5

# define MAGENTA	"\033[95m"
# define GREEN		"\x1b[32m"
# define WHITE		"\e[1;37m"

# define WALL		1
# define SPACE		0
# define PLAYER		2
# define P_N		21
# define P_S		22
# define P_E		23
# define P_W		24
# define OUT_MAP	-1
# define RIGHT		262
# define RIGHT_D	68
# define LEFT		263
# define LEFT_A		65
# define DOWN		264
# define DOWN_S		83
# define UP			265
# define UP_W		87
# define NUM_TXT	2

/* ERROR TYPE*/
# define E_SYNTAX 2

# define MAX_W		3200
# define MAX_H		1800
# define MIN_W		800
# define MIN_H		600

# define SCR_W		1920
# define SCR_H		1080
# define TEX_W		64
# define TEX_H		64

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_render
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		step;
	uint32_t	color;
}				t_render;

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*walln;
	mlx_texture_t	*walls;
	mlx_texture_t	*wallw;
	mlx_texture_t	*walle;
	mlx_texture_t	*black;
	mlx_texture_t	*hand;
	mlx_image_t		*texture_n;
	mlx_image_t		*texture_s;
	mlx_image_t		*texture_e;
	mlx_image_t		*texture_w;
	mlx_image_t		*txt_black;
	mlx_image_t		*txt_hand;
	uint32_t		floor;
	uint32_t		ceiling;
}				t_textures;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int		card_p;
}			t_player;

typedef struct s_map
{
	int		**map_array;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		ceiling_c[3];
	int		floor_c[3];
	int		rows;
	int		cols;
	char	*line;
}			t_map;

typedef struct s_ray
{
	double	r_dirx;
	double	r_diry;
	double	dir_x;
	double	dir_y;
	double	camera_x;
	double	plane_x;
	double	plane_y;
	int		boxmap_x;
	int		boxmap_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	walldist;
	int		step_x;
	int		step_y;
	int		line_h;
	int		draw_start;
	int		draw_end;
	double	mv_speed;
	double	rot_speed;
}			t_ray;

typedef struct s_game
{
	t_map			*map;
	t_player		*player;
	t_ray			*ray_cast;
	t_textures		*texts;
	t_render		*rd;
	int				n_players;
	int				key;
	mlx_t			*mlx;
	mlx_image_t		*mlx_win;
	int				checker;
	int				end;
	uint32_t		**buffer;
	int				moves;
	int				spr;
}				t_game;

#endif