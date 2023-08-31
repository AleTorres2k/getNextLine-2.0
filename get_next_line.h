/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aletorre <aletorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:07:08 by aletorre          #+#    #+#             */
/*   Updated: 2023/08/31 12:21:57 by aletorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h> //Para utilizar O_RDONLY
# include <stdio.h> //Para utilizar NULL o también vale stdlib.h
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_get_line(char *rest);
char	*ft_read_buffer(int fd, char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);

#endif