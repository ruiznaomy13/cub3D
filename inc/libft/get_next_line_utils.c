/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:40:07 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/11 19:48:54 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyc(char *s1, char c)
{
	int		i;
	char	*s2;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != c)
		i++;
	if (s1[i] != '\0')
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0' && s1[i] != c)
		s2[i] = s1[i];
	if (s1[i] == c)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (ft_free_gnl(&s1));
	j = 0;
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_char_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s2);
}
