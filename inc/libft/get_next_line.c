/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:40:16 by ncastell          #+#    #+#             */
/*   Updated: 2024/02/11 20:08:31 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_gnl(char **str)
{
	free (*str);
	*str = NULL;
	return (NULL);
}

char	*read_buff(int fd, char *buff)
{
	char	*buffer;
	int		reader;

	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (ft_free_gnl(&buff));
	buffer[0] = '\0';
	reader = 1;
	while (!ft_strchr(buffer, '\n') && reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (ft_free_gnl(&buff));
		}
		if (reader > 0)
		{
			buffer[reader] = '\0';
			buff = ft_strjoin_gnl(buff, buffer);
		}
	}
	free(buffer);
	return (buff);
}

char	*save_reminder(char *buff)
{
	int		i;
	int		j;
	char	*reminder;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!buff[i])
		return (ft_free_gnl(&buff));
	reminder = (char *)malloc((ft_strlen(buff) - i + 1) * sizeof(char));
	if (!reminder)
		return (ft_free_gnl(&buff));
	while (buff[++i] != '\0')
		reminder[j++] = buff[i];
	if (j > 0)
		reminder[j] = '\0';
	else
	{
		free(reminder);
		return (ft_free_gnl(&buff));
	}
	ft_free_gnl(&buff);
	return (reminder);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_buff(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_strcpyc(buff, '\n');
	if (!line)
		return (ft_free_gnl(&buff));
	buff = save_reminder(buff);
	return (line);
}