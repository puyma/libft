/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:45:17 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/29 18:41:18 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isxdigit() function tests for any hexadecimal-digit character. Regardless
** of locale, this includes the following characters only: 0-9, A-F, a-f. 
*/

#include "ft_ctype.h"

int	ft_isxdigit(int c)
{
	if (ft_isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'))
		return (1);
	return (0);
}
