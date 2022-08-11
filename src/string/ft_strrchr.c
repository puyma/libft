/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:27:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/05/11 17:38:28 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int) ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) s + len);
	while (len >= 0)
	{
		if (*(s + len) == (char) c)
			return ((char *) s + len);
		len--;
	}
	return (0);
}
