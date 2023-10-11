/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:34:17 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/11 10:36:09 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = (void *) malloc(count * size);
	if (res == NULL)
		return (0);
	ft_bzero(res, count * size);
	return (res);
}
