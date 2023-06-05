/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:08:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/05 11:58:26 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	else if (s2 == 0)
		return (1);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else if ((unsigned char) s2[i] > (unsigned char) s1[i])
			return (-1);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	*s1 = "exit ";
	char	*s2 = NULL;

	printf("%d\n", ft_strcmp(s1, s2));
	return (0);
}
*/
