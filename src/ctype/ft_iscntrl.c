/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:25:38 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/29 18:06:35 by mpuig-ma         ###   ########.fr       */
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
	if ((0 <= c && c <= 31) || c == 177)
		return (1);
	return (0);
}
