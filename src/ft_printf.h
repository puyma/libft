/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:34 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/18 16:26:35 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "ft_put_utils.h"
# include "ft_str_utils.h"
# include "ft_calc_utils.h"
# include "ft_printf_formats.h"
# include "ft_hex.h"

# define FD	1

int	ft_printf(const char *format, ...);
int	ft_print_formats(const char *s, va_list *v);
int	ft_illtohex(unsigned long long n, int c_case, int base, int fd);

#endif /* ft_printf_h */
