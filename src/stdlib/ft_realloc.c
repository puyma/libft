/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:39:40 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/13 16:11:58 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*realloc_mem;

	realloc_mem = NULL;
	realloc_mem = malloc(size);
	if (realloc_mem == NULL)
		return (NULL);
	realloc_mem = ft_memcpy(realloc_mem, ptr, size);
	//realloc_mem = realloc(ptr, size);
	return (realloc_mem);
}
