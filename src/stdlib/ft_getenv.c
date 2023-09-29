/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:11:07 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/07 16:57:00 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

char	*ft_getenv(const char *name, const char **env)
{
	char	*variable;
	size_t	variable_len;
	int		i;

	i = 0;
	variable = ft_strjoin(name, "=");
	variable_len = ft_strlen(variable);
	while (env != NULL && env[i] != NULL)
	{
		if (ft_strncmp(env[i], variable, variable_len) == 0)
		{
			free(variable);
			return ((char *) env[i] + variable_len);
		}
		++i;
	}
	free(variable);
	variable = NULL;
	return (variable);
}
