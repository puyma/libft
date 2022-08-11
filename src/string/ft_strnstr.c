/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:24:00 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/05/11 20:47:27 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *) haystack);
	else if (*haystack == '\0')
		return (0);
	else if (len < ft_strlen(needle))
		return (0);
	j = 0;
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (haystack[i] == needle[i] && needle[i] && (j + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char *) haystack);
		}
		j++;
		haystack++;
	}
	return (0);
}
