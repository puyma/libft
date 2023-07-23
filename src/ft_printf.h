/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:00:36 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/22 20:00:36 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>/*rm if possible ?*/

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS				0
# endif

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE				1
# endif

# ifndef STDOUT_FILENO
#  define STDOUT_FILENO				1
# endif

# ifndef STDERR_FILENO
#  define STDERR_FILENO				2
# endif

# define FT_PRINTF_TYPE_MODIFIERS	"cspdiuxX"
# define FT_PRINTF_FLAGS			"-0# +"//.

typedef struct s_flags {
	int		precision;
	int		padding;
	int		left_adjusted;
	int		sign;
	int		blank;
	int		alternate_form;
	int		width;
	int		c_padding;
}			t_flags;

/*
 * ft_printf();
 * % [ param-no $] flags width [ . precision ] type conversion
 *
 */

int		ft_printf(const char *format, ...)
		__attribute__((__format__(__printf__, 1, 2)));
int		ft_fprintf(FILE *file, const char *format, ...)
		__attribute__((__format__(__printf__, 2, 3)));

/* ft_printf_loop.c */

int		ft_printf_loop(const char *format, va_list *vargs, int *nb, int fd);

/* ft_printf_flags.c */

int		ft_set_flags(char *format_substr, t_flags *flags);
char	*ft_parse_flags(char *format, t_flags *flags, char *arg_str);

/* ft_printf_formats.c */

char	*ft_getformat(char *format);
char	*ft_gettypemodifier(char *format);

/* ft_p_utils.c */

int		ft_p_putchar_fd(int c, int fd);
int		ft_p_putstr_fd(char *s, int fd);

/* ft_printf_utils.c */

char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strndup(const char *s1, size_t n);

#endif /* ft_printf.h */
