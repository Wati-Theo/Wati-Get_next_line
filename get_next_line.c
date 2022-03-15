/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:11:23 by tschlege          #+#    #+#             */
/*   Updated: 2022/03/15 11:04:39 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*char	*raciste(int *loc, char *res, char *tmp, char *buf)
{
	loc = where_are_you(buf);
	tmp = sp_ft_strndup(buf, loc);
	res = ft_strjoin(res, tmp);
	if (tmp)
		free(tmp);
	if (buf[loc + 1]) // si il y a quelques chose apres le '\n'
	{
		buf[loc] = 0; // '\0' a lemplacement de l'ancien de '\n'
		get_back(buf);
		return (res);
	}
	get_zeroed(buf);
	return (res);
}*/

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				r;
	int				loc;
	char			*res;
	char			*tmp;

	res = NULL;
	if (!buf[0])
		r = read(fd, buf, BUFFER_SIZE);
	else
		r = 1;
	while (r > 0)
	{
		if (where_are_you(buf) > -1) //  si \n dans buf
		{
			loc = where_are_you(buf);
			tmp = sp_ft_strndup(buf, loc);
			res = ft_strjoin(res, tmp);
			if (tmp)
				free(tmp);
			if (buf[loc + 1]) // si il y a quelques chose apres le '\n'
			{
				buf[loc] = 0; // '\0' a lemplacement de l'ancien de '\n'
				get_back(buf);
				return (res);
			}
			get_zeroed(buf);
			return (res);
		}
		else
		{
			res = ft_strjoin(res, buf); // strjoin le texte lu
			r = read(fd, buf, BUFFER_SIZE);
			buf[r] = 0;
		}
	}
	return (res);
}

