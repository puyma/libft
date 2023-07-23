/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:30:56 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/22 20:30:56 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(FILE *file, const char *format, ...)
{
	int			nb;
	int			fd;
	va_list		vargs;

	nb = 0;
	if (file != NULL)
		fd = file->_file;
	else
		fd = STDOUT_FILENO;
	va_start(vargs, format);
	ft_printf_loop(format, &vargs, &nb, fd);
	va_end(vargs);
	return (nb);
}
