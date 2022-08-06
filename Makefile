# Variables

CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra
#INCLUDES		:= -I $(SRC_DIR)
RM				:= rm -rf

NAME			:= libft.a
SRC_DIR			:= src
BUILD_DIR		:= build

CTYPE_FILES		= ctype/ft_isalpha.c \
				  ctype/ft_isdigit.c \
				  ctype/ft_isalnum.c \
				  ctype/ft_isascii.c \
				  ctype/ft_isprint.c \
				  ctype/ft_isupper.c \
				  ctype/ft_islower.c \
				  ctype/ft_toupper.c \
				  ctype/ft_tolower.c

IO_FILES		= io/ft_putchar_fd.c \
				  io/ft_putstr_fd.c \
				  io/ft_putendl_fd.c \
				  io/ft_putnbr_fd.c

STDLIB_FILES	= stdlib/ft_atoi.c \
				  stdlib/ft_calloc.c \
				  stdlib/ft_itoa.c

STRING_FILES	= string/ft_memset.c \
				  string/ft_memcpy.c \
				  string/ft_memmove.c \
				  string/ft_memchr.c \
				  string/ft_memcmp.c \
				  string/ft_bzero.c \
				  string/ft_strlen.c \
				  string/ft_strlcpy.c \
				  string/ft_strlcat.c \
				  string/ft_strchr.c \
				  string/ft_strrchr.c \
				  string/ft_strncmp.c \
				  string/ft_strnstr.c \
				  string/ft_strdup.c \
				  string/ft_substr.c \
				  string/ft_strjoin.c \
				  string/ft_strtrim.c \
				  string/ft_split.c \
				  string/ft_strmapi.c \
				  string/ft_striteri.c

LST_FILES		= lst/ft_lstnew.c \
				  lst/ft_lstadd_front.c \
				  lst/ft_lstsize.c \
				  lst/ft_lstlast.c \
				  lst/ft_lstadd_back.c \
				  lst/ft_lstdelone.c \
				  lst/ft_lstclear.c \
				  lst/ft_lstiter.c \
				  lst/ft_lstmap.c

OBJS			= $(SRC_FILES:%.c=$(BUILD_DIR)/%.o)

.PHONY: all re fclean clean bonus

all: $(NAME)

SRC_FILES = $(CTYPE_FILES) $(IO_FILES) $(STDLIB_FILES) $(STRING_FILES)
$(NAME): $(OBJS)
	@echo "Linking $@"
	@ar -rcs $(NAME) $(OBJS)
	@echo "Done!"

bonus: SRC_FILES += $(CTYPE_FILES) $(IO_FILES) $(STDLIB_FILES) $(STRING_FILES) $(LST_FILES)
bonus: $(OBJS)
	@echo "Linking $@"
	@ar -rcs $(NAME) $(OBJS)
	@echo "Done!"

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	@$(RM) $(BUILD_DIR)

fclean: clean
	@$(RM) $(NAME)

fclear: fclean
	@clear

re: fclean
	$(MAKE)

# $@ The file name of the target of the rule.
# $< The name of the first prerequisite.
# $? The names of all the prerequisites that are newer than the target, with spaces between them. 
# $^ The names of all the prerequisites, with spaces between them.
#
# ‘$(@D)’ The directory part of the file name of the target, with the trailing slash removed.
# ‘$(@F)’ The file-within-directory part of the file name of the target.
# ‘$(^D)‘ ‘$(^F)’ Lists of the directory parts and the file-within-directory parts of all prerequisites.
