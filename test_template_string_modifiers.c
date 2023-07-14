/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_template_string_modifiers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:23:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/13 18:28:26 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

/*
 * ft_printf();
 * % [ param-no $] flags width [ . precision ] type conversion
 *
 */

#define FT_PRINTF_TYPE_MODIFIERS "cspdiuxX"
#define FT_PRINTF_FLAGS	"-0.# +"

int	ft_format(char *format);

int	main(int argc, char **argv)
{
	char	*format;

	if (argc != 2)
		return (2);
	format = argv[1];
	while (format != NULL && *format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0' && *(format + 1) == '%')
		{
			write(STDOUT_FILENO, format + 1, 1);
			format++;
		}
		else if (*format == '%')
			format = format + ft_format(format);
		else
		{
			write(STDOUT_FILENO, format, 1);
		}
		++format;
	}
	return (0);
}

int	ft_format(char *format)
{
	int	nbytes;
	char	*ptr;

	nbytes = 0;
	(void) nbytes;
	ptr = format;
	++format;
	while (*format != '\0' && strchr(FT_PRINTF_FLAGS, *format) != NULL)
	{
		printf("Flag found: %c\n", *format);
		++format;
	}
	while (*format != '\0' && isdigit(*format) != 0)
	{
		printf("(width) Digit Found\n");
		++format;
	}
	if (*format != '\0' && *format == '.')
	{
		printf("Found precision flag\n");
		++format;
		while (*format != '\0' && isdigit(*format) != 0)
		{
			printf("Found precision digit\n");
			++format;
		}
	}
	if (*format != '\0' && strchr(FT_PRINTF_TYPE_MODIFIERS, *format) != NULL)
		printf("Type mod: %c\n", *format);
	else
		printf("Not valid\n");
	return (format - ptr);
}
