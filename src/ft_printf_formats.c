/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:55:02 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/23 11:55:02 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getformat(char *format)
{
	size_t	len;
	char	*fsubstr;

	len = 0;
	fsubstr = ++format;
	while (fsubstr != NULL && *fsubstr != '\0'
		&& ft_strchr(FT_PRINTF_FLAGS, *fsubstr) != NULL)
	{
		++fsubstr;
		++len;
	}
	while (fsubstr != NULL && *fsubstr != '\0' && ft_isdigit(*fsubstr) != 0)
	{
		++fsubstr;
		++len;
	}
	if (fsubstr != NULL && *fsubstr != '\0'
		&& ft_strchr(FT_PRINTF_TYPE_MODIFIERS, *fsubstr) != NULL)
		++len;
	fsubstr = ft_strndup(format, len);
	return (fsubstr);
}

char	*ft_gettypemodifier(char *format)
{
	while (format != NULL && *format != '\0'
		&& ft_strchr(FT_PRINTF_FLAGS, *format) != NULL)
		++format;
	while (*format != '\0' && ft_isdigit(*format) != 0)
		++format;
	if (*format == '.')
	{
		++format;
		while (*format != '\0' && ft_isdigit(*format) != 0)
			++format;
	}
	return (format);
}
