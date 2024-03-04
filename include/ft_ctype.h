/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:59:19 by mpuig-ma          #+#    #+#             */
/*   Updated: 2024/03/04 13:05:35 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

__BEGIN_DECLS extern "C"

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isupper(int c);
int	ft_islower(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);

int	ft_isblank(int c);
int	ft_iscntrl(int c);
int	ft_isgraph(int c);
int	ft_ispunct(int c);
int	ft_isspace(int c);
int	ft_isxdigit(int c);
int	ft_ismeta(int c);

__END_DECLS

#endif /* ft_ctype.h */
