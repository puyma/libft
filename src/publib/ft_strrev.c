/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:18:16 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/21 13:27:25 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_publib.h"

char	*ft_strrev(char *str)
{
	char	temp;
	char	*start;
	char	*end;

	if (str == NULL)
		return (NULL);
	start = str;
	end = str + ft_strlen(str) - 1;
	while (start < end)
	{
		temp = *end;
		*end = *start;
		*start = temp;
		++start;
		--end;
	}
	return (str);
}
