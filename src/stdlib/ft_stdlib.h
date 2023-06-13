/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlibft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:02:41 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/13 15:41:54 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include "../string/ft_string.h"
# include <stdlib.h> /* malloc */
# include <fcntl.h> /* open */
# include "../libft.h"

char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_illtohex_fd(unsigned long long n, int c_format, int base, int fd);

void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t size);

int		ft_setenv(const char *name, const char *value,
			int owr, const char **envp);
char	*ft_getenv(const char *name, const char **env);
int		ft_unsetenv(const char *name, char **envp);

char	*ft_which(const char *exec, char *path);

#endif /* ft_stdlib.h */
