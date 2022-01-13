/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:11:23 by tschlege          #+#    #+#             */
/*   Updated: 2022/01/12 17:19:44 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	void	*retturn;

	retturn = b;
	while (len)
	{
		len--;
		*((unsigned char *)b + len) = (unsigned char)c;
	}
	return (retturn);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*retturn;

	retturn = malloc(count * size);
	if (!retturn)
		return (NULL);
	return (ft_memset(retturn, '\0', count * size));
}

size_t	ft_strlen(const	char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	get_back(char *buf, char *cpy)
{
	int	i;
	
	i = 0;
	while (cpy[i])
	{
		buf[i] = cpy[i];
		i++;
	}
	free (cpy);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*res;
	char		*tmp;
	int			check;

	buf[BUFFER_SIZE] = 0;
	if (!(*buf) && read(fd, buf, BUFFER_SIZE) <= 0) // read seulement au premier appel de read
		return (NULL);
	if (where_are_you(buf) >= 0) // si '/n' dans buf[BUFFER_SIZE]
		return (ft_strndup(buf, where_are_you(buf)));
	else // si pas de '\n'
	{
		res = ft_strdup(buf);
		while (where_are_you(buf) == -1)
		{
			if (read(fd, buf, BUFFER_SIZE) <= 0) // si read < 1
				return (NULL);
			if (where_are_you(buf) == -1) // check si dans le nouveau code on a \n
			{
				tmp = res;
				res = ft_strjoin(res, buf);
				free(tmp);
			}
		}
		tmp = res;
		check = where_are_you(buf);
		buf[where_are_you(buf)] = 0; // remplace le \n  par un \0
		res = ft_strjoin(res, buf);
		free(tmp);
		if (buf[check + 1])
			get_back(buf, ft_strdup(buf + check + 1));
		return (res);
	}
}

int	main(void)
{
	int	fd;
	char	*get_free;
	
	fd = open("mamamia", O_RDONLY);
	get_free = get_next_line(fd);
	printf("$%s$\n", get_free);
	free(get_free);
	get_free = get_next_line(fd);
	printf("$%s$\n", get_free);
	free(get_free);
	get_free = get_next_line(fd);
	printf("$%s$\n", get_free);
	free(get_free);
}
