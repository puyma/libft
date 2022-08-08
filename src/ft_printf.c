/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/18 16:26:27 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	static const char	formats[] = "cspdiuxX%";
	int					counter;
	va_list				args;

	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && ft_strchr(formats, *(format + 1)) != 0)
		{
			counter += ft_print_formats(format + 1, &args);
			format++;
		}
		else if (*format == '%' && ft_strchr(formats, *(format + 1) == 0))
			ft_putstr_fd("invalid...", FD);
		else
			counter += ft_putchar_fd(*format, FD);
		format++;
	}
	va_end(args);
	return (counter);
}
