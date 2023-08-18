/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aletorre <aletorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:07:05 by aletorre          #+#    #+#             */
/*   Updated: 2023/08/14 12:32:32 by aletorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		str1len;
	int		str2len;
	char	*finalstr;
	int		i;

	str1len = ft_strlen((char *)str1);
	str2len = ft_strlen((char *)str2);
	finalstr = (char *)malloc(sizeof(char) * (str1len + str2len) + 1);
	if (!finalstr)
		return (NULL);
	i = -1;
	while ((str1) && (str1[++i]))
	{
		finalstr[i] = str1[i];
	}
	i = -1;
	while ((str2) && (str2[++i]))
	{
		finalstr[str1len] = str2[i];
		str1len++;
	}
	finalstr[str1len] = '\0';
	return (finalstr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;
	size_t	i;

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
