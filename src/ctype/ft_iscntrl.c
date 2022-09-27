/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:25:38 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/27 20:38:17 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** The iscntrl() function tests for any control character.
**
** ALSO (?)
** The value of the argument must be representable as an unsigned char
** or the value of EOF.
**
** The iscntrl() function returns zero if the character tests false 
** and returns non-zero if the character tests true.
*/

#include "ft_ctype.h"

int	ft_iscntrl(int c)
{
	// control characters (ASCII)> 0-7, 10-17, 20-27, 30-37, 177
	if ((0 <= c && c <= 7)
			|| (10 <= c && c <= 17)
			|| (20 <= c && c <= 27)
			|| (30 <= c && c <= 37)
			|| c == 177)
		return (1);
	return (0);
}
