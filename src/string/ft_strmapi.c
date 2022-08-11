/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:56:23 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/05/21 18:12:50 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strmapi;
	unsigned int	i;

	strmapi = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (strmapi == NULL)
		return (0);
	ft_bzero(strmapi, ft_strlen(s) + 1);
	i = 0;
	while (s[i] != '\0')
	{
		strmapi[i] = f(i, s[i]);
		i++;
	}
	return (strmapi);
}
