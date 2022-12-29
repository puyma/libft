/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:06:00 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/09/08 21:58:36 by mpuig-ma         ###   ########.fr       */
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

static void	ft_set_precision(t_printout *p, int n_digits)
{
	char	*atoi;

	if (n_digits > 0 && p->flag_blank == '\0' && p->flag_adjustment == '\0')
		p->flag_adjustment = ' ';
	while (ft_isdigit(*(p->format)) == 0)
			p->format++;
	atoi = ft_substr(p->format, 0, n_digits);
	p->n_precision = ft_atoi(atoi);
	free(atoi);
}

void	ft_manage_flags(t_printout *p)
{
	const char	*s = p->format;
	int			chars_until_format;
	int			n_digits;

	n_digits = 0;
	chars_until_format = ft_chars_until_format(s);
	while (--chars_until_format >= 0)
	{
		if (*s == '#')
			p->flag_alt_form = *s;
		if (*s == '+')
			p->flag_sign = *s;
		if (*s == ' ')
			p->flag_blank = *s;
		if (*s == '-' || *s == '0' || *s == '.')
			p->flag_adjustment = *s;
		if (*s == ' ' || *s == '0')
			p->flag_padding_char = *s;
		if (ft_isdigit(*s))
			n_digits++;
		s++;
	}
	ft_set_precision(p, n_digits);
	p->format = s;
}

void	ft_dump_flags(t_printout *p)
{
	p->flag_sign = '\0';
	p->flag_blank = '\0';
	p->flag_alt_form = '\0';
	p->flag_adjustment = '\0';
	p->flag_padding_char = ' ';
	p->n_precision = -1;
}
