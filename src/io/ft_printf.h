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
# include "../../libft/libft.h" // DIFFERS MAIN (path)
# include "../math/ft_math.h"

// In order to fullfill printf's bonus requirements, 
// the following headers may have been modified 
// as well as some of some of the files they refer to (.c)
//
// BE CAREFUL WHEN MERGING TO MAIN

# include "ft_io.h" // DIFFERS MAIN
# include "../stdlib/ft_stdlib.h" // DIFFERS MAIN

typedef struct s_printout
{
	va_list		args;
	int			n_written;
}				t_printout;

int	ft_printf(const char *format, ...);

#endif /* ft_printf_h */
