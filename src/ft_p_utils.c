/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:46:34 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/23 11:46:34 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_putstr_fd(char *s, int fd)
{
	int		nb;

	nb = 0;
	while (s != NULL && *s != '\0')
	{
		if (write(fd, s, 1) == -1)
		{
			nb = -1;
			break ;
		}
		else
			++nb;
		++s;
	}
	return (nb);
}

int	ft_p_putchar_fd(int c, int fd)
{
	int		nb;

	nb = 0;
	nb = write(fd, &c, 1);
	return (nb);
}
