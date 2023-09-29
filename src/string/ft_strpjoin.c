/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:10:35 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/10 16:12:47 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
 * ft_strpjoin()
 * joins str s2 into position p of str s1
 *
 * if s1's length is smaller than p, s2 is appended like the
 * regular strjoin()
 *
 * if s1 is NULL,
 *
 * if s2 is NULL
 *
 */

char	*ft_strpjoin(char *s1, char *s2, size_t p)
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
		ft_strlcat(strpjoin, s1 + p, p + len_s2 + len_s1 + 1);
	return (strpjoin);
}
