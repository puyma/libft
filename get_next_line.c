/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:29:07 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/16 12:54:33 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_until(int fd, int c, char **buffer);
char	*ft_get_line(char **buffer);

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	
	buffer = ft_read_until(fd, '\n');
	line = ft_get_line(&buffer);
	return (line);
}

char	*ft_read_until(int fd, int c, char **buffer)
{
	char	*buf;
	int		read_value;

	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	ft_memset(buf, '\0', BUFFER_SIZE);
	while (ft_strchr(buf, c) == 0)
	{
		ft_memset(buf, '\0', BUFFER_SIZE);
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value <= 0)
			break ;
		*buffer = ft_strjoin(*buffer, buf);
	}
	return (NULL);
}

char	*ft_get_line(char **buffer)
{
	char	*line;

	(void) *buffer;
	line = NULL;
	return (line);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

