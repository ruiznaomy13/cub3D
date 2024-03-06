/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:48:14 by ncastell          #+#    #+#             */
/*   Updated: 2024/03/06 19:12:02 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAGENTA	"\033[95m"
#define GREEN	"\x1b[32m"
#define WHITE	"\e[1;37m"

#define SQSZ	20

#define WALL	1
#define SPACE	0
#define PLAYER	2
#define P_N		21
#define P_S		22
#define P_E		23
#define P_W		24
#define	OUT_MAP	-1

/* ERROR TYPE*/
#define E_SYNTAX 2

#define SCR_W 1024
#define SCR_H 768

/* MAP PX TYPE */

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
	char	**map_guide;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		ceiling_c[3];
	int		floor_c[3];
	int		cols;
	int		rows;
	char	*line;
}			t_map;

typedef struct s_ray
{
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}			t_ray;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_ray		*ray_cast;
	t_textures	*texts;
	void		*mlx;
	void		*mlx_win;
	int			checker;
	int			end;
	// int			error;
}				t_game;