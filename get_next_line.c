/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/12 12:52:15 by apires-d         ###   ########.fr       */
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

void	ft_save_str(char *str, size_t size)
{
	char	*aux;
	size_t	i;
	size_t	len;

	i = 0;
	len = (ft_strlen(str) - size) + 1;
	aux = malloc(len);
	if (!aux)
		return (NULL);
	while (i < len)
		aux[i++] = str[size++];
	aux[i] = '\0';
	free(str);
	str = malloc(len);
	str = ft_strdup(aux);
}

void	ft_get_line(char *str, char *line)
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
		if (ft_strlen(str) <= BUFFER_SIZE) // \n no final batendo com o tamanho do buffer
			line = str;
		else // \n antes de chegar no tamanho do buffer, guardar o que vem depois
		{
			aux = malloc(i + 1);
			if (!aux)
				return (NULL);
			while (j < i)
				aux[j++] = str[i++];
			aux[j] = '\0';
			line = aux;
			ft_save_str(str, i);
		}
		printf("%s\n",line);
	}
	else
	{
		if (ft_strlen(str) <= BUFFER_SIZE)
			line = str;
		else
		{
			aux = malloc(i + 1);
			if (!aux)
				return (NULL);
			while (j < i)
				aux[j++] = str[i++];
			aux[j] = '\0';
			line = aux;
			ft_save_str(str, i);
		}
	}
	printf("%s\n",line);
}

void	ft_mount_line(char *str, char *buff)
{
	char	*aux;
	size_t	len;

	if (str != NULL || str == "")
	{
		len = ft_strlen(str) + ft_strlen(buff) + 1;
		aux = malloc(len);
		if (!aux)
			return (NULL);
		aux = ft_strncat(str, buff, len);
		free(str);
		str = malloc(len);
		if (!str)
			return (NULL);
		str = ft_strdup(aux);
		free(aux);
	}
	else
	{
		len = ft_strlen(buff + 1);
		str = malloc(len);
		if (!str)
			return (NULL);
		str = ft_strdup(buff);
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
