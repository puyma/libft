/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:32:37 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/12/28 11:32:37 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

#include <stdio.h>
#include <limits.h>

#define FORMATS "cspdiuxX"
#define FLAGS "%-0.# +"

// pf stands for pointer (to) function

typedef struct s_printout
{
	va_list		varg;
	char		*format;
	int			nb_written;
	int			n_flags;
}				t_printout;

int	ft_printf(const char *format, ...);

int	ft_print_format(t_printout *p);
int	(*ft_which_format(char c))(t_printout *p);

int	ft_isformat(int c);
int	ft_isflag(int c);
int	ft_parse_flags(t_printout *p);

int	ft_print_cs(t_printout *p);
int	ft_print_diu(t_printout *p);
int	ft_print_xp(t_printout *p);

int	ft_putstr(const char *str);
int	ft_count_digits(int n, int base);
int	ft_power(int base, int exponent);
int	ft_putnbr(int n, int base);

// percnt

int	main(void)
{
	int	i;

	ft_printf("char %c\n", '&');
	ft_printf("single %%\n");
	ft_printf("string %s\n", "hey there");
	ft_printf("decimal %d\n", 69);
	ft_printf("integer %i\n", 69);
	ft_printf("pointer %p\n", 69);
	ft_printf("unsigned %p\n", 69);
	ft_printf("hexadecimal %x\n", 69);
	ft_printf("uppercase hex %X\n", 69);
	ft_printf("--\n");
	i = 0;
	ft_printf("flag test #%d %.d\n", ++i, 69);
	ft_printf("flag test #%d %04s\n", ++i, "string");
	ft_printf("--\n");
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_printout	*p;

	p = (t_printout *) ft_calloc(1, sizeof(t_printout));
	if (p == NULL)
		return (-1);
	p->format = (char *) format;
	p->nb_written = 0;
	va_start(p->varg, format);
	while (*(p->format) != '\0' && p->nb_written >= 0)
	{
		if (*(p->format) == '%')
		{
			write(1, "\033[3;4m", 6);
			ft_print_format(p);
			write(1, "\033[0m", 4);
		}
		else
			ft_putchar_fd(*(p->format), 1);
		p->format++;
	}
	va_end(p->varg);
	free(p);
	return (0);
}

int	ft_print_format(t_printout *p)
{
	int		(*pf)(t_printout *p);

	pf = NULL;
	p->format++;
	p->n_flags = 0;
	if (ft_isflag(*(p->format)))
		ft_parse_flags(p);
	p->format += p->n_flags;
	if (ft_isformat(*(p->format)))
		pf = ft_which_format(*(p->format));
	if (pf != NULL)
		pf(p);
	//p->format++;
	return (0);
}

int	(*ft_which_format(char c))(t_printout *p)
{
	if (c == '%' || c == 'c' || c == 's')
		return (ft_print_cs);
	else if (c == 'p' || c == 'x' || c == 'X')
		return (ft_print_cs);
	else if (c == 'd' || c == 'i' || c == 'u')
		return (ft_print_diu);
	return (0);
}

int	ft_parse_flags(t_printout *p)
{
	char	c;

	p->n_flags = 0;
	c = *(p->format);
	if (c == '%')
		write(1, &c, 1);
	else
		write(1, &c, 1);
	return (p->n_flags);
}

int	ft_putnbr(int n, int base)
{
	long int	nn;
	int			n_digits;
	int			c;

	nn = (long int) n;
	n_digits = ft_count_digits(n, base);
	if (n < 0)
	{
		write(1, "-", 1);
		nn *= -1;
	}
	while (n_digits > 0)
	{
		c = nn / (ft_power(base, n_digits - 1));
		nn = nn - c * (ft_power(base, n_digits - 1));
		c += '0';
		write(1, &c, 1);
		n_digits--;
	}
	return (0);
}

int	ft_count_digits(int n, int base)
{
	int	n_digits;
	int	nn;

	n_digits = 0;
	nn = n;
	if (n < 0)
		nn *= -1;
	else if (n == 0)
		return (1);
	while (nn > 0)
	{
		nn /= base;
		n_digits++;
	}
	return (n_digits);
}

int	ft_power(int base, int exponent)
{
	int	pow;

	if (exponent == 0)
		return (1);
	pow = base;
	while (--exponent > 0)
		pow *= base;
	return (pow);
}

int	ft_print_cs(t_printout *p)
{
	char	f;
	char	*s;
	int		c;

	s = NULL;
	f = *(p->format);
	if (f == '%')
		write(1, &f, 1);
	else if (f == 'c')
	{
		c = va_arg(p->varg, int);
		write(1, &c, 1);
	}
	else if (f == 's')
	{
		s = va_arg(p->varg, char *);
		ft_putstr(s);
	}
	return (0);
}

int	ft_print_diu(t_printout *p)
{
	char		f;
	int			di;
	unsigned	u;

	f = *(p->format);
	if (f == 'd' || f == 'i')
	{
		di = va_arg(p->varg, int);
		ft_putnbr(di, 10);
	}
	else if (f == 'u')
	{
		u = va_arg(p->varg, unsigned);
		ft_putnbr(u, 10);
	}
	return (0);
}

int	ft_print_xp(t_printout *p)
{
	write(1, (p->format + 1), 1);
	return (0);
}

int	ft_isformat(int c)
{
	int	(*pf)(int);

	pf = ft_isflag;
	(void) pf;
	if (ft_strchr(FORMATS, c) != NULL)
		return (1);
	return (0);
}

int	ft_isflag(int c)
{
	if (ft_strchr(FLAGS, c) != NULL)
		return (1);
	return (0);
}

int	ft_putstr(const char *str)
{
	char	*string;
	int		n_written;
	int		return_value;

	string = (char *) str;
	n_written = 0;
	return_value = 0;
	while (*string != '\0')
	{
		return_value = write(1, string, 1);
		if (return_value < 0)
			break ;
		else
			n_written += return_value;
		string++;
	}
	return (n_written);
}
