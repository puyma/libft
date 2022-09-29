/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:34:59 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/29 17:44:48 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ispunct() function tests for any printing character, except for 
** space (` ') or a character for which isalnum() is true.
** 
** Returns zero if the character tests falsee and returns non-zero if the
** character tests true. 
*/

#include "libft.h"

int	ft_ispunct(int c)
{
	if (ft_isprint(c) && !ft_isalnum(c))
		return (1);
	return (0);
}
