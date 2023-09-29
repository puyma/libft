/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:02:23 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 21:23:38 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

/*
static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
*/

char	*ft_itoa(int n)
{
	char	*itoa;
	int		count_digits;

	count_digits = ft_count_digits(n, 10);
	if (n <= 0 && n != -2147483648)
		count_digits++;
	itoa = (char *) malloc(sizeof(char) * count_digits + 1);
	if (itoa == NULL)
		return (NULL);
	ft_bzero(itoa, count_digits + 1);
	if (n == -2147483648)
		ft_strlcpy(itoa, "-2147483648", 11 + 1);
	else if (n < 0)
	{
		itoa[0] = '-';
		n *= -1;
	}
	while (count_digits-- > 0 && itoa[count_digits] != '-' && n >= 0)
	{
		itoa[count_digits] = (n % 10) + 48;
		n /= 10;
	}
	return (itoa);
}
