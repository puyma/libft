/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:27:07 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/18 16:27:09 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "../math/math.h"

int	ft_putchar(char c)
{
	if (write(1, &c, sizeof(c)) != -1)
		return (1);
	return (0);
}

int	ft_putnbr(long long int n)
{
	int				counter;
	int				n_digits;
	int				sign;
	int				d;
	int				pow;

	(void) d;
	counter = 0;
	sign = 1;
	n_digits = ft_count_digits(n, 10);
	if (n == 0)
		return (ft_putchar(n + 48));
	if (n < 0)
	{
		sign = -1;
		counter += ft_putchar('-');
	}
	while (--n_digits >= 0)
	{
		pow = ft_pow(10, n_digits);
		d = n / pow * sign;
		counter += ft_putchar(d + 48);
		n -= n / pow * pow;
	}
	return (counter);
}

int	ft_putnbr_u(unsigned long long n)
{
	int				counter;
	unsigned int	n_digits;
	unsigned int	sign;
	unsigned int	d;
	unsigned int	pow;

	(void) d;
	counter = 0;
	sign = 1;
	n_digits = ft_count_digits_u(n, 10);
	if (n == 0)
		return (ft_putchar(n + 48));
	if (n < 0)
	{
		sign = -1;
		counter += ft_putchar('-');
	}
	while (--n_digits >= 0)
	{
		pow = ft_pow(10, n_digits);
		d = n / pow * sign;
		counter += ft_putchar(d + 48);
		n -= n / pow * pow;
	}
	return (counter);
}

int	ft_putstr(char *s)
{
	int	counter;

	counter = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (*s)
		counter += ft_putchar(*s++);
	return (counter);
}

int	ft_puthex(unsigned long long nn, int c_case)
{
	int	counter;

	counter = 0;
	if (nn <= 9)
		counter += ft_putnbr(nn);
	else
		counter += ft_putchar(nn + c_case);
	return (counter);
}
