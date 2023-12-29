/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:39:18 by oaoulad-          #+#    #+#             */
/*   Updated: 2023/12/29 04:47:03 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// size_t	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
// char	*ft_strchr(char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (c == '\0')
// 		return ((char *)&s[i]);
// 	return (0);
// }

// char	*ft_strdup(char *s)
// {
// 	char	*cpy;
// 	int		i;

// 	i = 0;
// 	cpy = malloc(ft_strlen(s) + 1);
// 	if (!cpy)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		cpy[i] = s[i];
// 		i++;
// 	}
// 	cpy[i] = '\0';
// 	return (cpy);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 		return (ft_strdup(s2));
// 	if (!s2)
// 		return (ft_strdup(s1));
// 	i = 0;
// 	j = 0;
// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!str)
// 		return (NULL);
// 	while (s1[i])
// 		str[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		str[j++] = s2[i++];
// 	str[j] = '\0';
// 	return (str);
// }

#include "get_next_line.h"
/**
 * returns the length of string s without null terminator
 */
size_t ft_strlen(char *s)
{
size_t i;

i = 0;
if (!s)
return (0);
while (s[i] != '\0')
i++;
return (i);
}

char *ft_strchr(char *s, int c)
{
int i;

i = 0;
if (!s)
return (0);
if (c == '\0')
return ((char *)&s[ft_strlen(s)]);
while (s[i] != '\0')
{
if (s[i] == (char) c)
return ((char *)&s[i]);
i++;
}
return (0);
}
/**
 * concatanates two strings s1 and s2
 */

char *ft_strjoin(char *s1, char *s2)
{
size_t i;
size_t j;
char *str;

if (!s1)
{
s1 = (char *)malloc(1 * sizeof(char));
s1[0] = '\0';
}
if (!s1 || !s2)
return (NULL);
str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
if (str == NULL)
return (NULL);
i = -1;
j = 0;
if (s1)
while (s1[++i] != '\0')
str[i] = s1[i];
while (s2[j] != '\0')
str[i++] = s2[j++];
str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
free(s1);
return (str);
}