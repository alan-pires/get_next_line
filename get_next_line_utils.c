 #include "get_next_line.h"

 size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

 char	*ft_getline(char *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s));
	while (s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

int	ft_ismatch(char*s, int c)
{
	size_t	i;
	size_t	j;
	char	match;

	i = 0;
	j = 0;
	match = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == match)
			return (1);
		i++;
	}
	return (0);
}