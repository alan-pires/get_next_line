/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:25:16 by apires-d          #+#    #+#             */
/*   Updated: 2021/06/13 19:27:29 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	p = (char *)malloc((len + 1) * sizeof(*p));
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

static char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	copy = malloc((ft_strlen(s1) + 1) * sizeof(*copy));
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

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	match;

	i = 0;
	match = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == match)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == match)
		return ((char *)s + i);
	return (NULL);
}
