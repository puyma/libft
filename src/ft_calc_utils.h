/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:25:48 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/18 16:25:50 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CALC_UTILS_H
# define FT_CALC_UTILS_H

long long int		ft_pow(int n, int exponent);
unsigned long long	ft_pow_u(unsigned long long n, int exponent);
int					ft_count_digits(long long int n, int base);
int					ft_count_digits_u(unsigned long long n, unsigned int base);

#endif /* ft_calc_utils.h */
