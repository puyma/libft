/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:33:30 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/22 20:33:30 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_print_format_fd(char *format, va_list *vargs, int *nb, int fd);

int	ft_printf_loop(const char *format, va_list *vargs, int *nb, int fd)
{
	char		*format_substr;
	size_t		len;

	while (format != NULL && *format != '\0' && *nb >= 0)
	{
		if (*format == '%')
		{
			format_substr = ft_getformat((char *) format++);
			len = ft_strlen(format_substr);
			ft_print_format_fd((char *) format_substr, vargs, nb, fd);
			while (len-- > 0)
				++format;
			free(format_substr);
		}
		else
		{
			*(nb) = *(nb) + ft_p_putchar_fd(*format, fd);
			++format;
		}
	}
	return (EXIT_SUCCESS);
}

char	*ft_print_format_fd(char *format, va_list *vargs, int *nb, int fd)
{
	t_flags		flags;
	char		*parsed_str;
	char		*arg_str;

	if (*ft_gettypemodifier(format) == 's')
		arg_str = va_arg(*vargs, char *);
	if (arg_str != NULL)
	{
		ft_set_flags(format, &flags);
		parsed_str = ft_parse_flags(format, &flags, arg_str);
		*(nb) = *(nb) + ft_p_putstr_fd(parsed_str, fd);
		free(parsed_str);
	}
	return (NULL);
}
