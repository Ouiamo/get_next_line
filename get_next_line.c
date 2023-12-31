/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 09:50:16 by oaoulad-          #+#    #+#             */
/*   Updated: 2023/12/31 23:54:40 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *str_big)
{
	char	*buff;
	ssize_t	n;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n = 1;
	while (!ft_strchr(str_big, '\n') && (n != 0))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(buff);
			free(str_big);
			return (NULL);
		}
		buff[n] = '\0';
		str_big = ft_strjoin(str_big, buff);
	}
	free(buff);
	return (str_big);
}

char	*my_line(char *str_big)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str_big[i])
		return (NULL);
	while (str_big[i] && str_big[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str_big[i] && str_big[i] != '\n')
	{
		line[i] = str_big[i];
		i++;
	}
	if (str_big[i] == '\n')
	{
		line[i] = str_big[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*my_rest(char *str_big)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (str_big[i] && str_big[i] != '\n')
		i++;
	if (!str_big[i])
	{
		free(str_big);
		return (NULL);
	}
	rest = malloc(ft_strlen(str_big) - i + 1);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (str_big[i])
		rest[j++] = str_big[i++];
	rest[j] = '\0';
	free(str_big);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*str_big;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_big = ft_read_file(fd, str_big);
	if (!str_big)
		return (NULL);
	line = my_line(str_big);
	str_big = my_rest(str_big);
	return (line);
}
