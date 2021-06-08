 #include "get_next_line.h"

char	*ft_strchr(char*s, int c)
{
	size_t	i;
	size_t	j;
	char	match;
	char	*str;

	i = 0;
	j = 0;
	match = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == match)
		{
			str = malloc(i);
			while (j < i)
			{
				str[j] = s[j];
				j++;
			}
			return (str);
		}
		i++;
	}
	return (NULL);
}