/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:18:54 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 21:08:46 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION 
** The isblank() function returns zero if the character tests false 
** and returns non-zero if the character tests true.
**
** For any locale,
** this includes the following standard characters:
** ``\t''      `` ''
** In the "C" locale, a successful isblank() test is limited to these 
** characters only.
**
** RETURN VALUES
** The isblank() function returns zero if the character tests false and
** returns non-zero if the character tests true.
*/

/*
** ht (\t)	=>	011
** sp (  )	=>	040
*/

int	ft_isblank(int c)
{
	if (c == 011 || c == 040)
		return (1);
	return (0);
}
