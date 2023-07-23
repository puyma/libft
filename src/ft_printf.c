/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:55:47 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/22 19:55:47 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			nb;
	int			fd;
	va_list		vargs;

	nb = 0;
	fd = STDOUT_FILENO;
	va_start(vargs, format);
	ft_printf_loop(format, &vargs, &nb, fd);
	va_end(vargs);
	return (nb);
}
