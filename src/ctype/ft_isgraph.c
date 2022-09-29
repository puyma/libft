/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:40:40 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/29 18:40:26 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isgraph() function tests for any printing character except space (` ')
** and other locale-specific space-like characters. The value of the argument
** must be representable as an unsigned char or the value of EOF. 
** 
** The isgraph() function returns zero if the character tests false
** and returns non-zero if the character tests true.
*/

#include "ft_ctype.h"

int	ft_isgraph(int c)
{
	if ('!' <= c && c <= '~')
		return (1);
	return (0);
}
