/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:06:00 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/06 14:26:38 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_chars_until_format(const char *s)
{
	int	i;

	i = 0;
	while (ft_strchr(FORMATS, s[i]) == 0)
		i++;
	return (i);
}

void	ft_manage_flags(t_printout *p)
{
	const char	*s = p->format;
	int			chars_until_format;

	ft_dump_flags(p);
	chars_until_format = ft_chars_until_format(s);
	p->format += chars_until_format;
	while (chars_until_format--)
	{
		if (*s == '#')
			p->flag_alternate_form = *s;
		if (*s == '+')
			p->flag_sign = *s;
		if (*s == ' ')
			p->flag_blank = *s;
		if (*s == '-' || *s == '0')
			p->flag_adjustment += *s;
		if (*s == '.')
			p->n_precision = 3;
		s++;
	}
}

void	ft_dump_flags(t_printout *p)
{
	p->flag_alternate_form = '\0';
	p->flag_sign = '\0';
	p->flag_blank = '\0';
	p->flag_adjustment = '\0';
	p->n_precision = -1;
}
