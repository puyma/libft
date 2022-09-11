/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:29:35 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/11 19:09:06 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_read_until(int fd)
{
	char	*buf;
	char	*whole_buffer;
	char	*temp;
	int		read_return;

	whole_buffer = "";
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	ft_memset(buf, '\0', BUFFER_SIZE + 1);
	read_return = 1;
	while (ft_strchr(buf, '\n') == 0)
	{
		ft_memset(buf, '\0', BUFFER_SIZE);
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return <= 0)
			break ;
		temp = ft_strjoin(whole_buffer, buf);
		if (whole_buffer != NULL && *whole_buffer != '\0')
			free(whole_buffer);
		whole_buffer = temp;
		//ft_putstr_mod("--: ");ft_putstr_mod(buf);ft_putstr_mod("  :--");
		//write(1, "\n", 1);
	}
	//if (read_return <= -1)
	//	write(1, "Errored reading file descriptor.\n", 33);
	//else if (read_return == 0)
	//	write(1, "Reached end of file.\n", 23);
	//write(1, "end> ft_read_until()\n", 21);
	//ft_putstr_mod("w_buffer> \"");
	//ft_putstr_mod(whole_buffer);
	//write(1, "\"\n", 2);
	if (read_return == -1)
	{
		if (buf != NULL)
			free(buf);
		return (NULL);
	}
	free(buf);
	return (whole_buffer);
}

char	*ft_get_line(const char *buffer, char **remains)
{
	char	*line;
	char	*substr;

	if (buffer == NULL)
		return (NULL);
	substr = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer + 1);
	if (*remains == NULL)
		line = substr;
	else
	{
		line = ft_strjoin(*remains, substr);
		free(*remains);
	}
	*remains = ft_substr(buffer, ft_strchr(buffer, '\n') - buffer + 1, ft_strlen(buffer));
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*leftovers;

	buffer = ft_read_until(fd);
	if (buffer == NULL)
		return (NULL);
	if (buffer != NULL && ft_strchr(buffer, '\n') == 0)
	{
	//	write(1, "Something went wrong when trying to ft_get_line.\n", 49);
		//return (NULL);
	}
	line = ft_get_line(buffer, &leftovers);
	free(buffer);
	return (line);
}
