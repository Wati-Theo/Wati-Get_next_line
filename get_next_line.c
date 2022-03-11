/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wati-Theo <wati-theo@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:11:23 by tschlege          #+#    #+#             */
/*   Updated: 2022/03/11 16:51:24 by Wati-Theo        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>


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
			res = ft_strjoin(res, sp_ft_strndup(buf, loc));
			if (buf[loc + 1]) // si il y a quelques chose apres le '\n'
			{
				buf[loc] = 0; // '\0' a lemplacement de l'ancien de '\n'
				get_back(buf);
				return(res);
			}
			get_zeroed(buf);
			return (res);
		}
		else
		{
			tmp = res;
			res = ft_strjoin(res, buf); // strjoin le texte lu
			free(tmp);
			r = read(fd, buf, BUFFER_SIZE);
			buf[r] = 0;
		}
	}
	return (res);
}

int	main(void)
{
	int		fd;
	char	*get_free;
	
	fd = open("mamamia", O_RDONLY);
	get_free = get_next_line(fd);
	printf("res = $%s$\n", get_free);
	free(get_free);
	get_free = get_next_line(fd);
	printf("res = $%s$\n", get_free);
	free(get_free);
	get_free = get_next_line(fd);
	printf("res = $%s$\n", get_free);
	free(get_free);

	// char	buf[10];

	// buf[0] = 'W';	
	// buf[1] = 'a';
	// buf[2] = 't';
	// buf[3] = 'i';
	// buf[4] = '\n';
	// buf[5] = 'T';
	// buf[6] = 'h';
	// buf[7] = 'e';
	// buf[8] = 'o';
	// buf[9] = 0;

	//printf("%s\n", buf);
	// get_back(buf);
	// printf("%s\n", buf);

	// char	*reste;
	
	// reste = ft_strdup(buf + 4);
	// printf("$%s$\n", reste);
}
