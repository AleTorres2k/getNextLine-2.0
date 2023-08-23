/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aletorre <aletorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:05:00 by aletorre          #+#    #+#             */
/*   Updated: 2023/08/23 13:51:22 by aletorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(char *rest)
{
	char	*auxrest;
	int		i;
	int		j;
	int		restlength;

	i = 0;
	j = 0;
	restlength = ft_strlen(rest);
	if (rest)
	{
		if (ft_strchr(rest, '\n') && ft_strchr(rest, '\n')[1])
		{
			auxrest = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
			if (restlength > ft_strlen(ft_strchr(rest, '\n')))
			{
				while (rest[i])
				{
					auxrest[i] = rest[i];
					if (rest[i] == '\n')
					{
						i++;
						break ;
					}
					i++;
				}
				while (rest[i])
					rest[j++] = rest[i++];
					rest[j] = '\0';
				return (auxrest);
			}
			else
			{
				auxrest[0] = ft_strchr(rest, '\n')[0];
				while (rest[i])
				{
					rest[i] = rest[i + 1];
					i++;
				}
				return (auxrest);
			}
		}
		else
			return (rest);
	}
	return (NULL);
}

char	*get_line(int fd, char *buffer, char *rest)
{
	int		bytes;
	int		i;
	int		j;
	char	*line;
	char	*aux;

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
	aux = ft_strchr(line, '\n');
	while (aux && aux[j])
		rest[i++] = aux[j++];
	if (aux)
		aux[1] = '\0';
	if (j > 1)
		rest[j] = '\0';
	if (bytes == 0 && rest == NULL)
		return (NULL);
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
