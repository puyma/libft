/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:26:28 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/08/22 20:29:17 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a line read from a file descriptor.

#include "get_next_line.h"
#include <stdio.h>

char	*ft_fill_until_nl(int fd, char *rest)
{
	char	*buffer;
	char	*buf;
	int		n_read;

	buffer = ft_strjoin(rest, "");
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	ft_memset(buf, 0, BUFFER_SIZE);
	while (ft_strchr(buf, '\n') == 0)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		n_read = read(fd, buf, BUFFER_SIZE);
		//printf("\tbuf = \"%s\"\n", buf);
		if (n_read > 0)
			buffer = ft_strjoin(buffer, buf);
		else
			break ;
	}
	if (n_read == -1)
		return (NULL);
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)				
{
	char			*buffer;
	char			*line;
	static char		*rest;
	int				len;

	if (rest == NULL)
		rest = ft_strdup("");
	buffer = ft_fill_until_nl(fd, rest);
	free(rest);
	len = ft_strchr(buffer, '\n') - buffer;
	line = ft_substr(buffer, 0, len + 1);
	rest = ft_substr(buffer, len + 1, ft_strlen(buffer) - len + 1);
	free(buffer);
	return (line);
}
