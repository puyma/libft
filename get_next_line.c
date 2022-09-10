/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:29:35 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/10 21:27:20 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h> /* read */

#include <stdio.h>

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
	int		read_return;

	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	ft_memset(buf, '\0', BUFFER_SIZE);
	read_return = 1;
	while (ft_strchr(buf, '\n') == 0)
	{
		ft_memset(buf, '\0', BUFFER_SIZE);
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return <= 0)
			break;
		ft_putstr_mod("--: ");ft_putstr_mod(buf);ft_putstr_mod("\t:--");
		write(1, "\n", 1);
	}
	if (read_return <= -1)
			printf("errored reading");
	else if (read_return == 0)
		printf("Reached end of file.\n");
	return (buf);
}

char	*get_next_line(int fd)
{
	char	*line = NULL;
	printf("fd: %d\n", fd);
	char	*buf = ft_read_until(fd);
	ft_putstr_mod("bf: \"");ft_putstr_mod(buf);ft_putstr_mod("\"");
	write(1, "\n", 1);
	return (line);
}
