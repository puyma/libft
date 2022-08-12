/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:25:59 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/18 16:26:00 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "../math/ft_math.h"
#include "../io/ft_io.h"

static int	ft_set_case(int c_case)
{
	if (c_case != 'X')
		c_case = 'x';
	return (c_case - 23 - 10);
}

int	ft_illtohex(unsigned long long n, int c_format, int base)
{
	int					counter;
	int					return_value;
	int					c_case;
	unsigned int		n_digits;
	unsigned long long	nn;

	counter = 0;
	n_digits = ft_count_digits_u(n, base);
	if (c_format == 'p')
	{
		return_value = ft_putstr("0x");
		if (return_value == -1)
			return (-1);
		counter += return_value;
	}
	c_case = ft_set_case(c_format);
	while (--n_digits && n != 0)
	{
		nn = n / ft_pow_u(base, n_digits);
		return_value = ft_puthex(nn % base, c_case);
		if (return_value == -1)
			return (-1);
		else
			counter += return_value;
	}
	return_value = ft_puthex(n % base, c_case);
	if (return_value == -1)
		return (-1);
	else
		counter += return_value;
	return (counter);
}
