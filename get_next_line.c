/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:50:15 by cnavone           #+#    #+#             */
/*   Updated: 2020/12/04 05:54:12 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int      ft_check_n(char *s_line)
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

static int      ft_check_line(char **s_line, char **line)
{
        int             i;
        char    *tmp;

        i = ft_check_n(*s_line);
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

int                     get_next_line(int fd, char **line)
{
        ssize_t         res;
        char            buffer[ARG_MAX];
        static char     *tab[OPEN_MAX];

        if (line == NULL || fd < 0 || BUFFER_SIZE == 0 || read(fd, buffer, 0) == -1)
                return (-1);
        if (tab[fd] != NULL)
        {
                if (ft_check_line(&tab[fd], line) == 1)
                        return (1);
        }
        else
                tab[fd] = ft_strdup("");
        while ((res = read(fd, buffer, BUFFER_SIZE)) > 0)
        {
                buffer[res] = '\0';
                tab[fd] = tab[fd] == NULL ? ft_strdup(buffer) : ft_strjoin(tab[fd], buffer);
                if (tab[fd] == NULL)
                        return (-1);
                if (ft_check_line(&tab[fd], line) == 1)
                        return (1);
        }
        *line = res < 0 ? NULL : tab[fd];
        tab[fd] = NULL;
        return (res);
}
