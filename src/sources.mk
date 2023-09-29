# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 19:18:56 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/09/29 21:45:13 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CTYPE_FILES		:=	ctype/ft_isalnum.c \
				 	ctype/ft_isalpha.c \
				 	ctype/ft_isascii.c \
				 	ctype/ft_isblank.c \
				 	ctype/ft_iscntrl.c \
				 	ctype/ft_isdigit.c \
				 	ctype/ft_isgraph.c \
				 	ctype/ft_islower.c \
				 	ctype/ft_isprint.c \
				 	ctype/ft_ispunct.c \
				 	ctype/ft_isspace.c \
				 	ctype/ft_isupper.c \
				 	ctype/ft_isxdigit.c \
				 	ctype/ft_tolower.c \
				 	ctype/ft_toupper.c \
					ctype/ft_ismeta.c

IO_FILES		:=	io/ft_printf.c \
					io/ft_fprintf.c \
				 	io/ft_put_utils.c \
					io/ft_putendl_fd.c
				 	#io/ft_putchar_fd.c
					#io/ft_putendl_fd.c
				 	#io/ft_putnbr_fd.c
					#io/ft_putstr_fd.c

LST_FILES		:=	lst/ft_lstadd_back.c \
				 	lst/ft_lstadd_front.c \
				 	lst/ft_lstclear.c \
				 	lst/ft_lstdelone.c \
				 	lst/ft_lstiter.c \
				 	lst/ft_lstlast.c \
				 	lst/ft_lstmap.c \
				 	lst/ft_lstnew.c \
				 	lst/ft_lstsize.c

MATH_FILES		:=	math/ft_count_digits.c \
				 	math/ft_pow.c

STDLIB_FILES	:=	stdlib/ft_atoi.c \
				 	stdlib/ft_calloc.c \
				 	stdlib/ft_hex.c \
				 	stdlib/ft_itoa.c \
				 	stdlib/ft_getenv.c \
					stdlib/ft_setenv.c \
					stdlib/ft_unsetenv.c \
					stdlib/ft_realpath.c \
					stdlib/ft_which.c

STRING_FILES	:= 	string/ft_bzero.c \
				 	string/ft_memchr.c \
				 	string/ft_memcmp.c \
				 	string/ft_memcpy.c \
				 	string/ft_memmove.c \
				 	string/ft_memset.c \
				 	string/ft_split.c \
				 	string/ft_strchr.c \
					string/ft_strcmp.c \
				 	string/ft_strdup.c \
				 	string/ft_strndup.c \
					string/ft_striteri.c \
					string/ft_strjoin.c \
					string/ft_strpjoin.c \
					string/ft_strpjoin_replace.c \
					string/ft_strlcat.c \
					string/ft_strlcpy.c \
				 	string/ft_strlen.c \
				 	string/ft_strmapi.c \
				 	string/ft_strncmp.c \
				 	string/ft_strnstr.c \
					string/ft_strrchr.c \
					string/ft_strtrim.c \
				 	string/ft_substr.c \
					string/ft_strspn.c \
					string/ft_strcspn.c \
					string/ft_strpbrk.c \
					string/ft_strrev.c \
					string/ft_free_arr.c \
					string/get_next_line.c

UNISTD_FILES	:=	unistd/ft_execvpe.c

PUBLIB_FILES	:=	publib/ft_strrev.c

SRC_FILES		= $(CTYPE_FILES) \
				  $(IO_FILES) \
				  $(LST_FILES) \
				  $(MATH_FILES) \
				  $(STDLIB_FILES) \
				  $(STRING_FILES) \
				  $(PUBLIB_FILES) \
				  $(UNISTD_FILES)
