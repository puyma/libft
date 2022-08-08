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

#include "ft_put_utils.h"
#include "ft_calc_utils.h"

static int	ft_set_case(int c_case)
{
	if (c_case != 'X')
		c_case = 'x';
	return (c_case - 23 - 10);
}

int	ft_illtohex(unsigned long long n, int c_format, int base, int fd)
{
	int					counter;
	int					c_case;
	unsigned int		n_digits;
	unsigned long long	pow;
	unsigned long long	nn;

	(void) pow;
	counter = 0;
	n_digits = ft_count_digits_u(n, base);
	if (c_format == 'p')
		counter += ft_putstr_fd("0x", fd);
	c_case = ft_set_case(c_format);
	while (--n_digits && n != 0)
	{
		nn = n / ft_pow_u(base, n_digits);
		counter += ft_puthex_fd(nn % base, c_case, fd);
	}
	counter += ft_puthex_fd(n % base, c_case, fd);
	return (counter);
}
