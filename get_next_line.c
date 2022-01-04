/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wati-Theo <Wati-Theo@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:11:23 by tschlege          #+#    #+#             */
/*   Updated: 2022/01/04 22:28:08 by Wati-Theo        ###   ########lyon.fr   */
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

char	*get_next_line(int fd)
{
	
}

int	main(void)
{
	// printf("%d\n", where_are_you("oups\nerfzfezf"));
	// printf("$%s$\n", ft_strndup("oups\n", where_are_you("oups\nerfzfezf")));
	// printf("%d\n", where_are_you("oup\n"));
	// printf("$%s$\n", ft_strndup("oups\n", where_are_you("oup\n")));
	// printf("%d\n", where_are_you("ou\n"));
	// printf("$%s$\n", ft_strndup("oups\n", where_are_you("ou\n")));
	// printf("%d\n", where_are_you("oups"));
	// printf("%d\n", where_are_you(""));
}
