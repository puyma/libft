/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:14:04 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/01/07 17:14:04 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long int	ft_power(int base, int exponent)
{
	int	pow;

	if (exponent == 0)
		return (1);
	pow = base;
	while (--exponent > 0)
		pow *= base;
	return (pow);
}
