/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:11:23 by tschlege          #+#    #+#             */
/*   Updated: 2022/01/06 17:11:30 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	where_are_you(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *str, int size)
{
	char	*cpy;
	int		i;

	cpy = malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*copy;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	stotal_len;
	char	*the_nouvelle;
	int		i;
	int		j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	stotal_len = ft_strlen(s1) + ft_strlen(s2);
	the_nouvelle = ft_calloc(stotal_len + 1, sizeof(char));
	if (!the_nouvelle)
		return (NULL);
	while (s1[i])
		the_nouvelle[j++] = s1[i++];
	i = 0;
	while (s2[i])
		the_nouvelle[j++] = s2[i++];
	the_nouvelle[j] = '\0';
	return (the_nouvelle);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*first;
	int			offset;
	char		*res;

	
	first = NULL;
	offset = 0;
	if (read(fd, buf, BUFFER_SIZE) <= 0) // si read < 1
		return (NULL);
	if (where_are_you(buf)) // si '/n' dans buf[BUFFER_SIZE]
		return (ft_strndup(buf, where_are_you(buf)));
	else // si pas de '\n'
	{
		first = ft_strdup(buf);
		while (where_are_you(buf) == -1)
		{
			if (read(fd, buf, BUFFER_SIZE) <= 0) // si read < 1
				return (NULL);
			if (!offset)
				res = ft_strjoin(first, buf);
			else
				res = ft_strjoin(res, buf);
			offset++;
		}
		
	}
		
}

int	main(void)
{
	int	fd;

	fd = open("mamamia", O_RDONLY);
	printf("$%s$\n", get_next_line(fd));
}
