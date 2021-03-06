/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:09:44 by tschlege          #+#    #+#             */
/*   Updated: 2022/03/16 11:34:10 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // read
# include <stdlib.h> // malloc, free

char	*get_next_line(int fd);
int		where_are_you(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const	char *s);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	get_back(char *buf);
char	*sp_ft_strndup(char *str, int size);
char	*reducteur(char *res, char *buf);
char	*ft_strdup(const char *s1);

#endif
