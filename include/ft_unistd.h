/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:02:41 by mpuig-ma          #+#    #+#             */
/*   Updated: 2024/03/04 17:31:42 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNISTD_H
# define FT_UNISTD_H

# include <unistd.h>		// execve
# include <sys/cdefs.h>

# if defined(__cplusplus)
__BEGIN_DECLS extern "C"
# else
__BEGIN_DECLS
# endif

int	ft_execvpe(const char *cmd, char const *args[], char const *envp[]);

__END_DECLS

#endif /* ft_unistd.h */
