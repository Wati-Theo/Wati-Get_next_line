/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wati-Theo <wati-theo@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:11:23 by tschlege          #+#    #+#             */
/*   Updated: 2022/03/09 23:02:29 by Wati-Theo        ###   ########lyon.fr   */
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
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*sp_ft_strndup(char *str, int size)
{
	char	*cpy;
	int		i;

	cpy = malloc((size + 1) * sizeof(char) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\n';
	cpy[i + 1] = 0;
	return (cpy);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*copy;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1) );
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

char	*sp_ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*copy;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1) );
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\n';
	copy[i + 1] = '\0';
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

void get_zeroed(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		buf[i] = 0;
		i++;
	}
}

void	get_back(char *buf)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (buf[i])
		i++;
	i++;
	while (buf[i])
	{
		buf[j] = buf[i];
		i++;
		j++;
	}
	buf[j] = 0;
	
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*the_nouvelle;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
		return (ft_calloc(1, sizeof(char)));
	if ((s_len - start) > len)
		the_nouvelle = ft_calloc((len + 1), sizeof(char));
	else
	{
		the_nouvelle = ft_calloc((s_len - start + 1), sizeof(char));
		len = s_len - start + 1;
	}
	if (!the_nouvelle)
		return (NULL);
	while (s[start + i] && i < len)
	{
		the_nouvelle[i] = s[start + i];
		i++;
	}
	return (the_nouvelle);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				r;
	int				loc;
	char			*res;

	if (BUFFER_SIZE < 1 || fd < 0) // cas erreur
		return (NULL);
	while(where_are_you(buf) == -1) // tant qu'il n'y a pas de '\n'
	{
		r = read(fd, buf, BUFFER_SIZE); // lecture de fd
		if (r == 0)
		{
			res = ft_strdup(buf);
			return(res);
		}
		if (r < 0)
			return (NULL);
		buf[r] = 0;
	}
	// \n trouvé !
	loc = where_are_you(buf);
	res = sp_ft_strndup(buf, loc); // securisation de ce que je vais renvoyer
	if (buf[loc + 1]) // si il y a quelques chose apres le '\n'
	{
		buf[loc] = 0; // '\0' a lemplacement de l'ancien de '\n'
		get_back(buf);
		return(res);
	}
	get_zeroed(buf);
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
