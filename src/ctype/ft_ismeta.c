/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismeta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:13:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 21:35:14 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** As in GNU Bash Reference:
** metacharacter:
** A character that, when unquoted, separates words. 
** A metacharacter is a space, tab, newline, 
** or one of the following characters: 
** '|', '&', ';', '(', ')', '<', or '>'.
*/

/*
** HT	=>	011
** NL	=>	012
** SP	=>	040
** '&'	=>	046
** '('	=>	050
** ')'	=>	051
** ';'	=>	073
** '<'	=>	074
** '>'	=>	076
** '|'	=>	0174
*/

int	ft_ismeta(int c)
{
	if (c == 011 || c == 012
		|| c == 046 || c == 040
		|| c == 050 || c == 051
		|| c == 073 || c == 074 || c == 076
		|| c == 0174)
		return (1);
	return (0);
}
