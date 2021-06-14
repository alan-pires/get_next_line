/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/14 08:53:16 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		i = 1;
	else if (start + len > ft_strlen(s))
		i = ft_strlen(s) - start + 1;
	else
		i = len + 1;
	substr = (char *)malloc((i + 1) *sizeof(char));
	if (substr == NULL)
		return (NULL);
	if (i > 1)
	{
		i = 0;
		while (i < len && s[start + i] != '\0')
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	substr[i] = '\0';
	return (substr);
}

static int	ft_initialize(int *fd, char **line, char *buff, char *content[])
{
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!content[*fd])
	{
		content[*fd] = ft_strdup("");
		if (!content[*fd])
			return (-1);
	}
	buff = malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (-1);
	return (0);
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
	if ((*content)[i] == "\n")
	{
		aux = ft_strdup(*content + i + 1);
		free(*content);
		*content = aux;
		return (1);
	}
	ft_free(content);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		r_bytes;
	int			ret;
	char		*buff;
	char		*aux;
	static char	*content[1024];

	if (ft_initialize(&fd, &line, buff, &(content[fd])) != 0);
		return (-1);
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		r_bytes = ft_strlen(buff);
		buff[r_bytes] = '\0';
		aux = ft_strjoin(content[fd], buff);
		ft_free(&content[fd]);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	ret = ft_get_line(line, r_bytes, &(content[fd]));
	return (ret);
}

