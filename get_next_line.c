#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_str_alloc(size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(size + 1);
	if (memory == NULL)
		return (NULL);
	while (i < size + 1)
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
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
	while (read_b = read(fd, buff, BUFFER_SIZE) > 0)
	{
		str = ft_realloc_str(str);
		str = ft_strjoin(str, buff);
		if (ft_endofline(buff))
			break ;
	}
	
	return (0);
}
