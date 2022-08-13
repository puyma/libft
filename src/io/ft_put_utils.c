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

#include "ft_io.h"
#include "../math/ft_math.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	counter;

	counter = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (*s)
	{
		if (ft_putchar(*s++) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}

int	ft_putnbr(long long int n)
{
	int	n_digits;
	int	pow;
	int	sign;
	int	return_value;
	int	d;

	sign = 1;
	n_digits = ft_count_digits(n, 10);
	return_value = 0;
	if (n == 0)
		return (ft_putchar(n + 48));
	if (n < 0)
	{
		sign = -1;
		if (ft_putchar('-') == -1)
			return (-1);
		return_value++;
	}
	while (--n_digits >= 0)
	{
		pow = ft_pow(10, n_digits);
		d = n / pow * sign;
		if (ft_putchar(d + '0') == -1)
			return (-1);
		return_value++;
		n -= n / pow * pow;
	}
	return (return_value);
}

int	ft_putnbr_u(unsigned long long n)
{
	unsigned int	n_digits;
	unsigned int	pow;
	unsigned int	sign;
	unsigned int	d;
	int				return_value;

	sign = 1;
	n_digits = ft_count_digits_u(n, 10);
	return_value = 0;
	if (n == 0)
		return (ft_putchar(n + 48));
	if (n < 0)
	{
		sign = -1;
		if (ft_putchar('-') == -1)
			return (-1);
		return_value++;
	}
	while (--n_digits >= 0)
	{
		pow = ft_pow(10, n_digits);
		d = n / pow * sign;
		if (ft_putchar(d + 48) == -1)
			return (-1);
		return_value++;
		n -= n / pow * pow;
	}
	return (return_value);
}

int	ft_puthex(unsigned long long nn, int c_case)
{
	int	return_value;

	return_value = 0;
	if (nn <= 9)
		return_value = ft_putnbr(nn);
	else
		return_value = ft_putchar(nn + c_case);
	return (return_value);
}
