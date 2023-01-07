/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:07:46 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/01/07 17:07:46 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_diu(t_printout *p)
{
	char	f;

	f = *(p->format);
	if (f == 'd' || f == 'i')
	{
		p->data.d = va_arg(p->ap, int);
		p->out = ft_itoa_base(p->data.d, 10);
		ft_print(p->out);
	}
	else if (f == 'u')
	{
		p->data.u = va_arg(p->ap, unsigned int);
		p->out = ft_itoa_base((long int) p->data.u, 10);
		ft_print(p->out);
	}
	return (0);
}

int	ft_print_cs(t_printout *p)
{
	char	f;

	f = *(p->format);
	if (f == '%')
		write(1, &f, 1);
	else if (f == 'c')
	{
		p->data.c = va_arg(p->ap, int);
		write(1, &p->data.c, 1);
	}
	else if (f == 's')
	{
		p->data.s = va_arg(p->ap, char *);
		p->out = p->data.s;
		ft_print(p->out);
	}
	return (0);
}

int	ft_print_xp(t_printout *p)
{
	unsigned int	u;
	char			*s;

	u = va_arg(p->ap, unsigned int);
	s = ft_itoa_base((long int) u, 16);
	ft_print(s);
	return (0);
}
