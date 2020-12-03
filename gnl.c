#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	long int size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substring;

	i = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if ((substring = malloc((len + 1) * sizeof(char))) == 0)
		return (0);
	while (i < len && (start + i) < s_len)
	{
		substring[i] = s[i + start];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

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

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;

	len = ft_strlen(s1) + 1;
	if ((cpy = ((char *)malloc(sizeof(char) * len))) != 0)
	{
		ft_strlcpy(cpy, s1, len);
		return (cpy);
	}
	else
		return (0);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (src == 0)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *restrict dst,
		const char *restrict src, size_t destsize);

#endif#include "get_next_line.h"

static int	gnl_end_line(char *s_line)
{
	int i;

	i = 0;
	if (s_line == 0)
		return (-1);
	while (s_line[i] != '\0')
	{
		if (s_line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	gnl_return_line(char **s_line, char **line)
{
	int		i;
	char	*tmp;

	i = gnl_end_line(*s_line);
	if (i >= 0)
	{
		*line = ft_substr(*s_line, 0, i);
		tmp = ft_substr(*s_line, i + 1, ft_strlen(*s_line));
		free(*s_line);
		*s_line = tmp;
		tmp = NULL;
		return (1);
	}
	else
		return (0);
}

int			get_next_line(int fd, char **line)
{
	char		buff[ARG_MAX];
	ssize_t		ret;
	static char	*s_l[OPEN_MAX];

	if (line == 0 || fd < 0 || BUFFER_SIZE == 0)
		return (-1);
	if (s_l[fd] != NULL)
	{
		if (gnl_return_line(&s_l[fd], line) == 1)
			return (1);
	}
	else
		s_l[fd] = ft_strdup("");
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		s_l[fd] = s_l[fd] == NULL ? ft_strdup(buff) : ft_strjoin(s_l[fd], buff);
		if (s_l[fd] == 0)
			return (-1);
		if (gnl_return_line(&s_l[fd], line) == 1)
			return (1);
	}
	*line = ret < 0 ? NULL : s_l[fd];
	s_l[fd] = NULL;
	return (ret);
}}
