/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:34 by mpuig-ma          #+#    #+#             */
/*   Updated: 2024/03/04 17:31:16 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>		// va_start, va_arg, va_end
# include <stdio.h>			// FILE *

# include "ft_io.h"
# include "ft_stdlib.h"
# include "ft_math.h"

# include <sys/cdefs.h>

# if defined(__cplusplus)
__BEGIN_DECLS extern "C"
# else
__BEGIN_DECLS
# endif

typedef struct s_printout
{
	int		n_written;
}			t_printout;

int			ft_printf(const char *format, ...);
int			ft_fprintf(FILE *file, const char *format, ...);

__END_DECLS

#endif /* ft_printf_h */
