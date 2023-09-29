/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:04:05 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/09/29 21:21:13 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"

//void	ft_putchar_fd(char c, int fd);
//void	ft_putstr_fd(char *s, int fd);
//void	ft_putendl_fd(char *s, int fd);
//void	ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(long long int n, int fd);
int		ft_putnbr_u_fd(unsigned long long n, int fd);
int		ft_puthex_fd(unsigned long long nn, int c_case, int fd);
//int	ft_putchar(char c);
//int	ft_putnbr(long long int n);
//int	ft_putnbr_u(unsigned long long n);
//int	ft_putstr(char *s);
//int	ft_puthex(unsigned long long nn, int c_case);

#endif /* ft_io.h */
