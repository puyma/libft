/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:15:56 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/01/07 17:15:56 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_digits(long int n, int base)
{
	int			n_digits;
	long int	nn;

	n_digits = 0;
	nn = n;
	if (n < 0)
		nn *= -1;
	else if (n == 0)
		return (1);
	while (nn > 0)
	{
		nn /= base;
		n_digits++;
	}
	return (n_digits);
}
