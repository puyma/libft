/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:00:12 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/01/07 18:00:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flags(t_printout *p)
{
	char	c;

	p->n_flags = 0;
	c = *(p->format);
	if (c == '%')
	{
		write(1, &c, 1);
	}
	else
	{
		ft_printf("(flag: %c)", c);
		p->n_flags++;
	}
	return (p->n_flags);
}
