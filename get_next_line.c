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

char	*ft_fill_until_nl(int fd, char *rest)
{
	char	*buffer;
	char	*buf;
	int		n_read;
	char	*temp;

	buffer = ft_strjoin(rest, "");
	if (rest == NULL)
		free(rest);
	rest = NULL;
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free(buffer);
		return (NULL);
	}
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	while (ft_strchr(buf, '\n') == 0 && fd != -1)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read > 0)
		{
			temp = ft_strjoin(buffer, buf);
			free(buffer);
			buffer = temp;
		}
		else
			break ;
	}
	free(buf);
	if (n_read == -1 || fd == -1 || *buffer == '\0')
	{
		free(buffer);
		return (NULL);
	}
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
	if (buffer == NULL)
		return (NULL);
	if (ft_strchr(buffer, '\n') == 0)
		len = ft_strlen(buffer);
	else
		len = ft_strchr(buffer, '\n') - buffer;
	line = ft_substr(buffer, 0, len + 1);
	rest = ft_substr(buffer, len + 1, ft_strlen(buffer) - len + 1);
	free(buffer);
	return (line);
}
