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

static void	ft_print_formats(t_printout *p)
{
	t_fptr	func;

	if (ft_strchr(FORMATS, *(p->format)) != 0)
	{
		func = ft_formats(p);
		func(&p->args, p, p->format);
	}
	else if (ft_strchr(FLAGS, *(p->format)) != 0)
	{
		ft_manage_flags(p);
	}
	else
		ft_putstr("Invalid format");
}

static void	ft_print_non_formats(t_printout *p)
{
	if (ft_putchar(*p->format) == -1)
		p->n_written = -1;
	else
		p->n_written++;
}

int	ft_printf(const char *format, ...)
{
	t_printout	p;

	va_start(p.args, format);
	p.format = format;
	p.n_written = 0;
	while (*p.format != '\0' && p.n_written >= 0)
	{
		if (*p.format == '%')
		{
			p.format++;
			ft_print_formats(&p);
		}
		else
			ft_print_non_formats(&p);
		p.format++;
	}
	va_end(p.args);
	return (p.n_written);
}
