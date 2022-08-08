/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:26:28 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/28 19:35:29 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a line read from a file descriptor.

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned char	*ss;

	ss = (unsigned char *) s + start;
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = (char *) malloc(sizeof(*s) * len + 1);
	if (substr == NULL)
		return (0);
	i = 0;
	while (len--)
		substr[i++] = *ss++;
	substr[i] = '\0';
	return (substr);
}

char	*ft_fill_until_nl(int fd)
{
	int		read_value;
	char	*buf;
	char	*line_buf = "";

	(void) read_value;
	buf = calloc(BUFFER_SIZE, sizeof(*buf));
	while (ft_strchr(buf, '\n') == 0)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		if (read(fd, buf, BUFFER_SIZE) > 0)
			line_buf = ft_strjoin(line_buf, buf);
		else
		{
			//printf("returned null\n");
			//return (NULL);
			break ;
		}
	}
	if (*line_buf == '\0')
		return (NULL);
	return (line_buf);
}

char	*get_next_line(int fd)				
{
	static char		*line_buf;
	char			*temp;
	char			*substr;
	unsigned int	end;

	(void) temp;
	(void) end;
	(void) substr;
	line_buf = ft_fill_until_nl(fd);
	/*
	end = ft_strchr(line_buf, '\n') - line_buf;
	if (end < 0)
		return (line_buf);
	substr = ft_substr(line_buf, 0, end);
	*/
	return (line_buf);
}
