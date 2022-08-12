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

static void	ft_formats_c(va_list *v, t_printout *p)
{
	int	return_value;

	return_value = ft_putchar(va_arg(*v, int));
	if (return_value == -1)
		p->n_written = -1;
	else
		p->n_written += return_value;
}

static void	ft_formats_s(va_list *v, t_printout *p)
{
	int	return_value;

	(void) v;
	(void) p;
	return_value = ft_putstr(va_arg(*v, char *));
	if (return_value == -1)
		p->n_written = -1;
	else
		p->n_written += return_value;
}

static void	ft_formats_p(va_list *v, t_printout *p)
{
	(void) v;
	(void) p;
	ft_putnbr(va_arg(*v, int));
}

static void	ft_formats_d(va_list *v, t_printout *p)
{
	(void) v;
	(void) p;
}

static void	ft_formats_u(va_list *v, t_printout *p)
{
	(void) v;
	(void) p;
}

static void	ft_formats_x(va_list *v, t_printout *p)
{
	(void) v;
	(void) p;
}

static void	ft_formats_percent(va_list *v, t_printout *p)
{
	(void) v;
	if (ft_putchar('%') == -1)
		p->n_written = -1;
	else
		p->n_written++;
}

typedef void	(*t_fptr)(va_list *v, t_printout *p);

static t_fptr	ft_formats(const char *s)
{
	if (*s == 'c')
		return (ft_formats_c);
	else if (*s == 's')
		return (ft_formats_s);
	else if (*s == 'p')
		return (ft_formats_p);
	else if (*s == 'd' || *s == 'i')
		return (ft_formats_d);
	else if (*s == 'u')
		return (ft_formats_u);
	else if (*s == 'x' || *s == 'X')
		return (ft_formats_x);
	else if (*s == '%')
		return (ft_formats_percent);
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	static const char	formats[] = "cspdiuxX%";
	t_fptr				func;
	t_printout			p;

	va_start(p.args, format);
	p.n_written = 0;
	while (*format != '\0' && p.n_written >= 0)
	{
		if (*format == '%' && ft_strchr(formats, *(format + 1)) != 0)
		{
			func = ft_formats(format + 1);
			func(&p.args, &p);
			format++;
		}
		else if (*format == '%' && ft_strchr(formats, *(format + 1) == 0))
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
