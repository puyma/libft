/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:26:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 20:55:24 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The isalnum() function tests for any character for which isalpha(3) 
** or isdigit(3) is true.
** 
** RETURN VALUES
** The isalnum() function returns zero if the character tests false 
** and returns non-zero if the character tests true.
*/

/*
** '0' =>	060
** '9' =>	071
** 'a' =>	0141
** 'z' =>	0172
** 'A' =>	0101
** 'Z' =>	0132
*/

int	ft_isalnum(int c)
{
	if (060 <= c && c <= 071)
		return (1);
	if (0141 <= c && c <= 0172)
		return (1);
	if (0101 <= c && c <= 0132)
		return (1);
	return (0);
}
