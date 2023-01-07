/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:51:52 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/01/07 16:51:52 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define FORMATS "cspdiuxX"
# define FLAGS "%-0.# +"

typedef union u_data
{
	char				c;
	char				*s;
	int					d;
	unsigned int		u;
	long unsigned int	p;
}						t_data;

typedef struct s_printout
{
	va_list		ap;
	char		*format;
	int			nb_written;
	int			n_flags;
	t_data		data;
	char		*out;
}				t_printout;

typedef unsigned long int	t_ul;

int		ft_printf(const char *format, ...);
int		ft_isflag(int c);
int		ft_isformat(int c);
int		ft_print_cs(t_printout *p);
int		ft_print_diu(t_printout *p);
int		ft_print_xp(t_printout *p);
t_ul	ft_power(int base, int exponent);
int		ft_count_digits(long int n, int base);
int		ft_parse_flags(t_printout *p);
char	*ft_itoa_base(long int n, int base);
int		ft_print(const char *data);

#endif /* ft_printf.h */
