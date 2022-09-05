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

# define FORMATS "cspdiuxX%" /* conversion specifiers */
# define FLAGS "# +-0." /* flag characters */

typedef struct s_printout
{
	va_list		args;
	const char	*format;
	int			n_written;
	char		flag_alternate_form;
	char		flag_adjustment;
	int			n_precision;
}				t_printout;

typedef void	(*t_fptr)(va_list *v, t_printout *p, const char *s);

int		ft_printf(const char *format, ...);
t_fptr	ft_formats(const char *s);
void	ft_formats_cs(va_list *v, t_printout *p, const char *s);
void	ft_formats_du(va_list *v, t_printout *p, const char *s);
void	ft_formats_xp(va_list *v, t_printout *p, const char *s);
void	ft_manage_flags(t_printout *p);
void	ft_dump_flags(t_printout *p);
void	ft_ensure_print(t_printout *p, int func_return);

#endif /* ft_printf_h */
