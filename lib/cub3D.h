/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:48:14 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/23 20:03:29 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

# define CYAN	"\x1b[36m"

# define WALL	1
# define SPACE	0
# define PLAYER	2

# define E_SYNTAX 2

# define SCR_W 640
# define SCR_H 480

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		card_p;
}			t_player;

typedef struct s_map
{
	int		**map_guide;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		ceiling_c[3];
	int		floor_c[3];
	int		cols;
	int		rows;
}			t_map;


typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	int			checker;
}				t_game;

int		main(int ac, char *av[]);

/* CHECKER */
int		check_input_map(char *map_file, t_game *game);
int		check_map_name(char *map_file);
#endif