#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strchr(char *str, int c)
{
	size_t i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char c) == '\0')
		return (&str[i]);
	return (NULL);
}

char *ft_strjoin(char s1, char s2)
{
	size_t	i;
	size_t	j;
	char *total;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	total = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!total)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while(s1[i])
			total[j++] = s1[i++];
	i = 0;
	while (s2[i])
		total[j++] = s2[i++];
	total[j] = '\0';
	free(s1)
	return (total);
}
