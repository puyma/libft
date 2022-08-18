/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:26:28 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/08/18 16:42:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a line read from a file descriptor.

#include "get_next_line.h"

char	*ft_line(char *nl_buf)
{
	char	*line;
	int		end;

	end = ft_strchr(nl_buf, '\n') - nl_buf;
	if (end <= 0)
		return (nl_buf);
	line = ft_substr(nl_buf, 0, end);
	return (line);
}

char	*ft_fill_until_nl(int fd)
{
	int		read_value;
	char	*buf;
	char	*line_buf = "";

	buf = (char *) malloc(sizeof(*buf) * BUFFER_SIZE);
	ft_memset(buf, 0, (sizeof(*buf) * BUFFER_SIZE));
	while (ft_strchr(buf, '\n') == 0 && read_value > 0)
	{
		ft_memset(buf, 0, (sizeof(*buf) * BUFFER_SIZE));
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value > 0)
			line_buf = ft_strjoin(line_buf, buf);
	}
	return (line_buf);
}

char	*get_next_line(int fd)				
{
	static char		*nl_buf;
	char			*next_line;

	nl_buf = ft_fill_until_nl(fd);
	next_line = ft_line(nl_buf);
	return (next_line);
}
