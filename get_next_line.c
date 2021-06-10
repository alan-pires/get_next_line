/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/10 16:42:52 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 15

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

 size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = malloc(ft_strlen(s1));
	if (copy == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_get_line(char *buff, int size)
{
	int		i;
	char	*aux;

	i = 0;
	aux = malloc(size + 1);
	if (!aux)
		return(NULL);
	while (i < size)
	{
		aux[i] = buff[i];
		i++;
	}
	aux[i] = '\0';
	free(buff);
	buff = malloc(ft_strlen(aux));
	if (!buff)
		return(NULL);
	buff = ft_strdup(aux);
	return (buff);
}

int	ft_read_line(int fd, char *str, char *buff, char **line)
{
	int		read_b;
	size_t	i;

	i = -1;
	read_b = read(fd, buff, BUFFER_SIZE);
	if (read_b < 0)
		return (-1);
	while (buff[++i])
	{
		if (buff[i] == '\n')
		{
			buff = ft_get_line(buff, i);
			break ;
		}
	}
	*line = buff;
	str = ft_strncat(str, buff, BUFFER_SIZE);
	return (read_b);
}

int	get_next_line(int fd, char **line)
{
	int			result;
	static char	*str;
	char		*buff;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	str = NULL;
	result = 0;
	buff = malloc(BUFFER_SIZE);
	str = malloc(BUFFER_SIZE);
	if (!buff || !str)
		return (-1);
	while (result == 0)
	{
		result = ft_read_line(fd, str, buff, line);
	}
	printf("%s\n", *line);
	printf("após strncat: %s\n", str);
	return (0);
}
