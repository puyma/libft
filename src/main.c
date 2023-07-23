/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:55:28 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/22 20:55:28 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	og;
	int	ft;

	og = printf("og %4s\n", "hey");
	ft = ft_printf("ft %4s\n", "hey");
	printf("og: %d, ft: %d --\n", og, ft);
	return (0);
}
