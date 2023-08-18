/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aletorre <aletorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:05:00 by aletorre          #+#    #+#             */
/*   Updated: 2023/08/18 14:01:01 by aletorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_rest(char *rest)
{
	static char	*auxrest;
	int			i;
	int			j;

	i = 1;
	j = 0;
	auxrest = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (rest)
	{
		if (ft_strchr(rest, '\n') && ft_strchr(rest, '\n')[1])
		{
			while (ft_strchr(rest, '\n')[i])
				auxrest[j++] = ft_strchr(rest, '\n')[i++];
			return ("\n");
		}
		else if (ft_strchr(rest, '\n') && ft_strchr(rest, '\n')[1] == '\0')
		{
			return ("\n");
		}
		else
		{
			return (rest);
		}
	}
	return ("");
}

char	*get_line(int fd, char *buffer, char *rest)
{
	int		bytes;
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 1;
	bytes = -1;
	line = get_rest(rest);
	while (bytes != 0 && !ft_strchr(line, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	while (ft_strchr(line, '\n') && ft_strchr(line, '\n')[j])
		rest[i++] = ft_strchr(line, '\n')[j++];
	if (ft_strchr(line, '\n'))
		//ft_strchr(line, '\n')[1] = '\0';
		write(1, &ft_strchr(line, '\n')[1], 1);
	rest[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!rest)
		rest = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = get_line(fd, buf, rest);
	buf[0] = '\0';
	free(buf);
	return (line);
}
