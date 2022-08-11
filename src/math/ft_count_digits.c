/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:25:34 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/18 16:25:39 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_count_digits(long long int n, int base)
{
	int	n_digits;

	n_digits = 0;
	while (n != 0)
	{
		n /= base;
		n_digits++;
	}
	return (n_digits);
}

int	ft_count_digits_u(unsigned long long n, unsigned int base)
{
	int	n_digits;

	n_digits = 0;
	while (n != 0)
	{
		n /= base;
		n_digits++;
	}
	return (n_digits);
}
