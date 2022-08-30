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

// possibility to merge alternate_form with blank_sign
static void	ft_flags_alternate_form(t_printout *p); // flag #
static void	ft_flags_blank_sign(t_printout *p); // flags space, +
static void	ft_flags_adjust(t_printout *p); // flags -, 0, .

void	ft_manage_flags(t_printout *p)
{
	int	chars_until_format;

	chars_until_format = 0;
	while (ft_strchr(FORMATS, p->format[chars_until_format]) == 0)
		chars_until_format++;
	ft_printf("chars until format: %d\n", chars_until_format);
	if (*(p->format) == '+' || *(p->format) == ' ')
		ft_flags_blank_sign(p);
	else if (*(p->format) == '#')
		ft_flags_alternate_form(p);
	else if (*(p->format) == '-' || *(p->format) == '0' || *(p->format) == '.')
		ft_flags_adjust(p);
	else
		write(1, "flags error\n", 12);
}

static void	ft_flags_alternate_form(t_printout *p)
{
	t_fptr	func;
	int		return_value;

	++p->format;
	return_value = 0;
	if (*(p->format) == 'x' || *(p->format) == 'X')
		return_value = ft_putstr("0x");
	func = ft_formats(p);
	func(&p->args, p, p->format);
	if (return_value == -1)
		p->n_written = -1;
	else
		p->n_written += return_value;
}

static void	ft_flags_blank_sign(t_printout *p)
{
	t_fptr	func;

	p->flag_numeric = *(p->format);
	if (ft_strchr(FORMATS, *(p->format + 1)) != 0)
	{
		++p->format;
		func = ft_formats(p);
		func(&p->args, p, p->format);
	}
}

static void	ft_flags_adjust(t_printout *p)
{
	t_fptr	func;

	(void) func;
	++p->format;
	if (*(p->format) == '+')
	{
		++p->format;
		write(1, "-", 1);
	}
	else if (*(p->format) == '0')
	{
		++p->format;
		write(1, "0", 1);
	}
	else if (*(p->format) == '.')
	{
		++p->format;
		write(1, "precision", 9);
	}
}
