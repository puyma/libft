/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpjoin_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:07:35 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/11 12:07:46 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strpjoin_replace(char *s1, char *s2, size_t p)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*strpjoin;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (p > len_s1)
		p = len_s1;
	strpjoin = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (strpjoin == NULL)
		return (0);
	ft_bzero(strpjoin, len_s1 + len_s2 + 1);
	if (len_s1 > 0)
		ft_strlcat(strpjoin, s1, p + 1);
	ft_strlcat(strpjoin, s2, p + len_s2 + 1);
	if (len_s1 > 0)
		ft_strlcat(strpjoin, s1 + p + 1, p + len_s2 + len_s1 + 1);
	return (strpjoin);
}
