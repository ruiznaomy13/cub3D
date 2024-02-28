/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliarFunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:51:49 by eliagarc          #+#    #+#             */
/*   Updated: 2024/02/28 19:04:11 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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