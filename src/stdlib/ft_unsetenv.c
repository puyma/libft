/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:58:00 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/13 11:00:52 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static int	ft_swap(char **ptr1, char **ptr2);

int	ft_unsetenv(const char *name, char **envp)
{
	char	*var_name;
	int		i;
	int		len;

	var_name = ft_strjoin(name, "=");
	i = 0;
	len = 0;
	while (envp[len] != NULL)
	{
		if (ft_strncmp(envp[len], var_name, ft_strlen(var_name)) == 0)
			i = len;
		++len;
	}
	while (i < len - 1)
	{
		ft_swap(&envp[i], &envp[i + 1]);
		++i;
	}
	free(envp[i]);
	envp[i] = NULL;
	free(var_name);
	return (EXIT_SUCCESS);
}

static int	ft_swap(char **ptr1, char **ptr2)
{
	char	*temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
	return (EXIT_SUCCESS);
}
