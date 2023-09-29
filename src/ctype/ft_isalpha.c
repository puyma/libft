/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:02:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 20:55:49 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION 
** The isalpha() function tests for any character for which isupper(3) 
** or islower(3) is true.
** 
** RETURN VALUES
** The isalpha() function returns zero if the character tests false 
** and returns non-zero if the character tests true.
*/

/*
** 'a' =>	0141
** 'z' =>	0172
** 'A' =>	0101
** 'Z' =>	0132
*/

int	ft_isalpha(int c)
{
	if ((0141 <= c && c <= 0172) || (0101 <= c && c <= 0132))
		return (1);
	return (0);
}
