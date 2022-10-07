/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:02:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/10/03 20:37:01 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** The isalpha() function tests for any character for which isupper(3) 
** or islower(3) is true.  The value of the argument must be representable as 
** an unsigned char or the value of EOF.
** 
** The isalpha() function returns zero if the character tests false 
** and returns non-zero if the character tests true.
*/

#include "ft_ctype.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}
