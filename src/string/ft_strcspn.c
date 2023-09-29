/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:05:54 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/21 12:21:02 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
 * Description:
 * The strcspn() function calculates the length of the initial segment of
 * `s` which consists entirely of bytes not in `reject`.
 *
 * Return value:
 * The strcspn() function returns the numer of bytes in the initial segment
 * of `s` which are not in the string `reject`.
 *
 */

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	nbytes;

	nbytes = 0;
	while (s != NULL && *s != '\0')
	{
		if (ft_strchr(reject, *s) != NULL)
			break ;
		++nbytes;
		++s;
	}
	return (nbytes);
}
