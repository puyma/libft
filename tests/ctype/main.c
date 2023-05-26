/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:02:01 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/05/26 12:44:06 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	c;

	if (argc != 2)
		return (0);
	c = *argv[1];
	printf ("c> %c (%d)", c, c);
	if (ft_isalnum(c))
		printf(", isalnum");
	if (ft_isalpha(c))
		printf(", isalpha");
	if (ft_isascii(c))
		printf(", isascii");
	if (ft_isblank(c))
		printf(", isblank");
	if (ft_iscntrl(c))
		printf(", iscntrl");
	if (ft_isdigit(c))
		printf(", isdigit");
	if (ft_isgraph(c))
		printf(", isgraph");
	if (ft_islower(c))
		printf(", islower");
	if (ft_isprint(c))
		printf(", isprint");
	if (ft_ispunct(c))
		printf(", ispunct");
	if (ft_isspace(c))
		printf(", isspace");
	if (ft_isupper(c))
		printf(", isupper");
	if (ft_isxdigit(c))
		printf(", isxdigit");
	return (0);
}
