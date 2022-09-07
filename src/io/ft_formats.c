/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:37:22 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/07 22:26:02 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../io/ft_io.h" /* put_utils */
#include "../stdlib/ft_stdlib.h" /* ft_illtohex() */
#include "ft_printf.h" /* stdarg, ft_formats, t_fptr */

static void	ft_do_flag_adjustment(t_printout *p, const char c, int length)
{
	ft_printf("length: %d\n", length);
	if (length > p->n_precision)
		length = length - p->n_precision;
	else
		length = p->n_precision - length;
	while (--length >= 0 && p->n_written != -1)
	{
		ft_ensure_print(p, ft_putchar(c));
	}
}

t_fptr	ft_formats(const char *s)
{
	t_fptr	do_func;

	if (*s == 'c' || *s == 's' || *s == '%')
		do_func = ft_formats_cs;
	else if (*s == 'd' || *s == 'i' || *s == 'u')
		do_func = ft_formats_du;
	else if (*s == 'p' || *s == 'x' || *s == 'X')
		do_func = ft_formats_xp;
	else
		do_func = NULL;
	return (do_func);
}

void	ft_formats_cs(va_list *v, t_printout *p, const char *s)
{
	char	*arg_str;
	int		precision;

	precision = p->n_precision;
	if (*s == '%')
		ft_ensure_print(p, ft_putchar('%'));
	else if (*s == 'c')
	{
		if (p->flag_adjustment == '0')
			precision--;
		while (p->flag_adjustment != '\0' && --precision >= 0)
			ft_ensure_print(p, ft_putchar(p->flag_padding_char));
		ft_ensure_print(p, ft_putchar(va_arg(*v, int)));
	}
	else if (*s == 's')
	{
		arg_str = va_arg(*v, char *);
		ft_printf("str: %s\n", arg_str);
		if (p->flag_blank != '\0' && *arg_str != '\0')
		{
			ft_printf("hey");
			ft_do_flag_adjustment(p, p->flag_alt_form, ft_strlen(arg_str));
			//ft_ensure_print(p, ft_putchar(' '));
		}
		ft_ensure_print(p, ft_putstr(arg_str));
	}
	else
		ft_ensure_print(p, -1);
}

void	ft_formats_du(va_list *v, t_printout *p, const char *s)
{
	int	argv_int;

	argv_int = 0;
	if (*s == 'u')
		ft_ensure_print(p, ft_putnbr(va_arg(*v, unsigned int)));
	else if (*s == 'd' || *s == 'i')
	{
		argv_int = va_arg(*v, int);
		if (argv_int >= 0 && p->flag_sign == '+')
			ft_ensure_print(p, ft_putchar(p->flag_sign));
		ft_ensure_print(p, ft_putnbr(argv_int));
	}
	else
		ft_ensure_print(p, -1);
}

void	ft_formats_xp(va_list *v, t_printout *p, const char *s)
{
	unsigned int	arg_uint;

	arg_uint = 0;
	if (*s == 'p')
		ft_ensure_print(p, ft_illtohex(va_arg(*v, unsigned long long), *s, 16));
	else if (*s == 'x' || *s == 'X')
	{
		arg_uint = va_arg(*v, unsigned int);
		if (p->flag_alt_form == '#' && arg_uint != 0)
		{
			ft_ensure_print(p, ft_putchar('0'));
			ft_ensure_print(p, ft_putchar(*s));
		}
		ft_ensure_print(p, ft_illtohex(arg_uint, *s, 16));
	}
	else
		ft_ensure_print(p, -1);
}
