/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:25:48 by mpuig-ma          #+#    #+#             */
/*   Updated: 2024/03/04 13:06:38 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

__BEGIN_DECLS extern "C"

long long int		ft_pow(int n, int exponent);
unsigned long long	ft_pow_u(unsigned long long n, int exponent);
int					ft_count_digits(long long int n, int base);
int					ft_count_digits_u(unsigned long long n, unsigned int base);

__END_DECLS

#endif /* ft_math.h */
