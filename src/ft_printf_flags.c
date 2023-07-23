/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/23 11:48:10 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flags(char *format, t_flags *flags);
static int	ft_flag_width(char *format, t_flags *flags);
static int	ft_flag_precision(char *format, t_flags *flags);

int	ft_set_flags(char *format, t_flags *flags)
{
	if (flags == NULL)
		return (EXIT_FAILURE);
	ft_flags(format, flags);
	ft_flag_width(format, flags);
	ft_flag_precision(format, flags);
	return (EXIT_SUCCESS);
}

static int	ft_flags(char *format, t_flags *flags)
{
	flags->padding = 0;
	flags->left_adjusted = 0;
	flags->sign = 0;
	flags->blank = 0;
	flags->alternate_form = 0;
	return (EXIT_SUCCESS);
}

static int	ft_flag_width(char *format, t_flags *flags)
{
	flags->width = 0;
	return (EXIT_SUCCESS);
}

static int	ft_flag_precision(char *format, t_flags *flags)
{
	flags->precision = 0;
	return (EXIT_SUCCESS);
}

char	*ft_parse_flags(char *format, t_flags *flags, char *arg_str)
{
	char	*parsed;

	if (flags->width > 0)
	{
		printf("width: %d\n", flags->width);
	}
	parsed = ft_strdup(arg_str);
	return (parsed);
}
