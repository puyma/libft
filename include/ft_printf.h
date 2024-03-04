/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:34 by mpuig-ma          #+#    #+#             */
/*   Updated: 2024/03/04 13:06:56 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>		// va_start, va_arg, va_end
# include <stdio.h>			// FILE *

# include "ft_io.h"
# include "ft_stdlib.h"
# include "ft_math.h"

__BEGIN_DECLS extern "C"

typedef struct s_printout
{
	int		n_written;
}			t_printout;

int			ft_printf(const char *format, ...);
int			ft_fprintf(FILE *file, const char *format, ...);

__END_DECLS

#endif /* ft_printf_h */
