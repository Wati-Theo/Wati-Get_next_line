/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:11:23 by tschlege          #+#    #+#             */
/*   Updated: 2022/03/15 11:25:57 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*raciste(char *res, char *buf)
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
	get_zeroed(buf);
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
			return (raciste(res, buf));
		else
		{
			res = ft_strjoin(res, buf);
			r = read(fd, buf, BUFFER_SIZE);
			buf[r] = 0;
		}
	}
	return (res);
}
