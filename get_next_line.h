/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:32:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/08 23:59:56 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 8
# include <unistd.h>
# include <stdlib.h>

int	get_next_line(int fd, char **line);
int	ft_ismatch(char*s, int c);
size_t	ft_strlen(const char *s);
char	*ft_getline(char *s);

#	endif