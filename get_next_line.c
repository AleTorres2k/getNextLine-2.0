/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aletorre <aletorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:05:00 by aletorre          #+#    #+#             */
/*   Updated: 2023/08/31 12:22:13 by aletorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buffer(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_get_line(char *rest)
{
	int		i;
	char	*line;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char *) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_rest(char *rest)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	i++;
	j = 0;
	while (rest[i])
		str[j++] = rest[i++];
	str[j] = '\0';
	free(rest);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read_buffer(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_get_line(rest);
	rest = ft_get_rest(rest);
	return (line);
}
