/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:00:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/08/26 19:00:33 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h> /* write, close */
#include <fcntl.h> /* open */
#include <stdlib.h> /* free */

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
	counter = 1;
	while (counter--)
	{
		line = get_next_line(fd);
		if (line == NULL)
			write(1, "(null)", 6);
		else if (*line == '\0')
			write(1, "\\0", 2);
		else
		{
			i = 0;
			while (line[i] != '\0')
				ft_putchar_mod(line[i++]);
		}
		free(line);
		write(1, "&\n", 2);
	}
	close(fd);
	return (0);
}
