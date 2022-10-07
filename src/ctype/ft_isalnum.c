/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:26:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/10/03 20:34:57 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isalnum() function tests for any character for which isalpha(3) 
** or isdigit(3) is true.  The value of the argument must be representable 
** as an unsigned char or the value of EOF.
** 
** The isalnum() function returns zero if the character tests false 
** and returns non-zero if the character tests true.
*/

#include "ft_ctype.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
