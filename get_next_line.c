#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_realloc_str(char *str)
{
	char	*aux;

	aux = ft_str_alloc(ft_strlen(str));
	if (!aux)
		return(NULL);
	
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
		
	}
	return (0);
}
