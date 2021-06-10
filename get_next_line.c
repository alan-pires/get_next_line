/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/10 09:06:59 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

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

int		ft_get_line(char *str, int read_b, char **line)
{
	char	*aux;
	size_t	i;

	i = 0;
	aux = ft_str_alloc(ft_strlen(str));
	if (!aux)
		return (0);
	if (ft_strlen(str) || read_b != 0)
	{
		if (str[0] ==  '\n')
			aux[0] = '\0';
		else
		{
			while (str[i] && str[i] != '\n')
			{
				aux[i] = str[i];
				i++;
			}
			aux[i] = '\0';
		}
		*line = aux;
		ft_save_str(i, str);
		free(aux);
		return (1);
	}
	return (0);
}

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
	free(aux);
	return (str);	
}

int	ft_endofline(char*s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			read_b;
	static char	*str;
	char		*buff;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	str = NULL;
	buff = ft_str_alloc(BUFFER_SIZE);
	str = ft_str_alloc(BUFFER_SIZE);
	if (!buff || !str)
		return (-1);
	while ((read_b = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		str = ft_realloc_str(str);
		str = ft_strjoin(str, buff);
		if (ft_endofline(buff))
			break ;
	}
	free(buff);
	if (ft_get_line(str, read_b, line))
		return (1);
	return (0);
}
