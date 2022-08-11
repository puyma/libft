/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:34:16 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/05/13 11:45:58 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// alternative, without using other functions
/*

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*src;

	src = s;
	while (n)
	{
		*src++ = '\0';
		--n;
	}
}

*/
