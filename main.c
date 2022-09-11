/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:00:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/11 15:01:13 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> /* open */

void	ft_putchar_mod(int c)
{
	if (c == '\n')
		write(1, "\\n", 2);
	else
		write(1, &c, 1);
}

int	main(void)
{
	int		fd;
	int		counter;
	int		i;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	counter = 3;
	while (counter--)
	{
		line = get_next_line(fd);
		if (line == NULL)
			write(1, "(null)", 6);
		else if (*line == '\0')
			write(1, "\\0", 2);
		else
		{
			write(1, "Received: ", 10);
			write(1, "\"", 1);
			i = 0;
			while (line[i] != '\0')
				ft_putchar_mod(line[i++]);
			write(1, "\"", 1);
		}
		free(line);
		write(1, "\n", 1);
	}
	close(fd);
	return (0);
}
