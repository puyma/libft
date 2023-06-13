/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:39:40 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/13 20:47:31 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*realloc_mem;

	realloc_mem = malloc(new_size);
	if (realloc_mem == NULL)
		return (NULL);
	if (ptr == NULL)
		return (realloc_mem);
	ft_memcpy(realloc_mem, ptr, original_size);
	return (realloc_mem);
}
