/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:32:37 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/12/28 11:32:37 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

#include <stdio.h>

#define FORMATS "cspdiuxX"
#define FLAGS "%-0.# +"

// pf stands for pointer (to) function

typedef struct s_printout
{
	va_list		varg;
	char		*format;
	int			nb_written;
}				t_printout;

int	ft_printf(const char *format, ...);
int	ft_print_format(t_printout *p);
int	(*ft_which_format(char c))(t_printout *p);
int	ft_isformat(int c);
int	ft_isflag(int c);
int	ft_parse_flags(t_printout *p);
int	ft_print_cs(t_printout *p);
int	ft_print_diu(t_printout *p);
int	ft_print_xp(t_printout *p);
int	ft_putstr(const char *str);

// percnt

int	main(void)
{
	ft_printf("char %c\n", '&');
	ft_printf("single %%\n");
	ft_printf("string %s\n", "string");
	ft_printf("decimal %d\n", 69);
	ft_printf("integer %i\n", 69);
	ft_printf("pointer %p\n", 69);
	ft_printf("unsigned %p\n", 69);
	ft_printf("hexadecimal %x\n", 69);
	ft_printf("uppercase hex %X\n", 69);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_printout	*p;

	p = (t_printout *) ft_calloc(1, sizeof(t_printout));
	if (p == NULL)
		return (-1);
	p->format = (char *) format;
	p->nb_written = 0;
	va_start(p->varg, format);
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
	va_end(p->varg);
	free(p);
	return (0);
}

int	ft_print_format(t_printout *p)
{
	int	(*pf)(t_printout *p);

	pf = NULL;
	if (*(p->format + 1) == '%' || *(p->format + 1) == 'c')
		pf = ft_print_cs;
	else if (ft_isformat(*(p->format + 1)))
		pf = ft_which_format(*(p->format + 1));
	else if (*(p->format) != '%')
		ft_parse_flags(p);
	if (pf != NULL)
		pf(p);
	p->format++;
	return (0);
}

int	(*ft_which_format(char c))(t_printout *p)
{
	if (c == '%' || c == 'c' || c == 's')
		return (ft_print_cs);
	else if (c == 'p' || c == 'x' || c == 'X')
		return (ft_print_cs);
	else if (c == 'd' || c == 'i' || c == 'u')
		return (ft_print_diu);
	return (0);
}

int	ft_print_cs(t_printout *p)
{
	write(1, (p->format + 1), 1);
	return (0);
}

int	ft_print_diu(t_printout *p)
{
	write(1, (p->format + 1), 1);
	return (0);
}

int	ft_print_xp(t_printout *p)
{
	write(1, (p->format + 1), 1);
	return (0);
}

int	ft_parse_flags(t_printout *p)
{
	(void) p;
	return (0);
}

int	ft_isformat(int c)
{
	int	(*pf)(int);

	pf = ft_isflag;
	(void) pf;
	if (ft_strchr(FORMATS, c) != NULL)
		return (1);
	return (0);
}

int	ft_isflag(int c)
{
	if (ft_strchr(FLAGS, c) != NULL)
		return (1);
	return (0);
}

int	ft_putstr(const char *str)
{
	char	*string;
	int		n_written;
	int		return_value;

	string = (char *) str;
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
	printf("ft_putstr> %d\n", n_written);
	return (n_written);
}
