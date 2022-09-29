/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:51:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/29 18:40:47 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isspace() function tests for the white-space characters. 
** For any locale, this includes the following standard characters:
** ``\t''   ``\n''    ``\v''    ``\f''    ``\r''    `` ''
**
** The isspace() function returns zero if the character tests false 
** and returns non-zero if the character tests true.
*/

#include "ft_ctype.h"

int	ft_isspace(int c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (1);
	return (0);
}
