/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:19:52 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/08/29 18:19:52 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_flags_alternate_form(t_printout *p); // flags #, space, +
static void	ft_flags_adjust(t_printout *p); // flags -, 0, .
static int	ft_chars_until_format(const char *s);

void	ft_manage_flags(t_printout *p)
{
	int	chars_until_format;

	chars_until_format = ft_chars_until_format(p->format);
	(void) chars_until_format;
	p->flag_alternate_form = '\0';
	if (ft_strchr("# +", *(p->format)) != 0)
		ft_flags_alternate_form(p);
	else if (ft_strchr("-0.", *(p->format)) != 0)
		ft_flags_adjust(p);
	else
		write(1, "flags error\n", 12);
}

static void	ft_flags_alternate_form(t_printout *p)
{
	t_fptr	func;
	int		chars_until_format;

	chars_until_format = ft_chars_until_format(p->format);
	p->flag_alternate_form = *(p->format);
	p->format += chars_until_format;
	func = ft_formats(p);
	if (func != NULL)
		func(&p->args, p, p->format);
}

static void	ft_flags_adjust(t_printout *p)
{
	int		chars_until_format;

	chars_until_format = ft_chars_until_format(p->format);
	p->flag_adjustment = *(p->format);
	p->format += chars_until_format;
	if (p->flag_adjustment == '-')
		write(1, "-", 1);
	else if (p->flag_adjustment == '0')
		write(1, "0", 1);
	else if (p->flag_adjustment == '.')
		write(1, "precision", 9);
	else
		write(1, "flaggs error", 12);
}

static int	ft_chars_until_format(const char *s)
{
	int	i;

	i = 0;
	while (ft_strchr(FORMATS, s[i]) == 0)
		i++;
	return (i);
}
