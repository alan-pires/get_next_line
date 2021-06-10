/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/10 15:46:39 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/*
char	*ft_realloc_str(char *str)
{
	char	*aux;

	aux = ft_str_alloc(ft_strlen(str));
	if (!aux)
		return(NULL);
	aux = ft_strdup(str);
	free(str);
	str = ft_str_alloc(BUFFER_SIZE + ft_strlen(aux));
	if (!str)
		return (NULL);
	str = ft_strdup(aux);
	return (str);	
}

void	ft_save_str(size_t pos, char *str)
{
	size_t	i;

	i = 0;
	while (pos < ft_strlen(str))
	{
		str[i] = str[pos + 1];
		i++;
		pos++;
	}
	str[i] = '\0';
}
*/


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
	copy = ft_str_alloc(ft_strlen(s1));
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

int		ft_get_line(char *buff, int size)
{
	int		i;
	char	*aux;

	i = 0;
	aux = malloc(size + 1);
	if (!aux)
		return(-1);
	while (i < size)
	{
		aux[i] = buff[i];
		i++;
	}
	aux[i] = '\0';
	free(buff);
	buff = malloc(ft_strlen(aux));
	if (!buff)
		return(-1);
	buff = ft_strdup(aux);
	return (1);
}

int	ft_endofline(char *buff)
{
	size_t	i;
	size_t	j;
	char	*aux;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			ft_get_line(buff, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_start(int fd, char *str, char *buff)
{
	int read_b;

	read_b = 0;
	while (!ft_endofline(buff))
		read_b = read(fd, buff, BUFFER_SIZE);
	if (read_b < 0)
		return (-1);
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
		result = ft_start(fd, str, buff);
		printf("%s\n",buff);
	}
	*line = buff;
	printf("%s\n %d\n", *line, result);
	return (0);
}
