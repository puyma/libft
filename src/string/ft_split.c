/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:41:26 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/06/13 14:52:56 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	ft_getlen(const char *s, int start, char c)
{
	int	len;

	len = ft_strchr(s + start + 1, c) - (s + start) - 1;
	if (len < 0)
		len = ft_strlen(s);
	if (len == 0)
		len++;
	return (len);
}

static char	**ft_free(char **split, int n, int total)
{
	while (n < total)
		free(split[n++]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		start;
	int		wrd;

	wrd = ft_count_words(s, c);
	split = (char **) malloc(sizeof(char *) * (wrd + 1));
	if (split == NULL)
		return (NULL);
	start = ft_strlen(s) - 1;
	split[wrd--] = 0;
	while (start > 0 && s[start] == c)
		start--;
	while (wrd >= 0)
	{
		while (start >= 0 && (s[start] != c))
			start--;
		split[wrd] = ft_substr(s, start + 1, ft_getlen(s, start, c));
		if (split[wrd] == 0)
			return (ft_free(split, wrd + 1, ft_count_words(s, c)));
		wrd--;
		while (start >= 0 && s[start] == c)
			start--;
	}
	return (split);
}
