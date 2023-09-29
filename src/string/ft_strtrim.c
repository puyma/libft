/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:08:58 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/05/21 17:32:41 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*strtrim;
	unsigned int	start;
	unsigned int	end;

	if (!*s1)
	{
		strtrim = (char *) malloc(sizeof(char));
		if (strtrim == NULL)
			return (0);
		*strtrim = '\0';
		return (strtrim);
	}
	start = 0;
	while (ft_strchr(set, s1[start]) && start < ft_strlen(s1))
		start++;
	end = ft_strlen(s1);
	while (ft_strrchr(set, s1[end]) && end)
		end--;
	strtrim = ft_substr(s1, start, (end - start) + 1);
	return (strtrim);
}
