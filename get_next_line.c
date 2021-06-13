/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/13 19:26:41 by apires-d         ###   ########.fr       */
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

int	ft_initialize(int *fd, char **line, char *buff, char *content[])
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
	ret = get_line(line, r_bytes, &(content[fd]));
	return (ret);
}

