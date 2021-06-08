#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line)
{
	int			read_bytes;
	static char	*buf;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (0);
	while (read_bytes = read(fd, buf, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_strchr(buf, '\n');
			printf("%s\n",*line);
			return (1);
		}
	}
	return (0);
}
