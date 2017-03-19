/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:07:06 by omotyliu          #+#    #+#             */
/*   Updated: 2017/01/20 18:07:07 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char	*gnl_join(char *str, char *buff)
{
    char *tmp;

    tmp = ft_strjoin(str, buff);
    ft_strdel(&str);
    return (tmp);
}

static int		find_nl(char *str, char **line, char *stat)
{
    size_t	i;
    char	*presult;
    char	*tmp;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            presult = ft_strsub(str, 0, i);
            tmp = ft_strsub(str, (unsigned int)(i + 1),
                            (int)ft_strlen(str) - i);
            ft_memmove(stat, tmp, ft_strlen(tmp) + 1);
            *line = ft_strdup(presult);
            free(tmp);
            free(presult);
            return (1);
        }
        i++;
    }
    return (0);
}

int		get_next_line(const int fd, char **line)
{
    ssize_t		ret;
    char		buff[BUFF_SIZE + 1];
    static char	sgnl[OPEN_MAX][BUFF_SIZE + 1];
    char		*wstr;

    if (fd < 0 || fd > OPEN_MAX || !line || BUFF_SIZE <= 0)
        return (-1);
    else if (find_nl(sgnl[fd], line, sgnl[fd]))
        return (1);
    wstr = ft_strdup(sgnl[fd]);
    ft_memset(buff, 0, BUFF_SIZE);
    while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
    {
        if (ret < 0 || (buff[ret] = '\0'))
            return (-1);
        wstr = gnl_join(wstr, buff);
        if (find_nl(wstr, line, sgnl[fd]))
        {
            free(wstr);
            return (1);
        }
    }
    if (ft_strlen(wstr) > 0 && ret == 0)
        sgnl[fd][0] = '\0';
    return ((*line = wstr) && ft_strlen(*line) != 0);
}