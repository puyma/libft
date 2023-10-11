/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:34 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/11 11:08:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>		// va_start, va_arg, va_end
# include <stdio.h>			// FILE *

# include "ft_io.h"
# include "ft_stdlib.h"
# include "ft_math.h"

typedef struct s_printout
{
	int		n_written;
}			t_printout;

int			ft_printf(const char *format, ...);
int			ft_fprintf(FILE *file, const char *format, ...);

#endif /* ft_printf_h */
