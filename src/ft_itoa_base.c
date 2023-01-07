/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:03:32 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/01/07 18:03:32 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_itoa_base(long int n, int base)
{
	long int	nn;
	char		*data;
	int			n_digits;
	int			c;
	int			i;

	i = 0;
	n_digits = ft_count_digits(n, base);
	data = ft_calloc(sizeof(char), n_digits + 1);
	nn = (long int) n;
	if (n < 0)
	{
		data[i++] = '-';
		nn *= -1;
	}
	while (i < n_digits || n_digits > 0)
	{
		c = nn / (ft_power(base, n_digits - 1));
		nn = nn - c * (ft_power(base, n_digits - 1));
		data[i++] = c + '0';
		n_digits--;
	}
	return (data);
}
