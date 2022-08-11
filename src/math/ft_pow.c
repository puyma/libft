/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:25:34 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/18 16:25:39 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

long long int	ft_pow(int n, int exponent)
{
	const int	pow = n;

	if (exponent == 0)
		return (1);
	while (--exponent > 0)
		n *= pow;
	return (n);
}

unsigned long long	ft_pow_u(unsigned long long n, int exponent)
{
	const unsigned pow = n;
	if (exponent == 0)
		return (1);
	while (--exponent > 0)
		n *= pow;
	return (n);
}
