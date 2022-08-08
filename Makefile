NAME		:= libftprintf.a
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
RM			:= rm -f

SRC_DIR		:= src
OBJ_DIR		:= obj
SRC_FILES	= ft_printf.c ft_printf_formats.c ft_hex.c ft_put_utils.c ft_str_utils.c ft_calc_utils.c

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -I ./ -c $< -o $@

SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))
DEPS		= $(addprefix $(OBJ_DIR)/, $(addsuffix .d, $(basename $(SRC_FILES))))

# $< The name of the first prerequisite.
# $@ The file name of the target of the rule.
#
.PHONY: all clean fclean re mk_libft

all: $(NAME)

mk_libft:
	@make -C libft/
	@cp libft/libft.a ../$(NAME)

-include $(DEPS)
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	$(MAKE)
