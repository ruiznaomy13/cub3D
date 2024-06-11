/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:48:14 by ncastell          #+#    #+#             */
/*   Updated: 2024/06/11 14:00:27 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCTURES_H
# define	STRUCTURES_H

#include "../inc/mlx42/include/MLX42/MLX42.h"

#define MAGENTA	"\033[95m"
#define GREEN	"\x1b[32m"
#define WHITE	"\e[1;37m"

#define SQSZ	20

# define MAGENTA	"\033[95m"
# define GREEN		"\x1b[32m"
# define WHITE		"\e[1;37m"

#define WALL	1
#define SPACE	0
#define PLAYER	2
#define P_N		21
#define P_S		22
#define P_E		23
#define P_W		24
#define	OUT_MAP	-1
#define RIGHT 124
#define RIGHT_D 2
#define LEFT 123
#define LEFT_A 0
#define DOWN 125
#define DOWN_S 1
#define UP 126
#define UP_W 13
#define NUM_TXT 2

/* ERROR TYPE*/
#define E_SYNTAX 2

#define SCR_W 1280
#define SCR_H 720
#define TEX_W 64
#define TEX_H 64

/* MAP PX TYPE */

typedef struct s_point
{
    int x;
    int y;
} 		t_point;

typedef struct	s_textures
{
	void			*wall;
	void			*player;
	void			*walle;
	mlx_image_t		*texture_data;
	unsigned int	floor;
	unsigned int	ceiling;
	int				bpp;
	int				size_line;
	int				endian;
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
	double	rayDirX;
	double	rayDirY;
	double	dirX;
	double	dirY;
	double	cameraX;
	double	planeX;
	double	planeY;
	int		boxMapX;
	int		boxMapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	moveSpeed;
	double	rotSpeed;
}			t_ray;

typedef struct s_game
{
	t_map			*map;
	t_player		*player;
	t_ray			*ray_cast;
	t_textures		*texts;
	int				n_players;
	int				key;
	mlx_t			*mlx;
	mlx_image_t		*mlx_win;
	int				checker;
	int				end;
	unsigned int	**buffer;
	int				moves;
	// int			error;
}				t_game;

#endif