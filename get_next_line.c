/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:29:35 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/12 12:35:19 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_mod(const char *s)
{
	while (s != NULL && *s != '\0')
	{
		if (*s == '\n')
			write(1, "\\n", 2);
		else
			write(1, s, 1);
		s++;
	}
}

static char	*ft_read_until(int fd)
{
	char	*buf;
	char	*whole_buffer;
	char	*temp;
	int		read_return;

	whole_buffer = "";
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	ft_memset(buf, '\0', BUFFER_SIZE + 1);
	read_return = 1;
	while (ft_strchr(buf, '\n') == 0 && read_return > 0)
	{
		ft_memset(buf, '\0', BUFFER_SIZE);
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return <= 0)
			break ;
		temp = ft_strjoin(whole_buffer, buf);
		if (whole_buffer != NULL && *whole_buffer != '\0')
			free(whole_buffer);
		whole_buffer = temp;
	}
	if (read_return == -1 || (read_return == 0 && *whole_buffer == '\0'))
	{
		free(buf);
		return (NULL);
	}
	free(buf);
	return (whole_buffer);
}

static char	*ft_get_line(const char *buffer, char **leftovers)
{
	char	*line;
	char	*substr;
	char	*remains;

	if (buffer == NULL)
		return (NULL);
	substr = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer + 1);
	if (substr == NULL)
		return (NULL);
	if (*leftovers == NULL)
		line = substr;
	else
		line = ft_strjoin(*leftovers, substr);
	if (*leftovers != NULL)
		free(substr);
	free(*leftovers);
	*leftovers = NULL;
	if (ft_strchr(buffer, '\n') != 0)
		remains = ft_strchr(buffer, '\n');
	else
		remains = ft_strchr(buffer, '\0');
	if (remains != NULL)
		*leftovers = ft_substr(remains, 1, ft_strlen(remains));
	else
		*leftovers = ft_substr(remains, 1, ft_strchr(remains, '\n') - remains + 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*buffer;
	char		*line;

	buffer = ft_read_until(fd);
	line = ft_get_line(buffer, &leftovers);
	free(buffer);
	if (line != NULL && *line != '\0')
	{
		/*
		ft_putstr_mod(" w_buffer> ");ft_putstr_mod(buffer);write(1, "\n", 1);
		ft_putstr_mod("     line> ");ft_putstr_mod(line);write(1, "\n", 1);
		ft_putstr_mod("leftovers> ");ft_putstr_mod(leftovers);write(1, "\n", 1);
		*/
		return (line);
	}
	free(line);
	return (NULL);
}
