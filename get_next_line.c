/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/13 17:11:48 by apires-d         ###   ########.fr       */
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

static void	ft_free(char **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	p = (char *)malloc((len + 1) * sizeof(*p));
	if (p == NULL)
		return (NULL);
	while (*s1)
	{
		p[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		p[i] = *s2;
		i++;
		s2++;
	}
	p[i] = '\0';
	return (p);
}


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

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *s1)
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

/*
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
*/

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
		r_bytes = ft_strlen(buff);
		buff[r_bytes] = '\0';
		aux = ft_strjoin(content[fd], buff);
		ft_free(&content[fd]);
	}
	return ();
}
