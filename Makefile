NAME		:= libftprintf.a
AUTHOR		?= mpuig-ma
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
RM			:= rm -f

SRC_DIR		:= src
OBJ_DIR		:= obj
SRC_FILES	:= io/ft_printf.c \
			   io/ft_put_utils.c \
			   math/ft_count_digits.c \
			   math/ft_pow.c \
			   stdlib/ft_hex.c

include 	./utils.mk

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	$(call msg_comp,Compiled,$(notdir $<))

SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))
DEPS		= $(addprefix $(OBJ_DIR)/, $(addsuffix .d, $(basename $(SRC_FILES))))

# $< The name of the first prerequisite.
# $@ The file name of the target of the rule.

.PHONY: all clean fclean re libft

all: $(NAME)

libft:
	@make -sC libft/
	@cp libft/libft.a $(NAME)

$(NAME)::
	$(call msg_ascii)

-include $(DEPS)
$(NAME):: libft $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	$(call msg_comp,Linked,$(NAME))

$(NAME)::
	$(call msg_end)

clean:
	@make fclean -sC libft/
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	$(MAKE)
