/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:49 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/18 16:26:51 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_formats(const char *s, va_list *v)
{
	unsigned int	counter;

	counter = 0;
	if (*s == 'c')
		counter += ft_putchar_fd(va_arg(*v, int), FD);
	else if (*s == 's')
		counter += ft_putstr_fd(va_arg(*v, char *), FD);
	else if (*s == 'p')
		counter += ft_illtohex(va_arg(*v, unsigned long long), *s, 16, FD);
	else if (*s == 'd' || *s == 'i')
		counter += ft_putnbr_fd(va_arg(*v, int), FD);
	else if (*s == 'u')
		counter += ft_putnbr_fd(va_arg(*v, unsigned int), FD);
	else if (*s == 'x' || *s == 'X')
		counter += ft_illtohex(va_arg(*v, unsigned int), *s, 16, FD);
	else if (*s == '%')
		counter += ft_putchar_fd('%', FD);
	return (counter);
}
