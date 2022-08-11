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

static int	ft_print_formats(const char *s, va_list *v)
{
	unsigned int	counter;

	counter = 0;
	if (*s == 'c')
		counter += ft_putchar(va_arg(*v, int));
	else if (*s == 's')
		counter += ft_putstr(va_arg(*v, char *));
	else if (*s == 'p')
		counter += ft_illtohex(va_arg(*v, unsigned long long), *s, 16);
	else if (*s == 'd' || *s == 'i')
		counter += ft_putnbr(va_arg(*v, int));
	else if (*s == 'u')
		counter += ft_putnbr(va_arg(*v, unsigned int));
	else if (*s == 'x' || *s == 'X')
		counter += ft_illtohex(va_arg(*v, unsigned int), *s, 16);
	else if (*s == '%')
		counter += ft_putchar('%');
	return (counter);
}

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
			ft_putstr("invalid...");
		else
			counter += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (counter);
}
