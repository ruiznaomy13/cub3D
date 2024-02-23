/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:42 by eliagarc          #+#    #+#             */
/*   Updated: 2024/02/23 20:45:40 by ncastell         ###   ########.fr       */
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
void	ft_error(t_game *game, int error);

/* MAIN */
int		ft_error(int error);

/* CHECKER */
int		check_input_map(char *map_file, t_game *game);
int		check_map_name(char *map_file);

#endif