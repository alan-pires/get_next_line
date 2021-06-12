/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/12 09:16:31 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 8

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

char	*ft_get_line(char *str, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n' && i < BUFFER_SIZE)
		i++;
	
}

void	ft_mount_line(char *str, char *buff)
{
	char	*aux;

	if (str != NULL || str == "")
	{
		aux = malloc(ft_strlen(str) + ft_strlen(buff) + 1);
		aux = ft_strncat(str, buff, ft_strlen(aux));
		free(str);
		str = malloc(ft_strlen(aux));
		str = ft_strdup(aux);
		free(aux);
	}
}

int	ft_read_line(int fd, char *str, char *buff, char **line)
{
	ssize_t		read_b;
	size_t	i;

	i = 0;

	read_b = read(fd, buff, BUFFER_SIZE);
	// verificar se str esta vazio, se tiver otimo, se nao tiver, concatenar com buff
	ft_mount_line(str, buff);
	// ver se tem \n na linha concatenada, se tiver pegar parte que vai ate antes disso
	ft_get_line(str, line);

	printf("%s\n",buff);
	if (read_b < 0)
		return (-1);
		
	//*line = buff;
	//str = ft_strncat(str, buff, BUFFER_SIZE);
	return (read_b);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		result;
	char		*buff;
	static char	*str;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	str = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	buff[BUFFER_SIZE] = '\0';
	if (!buff || !str)
		return (-1);
	result = ft_read_line(fd, str, buff, line);
	if (result < 0)
		return (-1);
	//if result = 0 return 0
	return (1);
}
