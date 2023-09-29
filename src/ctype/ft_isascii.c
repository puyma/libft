/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:37:07 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 20:57:02 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The isascii() function tests for and ASCII character, which is any character
** between 0 and octal 0177 inclusive. 
*/

int	ft_isascii(int c)
{
	if (0 <= c && c <= 0177)
		return (1);
	return (0);
}
