#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	p = (char *)ft_calloc((len + 1), sizeof(char));
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

int	get_next_line(int fd, char **line)
{
	int			read_b;
	static char	*str;
	char		*buff;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	str = NULL;
	buff = malloc(BUFFER_SIZE);
	str = malloc(BUFFER_SIZE);
	if (!buff || !str)
		return (-1);
	while (read_b = read(fd, buff, BUFFER_SIZE) > 0)
	{
		
	}
	return (0);
}
