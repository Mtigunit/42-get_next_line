/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:48:21 by mtigunit          #+#    #+#             */
/*   Updated: 2022/11/02 22:28:43 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char **saved)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	tmp = *saved;
	while (tmp[i] != '\n')
		i++;
	line = ft_substr(tmp, 0, i + 1);
	if (!tmp[i + 1])
	{
		free (*saved);
		*saved = NULL;
		return (line);
	}
	*saved = ft_strdup(&tmp[i + 1]);
	free(tmp);
	return (line);
}

static char	*line_no_nl(char **saved)
{
	char		*line;

	line = *saved;
	*saved = NULL;
	return (line);
}

static int	read_and_read(int fd, char **saved, char *buff)
{
	char	*tmp;
	int		readed;

	readed = 1;
	while (!ft_strchr(saved[fd], '\n') && readed)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed <= 0)
			return (readed);
		buff[readed] = '\0';
		tmp = saved[fd];
		saved[fd] = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (readed);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*saved[10240];
	int			readed;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	readed = read_and_read(fd, saved, buff);
	if ((readed <= 0))
		return (line_no_nl(&saved[fd]));
	if (ft_strchr(saved[fd], '\n'))
		return (extract_line(&saved[fd]));
	return (NULL);
}
