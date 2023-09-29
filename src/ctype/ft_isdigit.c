/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:22:38 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 21:00:03 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The isdigit() function tests for a decimal digit character.
**
** The isnumber() function behaves similarly to isdigit(), but
** may recognize additional characters, depending on the current locale
** setting.
**
** RETURN VALUES
** The isdigit() and isnumber() functions return zero if the character
** tests false and return non-zero if the character tests true.
*/

/*
** '0' =>	060
** '9' =>	071
*/

int	ft_isdigit(int c)
{
	if (060 <= c && c <= 071)
		return (1);
	return (0);
}
