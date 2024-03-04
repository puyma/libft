/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_publib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:16:48 by mpuig-ma          #+#    #+#             */
/*   Updated: 2024/03/04 17:31:23 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUBLIB_H
# define FT_PUBLIB_H

# include "ft_string.h"
# include <sys/cdefs.h>

# if defined(__cplusplus)
__BEGIN_DECLS extern "C"
# else
__BEGIN_DECLS
# endif

char	*ft_strrev(char *str);

__END_DECLS

#endif /* ft_publib.h */
