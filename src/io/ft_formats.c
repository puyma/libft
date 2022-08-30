/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:37:22 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/08/13 10:37:22 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../io/ft_io.h" /* put_utils */
#include "../stdlib/ft_stdlib.h" /* ft_illtohex() */
#include "ft_printf.h" /* stdarg, ft_formats, t_fptr */

t_fptr	ft_formats(t_printout *p)
{
	const char	*s;
	t_fptr		return_func;

	s = p->format;
	if (*s == 'c' || *s == 's' || *s == '%')
		return_func = ft_formats_cs;
	else if (*s == 'd' || *s == 'i' || *s == 'u')
		return_func = ft_formats_du;
	else if (*s == 'p' || *s == 'x' || *s == 'X')
		return_func = ft_formats_xp;
	else
		return_func = NULL;
	return (return_func);
}

void	ft_formats_cs(va_list *v, t_printout *p, const char *s)
{
	int	return_value;

	if (*s == '%')
		return_value = ft_putchar('%');
	else if (*s == 'c')
		return_value = ft_putchar(va_arg(*v, int));
	else if (*s == 's')
		return_value = ft_putstr(va_arg(*v, char *));
	else
		return_value = -1;
	if (return_value == -1)
		p->n_written = -1;
	else
		p->n_written += return_value;
}

void	ft_formats_du(va_list *v, t_printout *p, const char *s)
{
	int			return_value;
	long int	argv_int;

	argv_int = 0;
	if (*s == 'u')
		return_value = ft_putnbr(va_arg(*v, unsigned int));
	else if (*s == 'd' || *s == 'i')
	{
		argv_int = va_arg(*v, int);
		if (argv_int >= 0 && (p->flag_numeric == '+' || p->flag_numeric == ' '))
		{
			return_value = ft_putchar(p->flag_numeric);
			if (return_value == -1)
				p->n_written = -1;
			else
				p->n_written += return_value;
		}
		return_value = ft_putnbr(argv_int);
	}
	else
		return_value = -1;
	if (return_value == -1)
		p->n_written = -1;
	else
		p->n_written += return_value;
}

void	ft_formats_xp(va_list *v, t_printout *p, const char *s)
{
	int	return_value;

	if (*s == 'p')
		return_value = ft_illtohex(va_arg(*v, unsigned long long), *s, 16);
	else if (*s == 'x' || *s == 'X')
		return_value = ft_illtohex(va_arg(*v, unsigned int), *s, 16);
	else
		return_value = -1;
	if (return_value == -1)
		p->n_written = -1;
	else
		p->n_written += return_value;
}
