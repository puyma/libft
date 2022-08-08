/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:27:16 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/18 16:27:24 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_UTILS_H
# define FT_PUT_UTILS_H

# include <unistd.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(long long int n, int fd);
int	ft_putnbr_fd_u(unsigned long long n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_puthex_fd(unsigned long long nn, int c_case, int fd);

#endif /* ft_put_utils_h */
