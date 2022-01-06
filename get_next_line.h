/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:09:44 by tschlege          #+#    #+#             */
/*   Updated: 2022/01/06 17:28:07 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // read
# include <stdlib.h> // malloc, free
# include <fcntl.h> // open

char	*get_next_line(int fd);
int		where_are_you(char *str);
char	*ft_strndup(char *str, int size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const	char *s);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif
