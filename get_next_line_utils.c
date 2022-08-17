/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:36:27 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/07/28 19:35:35 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*cpy;

	cpy = s;
	while (len--)
		*cpy++ = c;
	return (s);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (dstsize <= len)
		return (ft_strlen(src) + dstsize);
	while (src[i] != '\0' && (i + len < dstsize - 1))
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	return (len + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strjoin = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (strjoin == NULL)
		return (0);
	ft_memset(strjoin, 0, len_s1 + len_s2 + 1);
	ft_strlcat(strjoin, s1, len_s1 + 1);
	ft_strlcat(strjoin, s2, len_s1 + len_s2 + 1);
	return (strjoin);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = (void *) malloc(count * size);
	if (res == NULL)
		return (0);
	ft_memset(res, 0, count * size);
	return (res);
}