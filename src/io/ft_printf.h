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
# include "../libft.h"
# include "ft_io.h"
# include "../stdlib/ft_stdlib.h"
# include "../math/ft_math.h"

typedef struct s_printout
{
	int	n_written;
}		t_printout;

int	ft_printf(const char *format, ...);

#endif /* ft_printf_h */