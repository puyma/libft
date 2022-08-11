/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:29:32 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/06/13 12:35:07 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*new;
	void	*temp_content;

	mapped = NULL;
	while (lst != NULL)
	{
		temp_content = f(lst->content);
		new = ft_lstnew(temp_content);
		if (new == NULL)
		{
			free(temp_content);
			ft_lstclear(&mapped, del);
			break ;
		}
		ft_lstadd_back(&mapped, new);
		lst = lst->next;
	}
	return (mapped);
}
