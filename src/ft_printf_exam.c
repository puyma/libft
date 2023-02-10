/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:36 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/02/10 11:42:41 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include <limits.h>
#include <stdio.h>

#define BASE "0123456789abcdef"

union u_data
{
	char			*s;
	int				i;
	unsigned int	u;
};

typedef struct s_printout
{
	char			*format;
	int				nb_written;
	va_list			varg;
	union u_data	data;
}					t_printout;

int					ft_printf(const char *format, ...);
int					ft_formats(t_printout *p);
int					ft_printstr(char *str, t_printout *p);
int					ft_putchar(int c);
int					ft_count_digits(int base, int num);
int					ft_count_digits_u(int base, unsigned int num);
long unsigned		ft_power(int base, int exponent);
char				*ft_itoa(int base, int n);
char				*ft_utoa(int base, unsigned int n);
void				*ft_calloc(int count, int size);

int	main(void)
{
	int	a;
	int	b;

	a = ft_printf("x: %x\n", -69);
	b = printf("x: %x\n", -69);
	printf("a: %d, b: %d\n", a, b);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_printout	p;

	p.nb_written = 0;
	p.format = (char *) format;
	va_start(p.varg, format);
	while (*p.format != '\0')
	{
		if (*p.format == '%')
			ft_formats(&p);
		else
			p.nb_written += ft_putchar(*p.format);
		p.format++;
	}
	va_end(p.varg);
	return (p.nb_written);
}

int	ft_formats(t_printout *p)
{
	p->format++;
	p->data.u = 0;
	if (*(p->format) == 's')
	{
		p->data.s = va_arg(p->varg, char *);
		ft_printstr(p->data.s, p);
	}
	else if (*(p->format) == 'd')
	{
		p->data.i = va_arg(p->varg, int);
		ft_printstr(ft_itoa(10, p->data.i), p);
	}
	else if (*(p->format) == 'x')
	{
		p->data.u = va_arg(p->varg, unsigned);
		ft_printstr(ft_utoa(16, p->data.u), p);
	}
	return (0);
}

char	*ft_itoa(int base, int n)
{
	char		*itoa;
	long int	nn;
	int			digits;

	itoa = NULL;
	nn = n;
	digits = ft_count_digits(base, n);
	if (n < 0)
		nn *= -1;
	return (itoa);
}

char	*ft_utoa(int base, unsigned int n)
{
	char				*utoa;
	int					digits;
	int					i;
	long unsigned		pow;
	int					c;

	utoa = NULL;
	digits = ft_count_digits_u(base, n);
	i = 0;
	utoa = ft_calloc((digits + 1), sizeof(char));
	while (utoa && digits > 0)
	{
		pow = ft_power(base, --digits);
		c = n / pow;
		n -= c * pow;
		if (base == 10)
			utoa[i++] = c + '0';
		else if (base == 16)
			utoa[i++] = BASE[c];
	}	
	return (utoa);
}

long unsigned	ft_power(int base, int exponent)
{
	long unsigned	power;

	power = base;
	if (exponent == 0)
		return (1);
	while (--exponent > 0)
	{
		power *= base;
	}
	return (power);
}

int	ft_count_digits(int base, int n)
{
	long int	nn;
	int			digits;

	nn = n;
	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		nn *= -1;
	while (nn > 0)
	{
		nn /= base;
		digits++;
	}
	return (digits);
}

int	ft_count_digits_u(int base, unsigned int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		digits++;
	}
	return (digits);
}

int	ft_printstr(char *str, t_printout *p)
{
	char	*s;

	s = str;
	if (s == NULL)
	{
		p->nb_written += write(1, "(null)", 6);
		return (p->nb_written);
	}
	while (s && *s != '\0')
	{
		p->nb_written += ft_putchar(*s);
		s++;
	}
	return (p->nb_written);
}

int	ft_putchar(int c)
{
	int	nb;

	nb = write(1, &c, 1);
	return (nb);
}

void	*ft_calloc(int count, int size)
{
	void	*calloc;
	char	*cllc;

	calloc = NULL;
	calloc = (void *) malloc(size * count);
	if (calloc == NULL)
		return (NULL);
	cllc = (char *) calloc;
	while (count >= 0)
	{
		cllc[count] = '\0';
		count--;
	}
	return (calloc);
}
