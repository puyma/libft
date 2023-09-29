/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:41:52 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/21 12:57:43 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	char	*ptr;

	ptr = NULL;
	while (s != NULL && *s != '\0')
	{
		if (ft_strchr(accept, *s) != NULL)
		{
			ptr = (char *) s;
			break ;
		}
		++s;
	}
	return (ptr);
}
