/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/08 19:22:01 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printout	p;

	va_start(p.args, format);
	p.format = format;
	p.n_written = 0;
	while (*(p.format) != '\0' && p.n_written >= 0)
	{
		ft_dump_flags(&p);
		if (*(p.format) == '%')
			ft_print_formats(&p);
		else
			ft_ensure_print(&p, ft_putchar(*(p.format)));
		p.format++;
	}
	va_end(p.args);
	return (p.n_written);
}

void	ft_print_formats(t_printout *p)
{
	t_fptr	func;

	p->format++;
	if (ft_strchr(FLAGS, *(p->format)) != 0 || ft_isdigit(*(p->format)))
		ft_manage_flags(p);
	if (ft_strchr(FORMATS, *(p->format)) != 0)
	{
		func = ft_formats(p->format);
		func(&p->args, p, p->format);
	}
	else
		ft_putstr("Invalid format");
}

void	ft_ensure_print(t_printout *p, int func_return)
{
	if (func_return == -1)
		p->n_written = -1;
	else if (func_return >= 0)
		p->n_written += func_return;
}