/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:00:57 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/06/13 13:51:36 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	char	*temp_dst;
	char	*temp_src;

	temp_dst = dst;
	temp_src = (char *) src;
	while (*temp_src != '\0')
		*temp_dst++ = *temp_src++;
	*temp_dst = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*res;

	res = (char *) malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (res == NULL)
		return (0);
	ft_strcpy(res, s1);
	return (res);
}
