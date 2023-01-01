/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:54:27 by rchmouk           #+#    #+#             */
/*   Updated: 2022/12/31 20:37:39 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *bag)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(bag, '\n') && rd)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free (bag);
			free (buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		bag = ft_strjoin(bag, buffer);
	}
	free (buffer);
	return (bag);
}

char	*ft_line(char *bag)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strlen(bag))
		return (NULL);
	while (bag[i] && bag[i] != '\n')
		i++;
	if (bag[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	while (j <= i && bag[j])
	{
		line[j] = bag[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_cut(char *bag)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!bag[i])
	{
		free (bag);
		return (NULL);
	}
	while (bag[i] && bag[i] != '\n')
		i++;
	if (bag[i] == '\n')
		i++;
	remainder = malloc(sizeof(char) * (ft_strlen(bag) - i + 1));
	if (!remainder)
	{
		free (bag);
		return (NULL);
	}
	while (bag[i])
		remainder[j++] = bag[i++];
	free (bag);
	return (remainder[j] = '\0', remainder);
}

char	*get_next_line(int fd)
{
	static char	*bag[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bag[fd] = ft_read(fd, bag[fd]);
	if (!bag[fd])
		return (NULL);
	line = ft_line(bag[fd]);
	bag[fd] = ft_cut(bag[fd]);
	return (line);
}

