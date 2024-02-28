/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliarFunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:51:49 by eliagarc          #+#    #+#             */
/*   Updated: 2024/02/28 18:31:37 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/cub3D.h"

int	arg_counter(char **argv)
{
	int	i;

	i = 0;
	if (!argv[0])
		return (0);
	while (argv[i])
		i++;
	return (i);
}