/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 21:20:32 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_formats_fd(const char *s, va_list *v, int fd);

int	ft_fprintf(FILE *file, const char *format, ...)
{
	static const char	formats[] = "cspdiuxX%";
	int					counter;
	va_list				args;
	int					fd;

	fd = file->_file;
	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && ft_strchr(formats, *(format + 1)) != 0)
		{
			counter += ft_print_formats_fd(format + 1, &args, fd);
			format++;
		}
		else if (*format == '%' && ft_strchr(formats, *(format + 1) == 0))
			ft_putstr_fd("invalid...", fd);
		else
			counter += ft_putchar_fd(*format, fd);
		format++;
	}
	va_end(args);
	return (counter);
}

static int	ft_print_formats_fd(const char *s, va_list *v, int fd)
{
	unsigned int	counter;

	counter = 0;
	if (*s == 'c')
		counter += ft_putchar_fd(va_arg(*v, int), fd);
	else if (*s == 's')
		counter += ft_putstr_fd(va_arg(*v, char *), fd);
	else if (*s == 'p')
		counter += ft_illtohex_fd(va_arg(*v, unsigned long long), *s, 16, fd);
	else if (*s == 'd' || *s == 'i')
		counter += ft_putnbr_fd(va_arg(*v, int), fd);
	else if (*s == 'u')
		counter += ft_putnbr_fd(va_arg(*v, unsigned int), fd);
	else if (*s == 'x' || *s == 'X')
		counter += ft_illtohex_fd(va_arg(*v, unsigned int), *s, 16, fd);
	else if (*s == '%')
		counter += ft_putchar_fd('%', fd);
	return (counter);
}
