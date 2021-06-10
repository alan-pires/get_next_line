/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:32:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/10 11:46:27 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 8

int		get_next_line(int fd, char **line);
int		ft_endofline(char*s);
size_t	ft_strlen(const char *s);
char	*ft_getline(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_str_alloc(size_t size);
char	*ft_strdup(const char *s1);
int		ft_get_line(char *str, int read_b, char **line);
void	ft_save_str(size_t pos, char *str);

#	endif