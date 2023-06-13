/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:55:19 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/12 17:34:49 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	nbytes;

	nbytes = 0;
	nbytes += ft_putstr_fd(s, fd);
	nbytes += ft_putchar_fd(10, fd);
	return (nbytes);
}
