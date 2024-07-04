/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:48:14 by ncastell          #+#    #+#             */
/*   Updated: 2024/07/04 16:42:45 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* ERROR TYPE*/
#define E_SYNTAX 2

#define SCR_W 1024
#define SCR_H 768

/* MAP PX TYPE */

typedef struct s_point
{
    int x;
    int y;
} 		t_point;

typedef struct	s_textures
{
	void	*wall;
}			t_textures;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
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
	double	stepX;
	double	stepY;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}			t_ray;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_ray		*ray_cast;
	t_textures	*texts;
	int			n_players;
	int			key;
	void		*mlx;
	void		*mlx_win;
	int			checker;
	int			end;
	// int			error;
}				t_game;