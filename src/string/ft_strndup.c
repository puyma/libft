/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:42:55 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/08/11 19:20:45 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) malloc((sizeof(char) * n) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		str[i] = s1[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
