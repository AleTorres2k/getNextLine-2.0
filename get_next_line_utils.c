/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aletorre <aletorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:07:05 by aletorre          #+#    #+#             */
/*   Updated: 2023/08/31 12:30:45 by aletorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*finalstr;
	int		i;
	int		str1len;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * (1 * sizeof(char)));
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	str1len = ft_strlen(str1);
	finalstr = (char *)malloc(sizeof(char) * (str1len + ft_strlen(str2) + 1));
	if (!finalstr)
		return (NULL);
	i = -1;
	if (str1)
		while ((str1) && (str1[++i]))
			finalstr[i] = str1[i];
	i = -1;
	while ((str2) && (str2[++i]))
		finalstr[str1len++] = str2[i];
	finalstr[str1len] = '\0';
	free(str1);
	return (finalstr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;
	size_t	i;

	if (!s)
		return (0);
	c = (char)c;
	aux = (char *)s;
	i = 0;
	while (aux[i] != c)
	{
		if (aux[i] == '\0')
			return (NULL);
		i++;
	}
	return (aux + i);
}
