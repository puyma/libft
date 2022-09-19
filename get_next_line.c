/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:29:07 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/19 15:45:34 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_until(int fd, int c, char *buffer);
static char	*ft_get_line(char *buffer);
static char	*ft_leftovers(char *leftovers);

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s != NULL && *s != '\0' && s[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = ft_read_until(fd, '\n', buffer);
	line = ft_get_line(buffer);
	buffer = ft_leftovers(buffer);
	return (line);
}

static char	*ft_read_until(int fd, int c, char *buffer)
{
	char	*buf;
	int		read_value;

	if (read(fd, NULL, 0))
		return (NULL);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	ft_memset(buf, '\0', BUFFER_SIZE);
	while (ft_strchr(buf, c) == 0)
	{
		ft_memset(buf, '\0', BUFFER_SIZE);
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value <= 0)
			break ;
		if (buffer == NULL)
			buffer = "";
		buffer = ft_strjoin(buffer, buf);
	}
	free(buf);
	if (!buffer || *buffer == '\0')
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

static char	*ft_get_line(char *buffer)
{
	int		len;
	char	*line;

	if (!buffer)
		return (NULL);
	if (ft_strchr(buffer, '\n') == 0)
		return (buffer);
	len = ft_strchr(buffer, '\n') - buffer + 1;
	line = ft_substr(buffer, 0, len);
	return (line);
}

static char	*ft_leftovers(char *buffer)
{
	int		len;
	char	*leftovers;

	if (!buffer || ft_strchr(buffer, '\n') == 0)
		return (NULL);
	len = (int) ft_strlen(ft_strchr(buffer, '\n'));
	leftovers = ft_substr(ft_strchr(buffer, '\n') + 1, 0, len);
	free(buffer);
	buffer = NULL;
	return (leftovers);
}
