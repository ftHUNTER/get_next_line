/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:01:44 by rchmouk           #+#    #+#             */
/*   Updated: 2022/11/13 17:52:54 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif 

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char	*s1, char	*s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s1);
char	*ft_strdup(const char	*s1);

#endif
