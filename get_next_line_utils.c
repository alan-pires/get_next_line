 #include "get_next_line.h"

 size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	p = (char *)malloc((len + 1) * sizeof(char));
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

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = ft_str_alloc(ft_strlen(s1));
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

/*
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
*/