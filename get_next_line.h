/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:32:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/08 12:45:41 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1000
# include <unistd.h>
# include <stdlib.h>

int	get_next_line(int fd, char **line);
char	*ft_strchr(char*s, int c);
char	*ft_strtrim(char const *s1, char const *set);
//size_t	ft_strlen(const char *s);
//char	*ft_getline(char *str);
char	*ft_split(char const *s, char c);
size_t	ft_count_split(char const *s, char c);
char	*ft_strndup(const char *s, size_t n);

#	endif