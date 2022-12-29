/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ensure_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:51:30 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/11/09 14:51:32 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ensure_print(t_printout *p, int func_return)
{
	if (func_return == -1)
		p->n_written = -1;
	else if (func_return >= 0)
		p->n_written += func_return;
}
