/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/14 13:05:03 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}

static int	ft_get_line(char **line, int r_bytes, char **content)
{
	size_t	i;
	char	*aux;

	i = 0;
	if (r_bytes < 0)
		return (-1);
	else if (*content[0] == '\0' && r_bytes == 0)
	{
		*line = ft_strdup("");
		ft_free(content);
		return (0);
	}
	while ((*content)[i] != '\0' && (*content)[i] != '\n')
		i++;
	*line = ft_substr(*content, 0, i);
	if ((*content)[i] == '\n')
	{
		aux = ft_strdup(*content + i + 1);
		free(*content);
		*content = aux;
		return (1);
	}
	ft_free(content);
	return (0);
}
/*
static int	ft_initialize(int fd, char **line, char **buff, char **content)
{
	printf("chegou aqui 0");
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (0);
	//printf("content[fd]: %s\n", *content);
	printf("chegou aqui 1");
	if (!content[fd])
	{
		content[fd] = ft_strdup("");
		if (!content[fd])
			return (0);
	}
	printf("chegou aqui 2");
	buff = malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (0);
	printf("chegou aqui 3");
	return (1);
}
*/
int		get_next_line(int fd, char **line)
{
	ssize_t		r_bytes;
	int			ret;
	char		*buff;
	char		*aux;
	static char	*content[1024];

	buff = NULL;
	// if (ft_initialize(fd, line, &buff, &content[fd]) == 0)
	// 	return (-1);
	
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(content[fd]))
	{
		content[fd] = ft_strdup("teste");
		if (!(content[fd]))
			return (-1);
	}
	printf("*content[fd]: %d\n",*content[fd]);
	printf("content[fd]: %s\n", content[fd]);
	printf("&content[fd]: %s\n", *&content[fd]);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (-1);
	
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		r_bytes = ft_strlen(buff);
		buff[r_bytes] = '\0';
		aux = ft_strjoin(content[fd], buff);
		ft_free(&content[fd]);
		content[fd] = aux;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	ret = ft_get_line(line, r_bytes, &(content[fd]));
	return (ret);
}
