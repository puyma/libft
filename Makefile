NAME		:= libft.a
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
RM			:= rm -rf

SRC_DIR		:= src/
OBJ_DIR		:= obj/
SRC_FILES	:= ft_isalpha.c\
			   ft_isdigit.c\
			   ft_isalnum.c\
			   ft_isascii.c\
			   ft_isprint.c\
			   ft_strlen.c\
			   ft_memset.c\
			   ft_bzero.c\
			   ft_memcpy.c\
			   ft_memmove.c\
			   ft_strlcpy.c\
			   ft_strlcat.c\
			   ft_toupper.c\
			   ft_tolower.c\
			   ft_strchr.c\
			   ft_strrchr.c\
			   ft_strncmp.c\
			   ft_memchr.c\
			   ft_memcmp.c\
			   ft_strnstr.c\
			   ft_atoi.c\
			   ft_calloc.c\
			   ft_strdup.c\
			   ft_substr.c\
			   ft_strjoin.c\
			   ft_strtrim.c\
			   ft_split.c\
			   ft_itoa.c\
			   ft_strmapi.c\
			   ft_striteri.c\
			   ft_putchar_fd.c\
			   ft_putstr_fd.c\
			   ft_putendl_fd.c\
			   ft_putnbr_fd.c
BONUS_FILES	:= $(SRC_FILES)\
			   ft_lstnew.c\
			   ft_lstadd_front.c\
			   ft_lstsize.c\
			   ft_lstlast.c\
			   ft_lstadd_back.c\
			   ft_lstdelone.c\
			   ft_lstclear.c\
			   ft_lstiter.c\
			   ft_lstmap.c

INCLUDES	:= -I include/

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD $(INCLUDES) -c $< -o $@

OBJ			= $(SRC_FILES:%.c=$(OBJ_DIR)%.o)
OBJ_BONUS	= $(BONUS_FILES:%.c=$(OBJ_DIR)%.o)
DEPS		= $(addprefix $(OBJ_DIR), $(addsuffix .d, $(basename $(SRC_FILES))))
DEPS_BONUS	= $(addprefix $(OBJ_DIR), $(addsuffix .d, $(basename $(BONUS_FILES))))

.PHONY: all clean fclean re

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

-include $(DEPS_BONUS)
bonus: $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ_BONUS)
	touch bonus

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) bonus

fclean: clean
	@$(RM) $(NAME)

re: fclean
	$(MAKE)
