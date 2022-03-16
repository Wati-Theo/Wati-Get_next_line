/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:11:23 by tschlege          #+#    #+#             */
/*   Updated: 2022/03/16 11:34:24 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*reducteur(char *res, char *buf)
{
	int		loc;
	char	*tmp;

	loc = where_are_you(buf);
	tmp = sp_ft_strndup(buf, loc);
	res = ft_strjoin(res, tmp);
	if (tmp)
		free(tmp);
	if (buf[loc + 1])
	{
		buf[loc] = 0;
		get_back(buf);
		return (res);
	}
	ft_memset(buf, 0, ft_strlen(buf));
	return (res);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				r;
	char			*res;

	res = NULL;
	if (!buf[0])
		r = read(fd, buf, BUFFER_SIZE);
	else
		r = 1;
	while (r > 0)
	{
		if (where_are_you(buf) > -1)
			return (reducteur(res, buf));
		else
		{
			res = ft_strjoin(res, buf);
			r = read(fd, buf, BUFFER_SIZE);
			buf[r] = 0;
		}
	}
	return (res);
}
