/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:48:41 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/06/13 09:58:28 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	next = lst->next;
	del(lst->content);
	if (next != NULL)
		lst->next = next;
	else
		free(lst);
}
