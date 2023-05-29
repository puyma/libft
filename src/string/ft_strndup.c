/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:42:55 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/05/29 12:08:39 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*temp_dst;
	char	*temp_src;
	size_t	i;

	temp_dst = dst;
	temp_src = (char *) src;
	i = 0;
	while (*temp_src != '\0' && i++ < len)
		*temp_dst++ = *temp_src++;
	*temp_dst = '\0';
	return (dst);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, s1, n);
	str[n + 1] = '\0';
	return (str);
}
