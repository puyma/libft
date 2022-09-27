# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 19:18:56 by mpuig-ma          #+#    #+#              #
#    Updated: 2022/09/27 19:34:17 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CTYPE_FILES		= ctype/ft_isalnum.c \
				  ctype/ft_isalpha.c \
				  ctype/ft_isascii.c \
				  ctype/ft_isdigit.c \
				  ctype/ft_islower.c \
				  ctype/ft_isprint.c \
				  ctype/ft_isupper.c \
				  ctype/ft_tolower.c \
				  ctype/ft_toupper.c

IO_FILES		= io/ft_printf.c \
				  io/ft_put_utils.c \
				  io/ft_putchar_fd.c \
				  io/ft_putendl_fd.c \
				  io/ft_putnbr_fd.c \
				  io/ft_putstr_fd.c

LST_FILES		= lst/ft_lstadd_back.c \
				  lst/ft_lstadd_front.c \
				  lst/ft_lstclear.c \
				  lst/ft_lstdelone.c \
				  lst/ft_lstiter.c \
				  lst/ft_lstlast.c \
				  lst/ft_lstmap.c \
				  lst/ft_lstnew.c \
				  lst/ft_lstsize.c

MATH_FILES		= math/ft_count_digits.c \
				  math/ft_pow.c

STDLIB_FILES	= stdlib/ft_atoi.c \
				  stdlib/ft_calloc.c \
				  stdlib/ft_hex.c \
				  stdlib/ft_itoa.c

STRING_FILES	= string/ft_bzero.c \
				  string/ft_memchr.c \
				  string/ft_memcmp.c \
				  string/ft_memcpy.c \
				  string/ft_memmove.c \
				  string/ft_memset.c \
				  string/ft_split.c \
				  string/ft_strchr.c \
				  string/ft_strdup.c \
				  string/ft_striteri.c \
				  string/ft_strjoin.c \
				  string/ft_strlcat.c \
				  string/ft_strlcpy.c \
				  string/ft_strlen.c \
				  string/ft_strmapi.c \
				  string/ft_strncmp.c \
				  string/ft_strnstr.c \
				  string/ft_strrchr.c \
				  string/ft_strtrim.c \
				  string/ft_substr.c \
				  string/get_next_line.c

SRC_FILES		= $(CTYPE_FILES) \
				  $(IO_FILES) \
				  $(LST_FILES) \
				  $(MATH_FILES) \
				  $(STDLIB_FILES) \
				  $(STRING_FILES)
