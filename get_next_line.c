/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/13 16:33:09 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 9
# endif

char	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*p;

	i = 0;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (i < (count * size))
	{
		*p = '\0';
		p++;
		i++;
	}
	return (p);
}

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
	if (!s1)
		return (NULL);
	copy = malloc((ft_strlen(s1) + 1) * sizeof(*copy));
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

int	ft_save_str(char *str, size_t size)
{
	char	*aux;
	size_t	i;
	size_t	len;

	i = 0;
	len = (ft_strlen(str) - size) + 1;
	aux = malloc(len);
	if (!aux)
		return (0);
	while (i < len)
		aux[i++] = str[size++];
	aux[i] = '\0';
	free(str);
	str = malloc(len);
	str = ft_strdup(aux);
	return (1);
}

int	ft_get_line(char *str, char **line)
{
	size_t	i;
	size_t	j;
	char	*aux;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n' && i < BUFFER_SIZE)
		i++;
	if (str[i] == '\n')
	{
		if (ft_strlen(str) <= BUFFER_SIZE)
		{
			*line = str;
			//printf("%s\n", aux);
		}
		else
		{
			aux = malloc(i + 1);
			if (!aux)
				return (0);
			while (j < i)
				aux[j++] = str[i++];
			aux[j] = '\0';
			*line = aux;
			//printf("%s\n", aux);
			ft_save_str(str, i);
		}
	}
	else
	{
		if (ft_strlen(str) <= BUFFER_SIZE)
		{
			*line = str;
			//printf("%s\n", aux);
		}
		else
		{
			aux = malloc(i + 1);
			if (!aux)
				return (0);
			while (j < i)
				aux[j++] = str[i++];
			aux[j] = '\0';
			*line = aux;
			//printf("%s\n",*line);
			ft_save_str(str, i);
		}
	}
	return (1);
}

int	ft_mount_line(char *str, char *buff)
{
	char	*aux;
	size_t	len;

	if (str != NULL && str != "")
	{
		len = ft_strlen(str) + ft_strlen(buff) + 1;
		aux = malloc(len);
		if (!aux)
			return (0);
		//printf("%s\n", buff);
		aux = ft_strncat(str, buff, len);
		
		free(str);
		str = malloc(len);
		if (!str)
			return (0);
		str = ft_strdup(aux);
		free(aux);
	}
	else
	{
		len = ft_strlen(buff + 1);
		str = malloc(len);
		if (!str)
			return (0);
		str = ft_strdup(buff);
	}
	return (1);
}

ssize_t	ft_read_line(int fd, char *str, char *buff, char **line)
{
	ssize_t		read_b;

	read_b = read(fd, buff, BUFFER_SIZE);
	printf("%s\n",buff);
	// verificar se str esta vazio, se tiver otimo, se nao tiver, concatenar com buff
	ft_mount_line(str, buff);
	// ver se tem \n na linha concatenada, se tiver pegar parte que vai ate antes disso
	//ft_get_line(str, line);
	if (read_b < 0)
		return (-1);
	return (read_b);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		r_bytes;
	char		*buff;
	char		*aux;
	static char	*content[1024];

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!content[fd])
	{
		content[fd] = ft_strdup("");
		if (!content[fd])
			return (-1);
	}
	buff = malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (-1);
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{

	}
	return ();
}
