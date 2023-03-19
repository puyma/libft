/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:29:07 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/03/19 17:09:45 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

/*
** This get_next_line version doesn't use ft_memset (or bzero)
** but a 2-4 line version of it. FIX, please.
*/

static char	*ft_read_until(int fd, int c, char *buffer);
static char	*ft_get_line(char *buffer);
static char	*ft_leftovers(char *leftovers);
static int	ft_read_loop(int fd, char **buf, char **buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = ft_read_until(fd, '\n', buffer);
	if (buffer == NULL)
		return (0);
	line = ft_get_line(buffer);
	buffer = ft_leftovers(buffer);
	return (line);
}

static char	*ft_read_until(int fd, int c, char *buffer)
{
	char			*buf;
	unsigned char	*cpy;
	size_t			cpy_len;

	if (read(fd, NULL, 0) || BUFFER_SIZE == 0)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	cpy = (unsigned char *) buf;
	cpy_len = BUFFER_SIZE + 1;
	while (cpy_len--)
		*cpy++ = 0;
	while (ft_strchr(buf, c) == 0)
	{
		if (ft_read_loop(fd, &buf, &buffer) == -1)
			break ;
	}
	free(buf);
	if (!buffer || *buffer == '\0')
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

static int	ft_read_loop(int fd, char **buf, char **buffer)
{
	char			*temp;
	int				read_value;
	unsigned char	*cpy;
	size_t			cpy_len;

	cpy = (unsigned char *) *buf;
	cpy_len = BUFFER_SIZE;
	while (cpy_len--)
		*cpy++ = 0;
	read_value = read(fd, *buf, BUFFER_SIZE);
	if (read_value <= 0)
		return (-1);
	if (*buffer == NULL)
		*buffer = "\0";
	temp = ft_strjoin(*buffer, *buf);
	if (buffer[0][0] != '\0')
		free(*buffer);
	*buffer = temp;
	return (0);
}

static char	*ft_get_line(char *buffer)
{
	int		len;
	char	*line;

	if (buffer == NULL)
		return (NULL);
	if (ft_strchr(buffer, '\n') == 0)
		return (buffer);
	len = ft_strchr(buffer, '\n') - buffer + 1;
	line = ft_substr(buffer, 0, len);
	if (line == NULL || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*ft_leftovers(char *buffer)
{
	int		len;
	char	*leftovers;

	if (buffer == NULL || ft_strchr(buffer, '\n') == 0)
		return (NULL);
	len = (int) ft_strlen(ft_strchr(buffer, '\n'));
	leftovers = ft_substr(ft_strchr(buffer, '\n') + 1, 0, len);
	free(buffer);
	buffer = NULL;
	if (leftovers == NULL || *leftovers == '\0')
	{
		free(leftovers);
		return (NULL);
	}
	return (leftovers);
}
