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
	t_fptr				func;
	t_printout			p;

	va_start(p.args, format);
	p.n_written = 0;
	while (*format != '\0' && p.n_written >= 0)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)) != 0)
		{
			func = ft_formats(++format);
			func(&p.args, &p, format);
		}
		else if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1) == 0))
			ft_putstr("Invalid format");
		else
		{
			if (ft_putchar(*format) == -1)
				p.n_written = -1;
			else
				p.n_written++;
		}
		format++;
	}
	va_end(p.args);
	return (p.n_written);
}
