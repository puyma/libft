/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:25:59 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/06 14:26:59 by mpuig-ma         ###   ########.fr       */
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

typedef struct s_nbr_obj {
	int					counter;
	int					return_value;
	int					c_case;
	unsigned int		n_digits;
	unsigned long long	nn;
}						t_nbr_obj;

int	ft_illtohex(unsigned long long n, int c_format, int base)
{
	t_nbr_obj	obj;

	obj.counter = 0;
	obj.n_digits = ft_count_digits_u(n, base);
	if (c_format == 'p')
	{
		obj.return_value = ft_putstr("0x");
		if (obj.return_value == -1)
			return (-1);
		obj.counter += obj.return_value;
	}
	obj.c_case = ft_set_case(c_format);
	while (--obj.n_digits && n != 0)
	{
		obj.nn = n / ft_pow_u(base, obj.n_digits);
		obj.return_value = ft_puthex(obj.nn % base, obj.c_case);
		if (obj.return_value == -1)
			return (-1);
		obj.counter += obj.return_value;
	}
	obj.return_value = ft_puthex(n % base, obj.c_case);
	if (obj.return_value == -1)
		return (-1);
	obj.counter += obj.return_value;
	return (obj.counter);
}
