/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:10:45 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 20:44:54 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The islower() function tests for any lower-case letters.
**
** RETURN VALUES
** The islower() function returns zero if the character tests false and returns
** non-zero if the character tests true.
*/

/*
** 'a' => 	0141
** 'z' =>	0172
*/

int	ft_islower(int c)
{
	if (0141 <= c && c <= 0172)
		return (1);
	return (0);
}
