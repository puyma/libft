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

static char	*ft_read_until(int fd, int c);
static char	*ft_get_line(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	buffer = ft_read_until(fd, '\n');
	line = ft_get_line(buffer);
	//buffer = ft_set_buffer(buffer);
	return (line);
}

static char	*ft_read_until(int fd, int c)
{
	char	*buf;
	char	*buffer;
	//char	*temp;
	int		read_value;

	//buffer = NULL;
	if (read(fd, NULL, 0))
		return (NULL);
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
		if (buffer == '\0')
			write(1, "hell yes\n", 9);
		/*
		if (buffer != NULL)
			buffer = ft_strjoin(buffer, buf);
		else
			buffer = buf;
		*/
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



size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (dstsize <= len)
		return (ft_strlen(src) + dstsize);
	while (src[i] != '\0' && (i + len < dstsize - 1))
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	return (len + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strjoin = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (strjoin == NULL)
		return (0);
	ft_memset(strjoin, 0, len_s1 + len_s2 + 1);
	ft_strlcat(strjoin, s1, len_s1 + 1);
	ft_strlcat(strjoin, s2, len_s1 + len_s2 + 1);
	return (strjoin);
}

