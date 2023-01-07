/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:27:26 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/01/07 16:27:26 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...);
static int	ft_print_format(t_printout *p);

int	ft_printf(const char *format, ...)
{
	t_printout	*p;

	p = (t_printout *) ft_calloc(1, sizeof(t_printout));
	if (p == NULL)
		return (-1);
	p->format = (char *) format;
	p->nb_written = 0;
	va_start(p->ap, format);
	while (*(p->format) != '\0' && p->nb_written >= 0)
	{
		if (*(p->format) == '%')
		{
			write(1, "\033[3;4m", 6);
			ft_print_format(p);
			write(1, "\033[0m", 4);
		}
		else
			ft_putchar_fd(*(p->format), 1);
		p->format++;
	}
	va_end(p->ap);
	free(p);
	return (p->nb_written);
}

// pf stands for pointer (to) function

static int	ft_print_format(t_printout *p)
{
	char	f;

	p->format++;
	p->n_flags = 0;
	if (ft_strchr(FLAGS, *(p->format)) != NULL)
		ft_parse_flags(p);
	p->format += p->n_flags;
	f = *(p->format);
	if (ft_strchr(FORMATS, *(p->format)) != NULL)
	{
		if (f == '%' || f == 'c' || f == 's')
			ft_print_cs(p);
		else if (f == 'd' || f == 'i' || f == 'u')
			ft_print_diu(p);
		else if (f == 'x' || f == 'X' || f == 'p')
			ft_print_xp(p);
	}
	return (0);
}

int	ft_print(const char *data)
{
	char	*string;
	int		n_written;
	int		return_value;

	string = (char *) data;
	n_written = 0;
	return_value = 0;
	while (*string != '\0')
	{
		return_value = write(1, string, 1);
		if (return_value < 0)
			break ;
		else
			n_written += return_value;
		string++;
	}
	return (n_written);
}
