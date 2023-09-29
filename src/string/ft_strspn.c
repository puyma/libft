/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:06:57 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/21 12:14:17 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
 * Description:
 * The strspn() function calculates the length (in bytes) of the initial
 * segment of `s` which consists entirely of bytes in `accept`.
 *
 * Return value:
 * The strspn() function returns the numbers of bytes in the initial segment
 * of `s` which consist only of bytes from `accept`.
 *
 */

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	nbytes;

	nbytes = 0;
	while (s != NULL && *s != '\0')
	{
		if (ft_strchr(accept, *s) == NULL)
			break ;
		++nbytes;
		++s;
	}
	return (nbytes);
}
