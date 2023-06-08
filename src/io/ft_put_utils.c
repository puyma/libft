/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:27:07 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/08 11:01:09 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "../math/ft_math.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, sizeof(c)));
}

int	ft_putnbr_fd(long long int n, int fd)
{
	int				counter;
	int				n_digits;
	int				sign;
	int				d;
	int				pow;

	counter = 0;
	sign = 1;
	n_digits = ft_count_digits(n, 10);
	if (n == 0)
		return (ft_putchar_fd(n + 48, fd));
	if (n < 0)
	{
		sign = -1;
		counter += ft_putchar_fd('-', fd);
	}
	while (--n_digits >= 0)
	{
		pow = ft_pow(10, n_digits);
		d = n / pow * sign;
		counter += ft_putchar_fd(d + 48, fd);
		n -= n / pow * pow;
	}
	return (counter);
}

int	ft_putnbr_u_fd(unsigned long long n, int fd)
{
	int				counter;
	int				n_digits;
	unsigned int	d;
	unsigned int	pow;

	counter = 0;
	n_digits = ft_count_digits_u(n, 10);
	if (n == 0)
		return (ft_putchar_fd(n + 48, fd));
	while (--n_digits >= 0)
	{
		pow = ft_pow(10, n_digits);
		d = n / pow;
		counter += ft_putchar_fd(d + 48, fd);
		n -= n / pow * pow;
	}
	return (counter);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	if (s == NULL)
		return (ft_putstr_fd("(null)", fd));
	while (*s)
		counter += ft_putchar_fd(*s++, fd);
	return (counter);
}

int	ft_puthex_fd(unsigned long long nn, int c_case, int fd)
{
	int	counter;

	counter = 0;
	if (nn <= 9)
		counter += ft_putnbr_fd(nn, fd);
	else
		counter += ft_putchar_fd(nn + c_case, fd);
	return (counter);
}
