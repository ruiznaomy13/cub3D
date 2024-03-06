/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:58:03 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/29 16:08:54 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_countwords(char const *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == '\t' || s[i] == ' '))
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != '\t' && s[i] != ' ')
			i++;
	}
	return (count);
}

static int	ft_wlen(char const *s, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != '\t' && s[i] != ' ')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free(char **str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		free(str[a]);
		a++;
	}
	free(str);
	return (NULL);
}

char	**ft_split_cub(char const *s)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (ft_countwords(s) + 1));
	if (!str)
		return (NULL);
	while (j < ft_countwords(s))
	{
		while (s[i] == '\t' || s[i] == ' ')
			i++;
		str[j] = (ft_substr(s, i, ft_wlen(s, i)));
		if (!str[j])
			return (ft_free(str));
		i += ft_wlen(s, i);
		j++;
	}
	str[j] = 0;
	return (str);
}