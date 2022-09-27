/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:18:54 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/27 20:33:26 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** The isblank() function returns zero if the character tests false 
** and returns non-zero if the character tests true.
*/

#include "ft_ctype.h"

int	ft_isblank(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
