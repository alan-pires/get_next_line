/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:32:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/10 19:39:59 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_get_line(char *buff, int size);
int	ft_endofline(int fd, char *buff);
int		ft_read_line(int fd, char *str, char *buff, char **line);
int		get_next_line(int fd, char **line);

#	endif