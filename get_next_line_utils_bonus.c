/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:59:49 by cnavone           #+#    #+#             */
/*   Updated: 2020/12/03 21:17:28 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	z;

	z = 0;
	while (s[z] != '\0')
		z++;
	return (z);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (s == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	if (!(start > ft_strlen(s)))
	{
		while (i < len && s[i + start])
		{
			dest[i] = s[i + start];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *string;
        size_t  i;
        size_t  j;

        if (s1 == 0 || s2 == 0)
                return (0);
        i = 0;
        if ((string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
                                        * sizeof(*string))) == 0)
                return (0);
        while (s1[i] != '\0')
        {
                string[i] = s1[i];
                i++;
        }
        j = 0;
        while (s2[j] != '\0')
        {
                string[i] = s2[j];
                i++;
                j++;
        }
        free((char *)s1);
        string[i] = '\0';
        return (string);
}

char		*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		result[i] = (char)s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dst == NULL || src == NULL)
		return (0);
	while (src[len] != '\0')
		len++;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (len);
}


