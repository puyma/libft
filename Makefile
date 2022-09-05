NAME		:= libftprintf.a
AUTHOR		?= mpuig-ma
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
RM			:= rm -f

SRC_DIR		:= src
BUILD_DIR	:= build
SRC_FILES	:= io/ft_formats.c \
			   io/ft_flags.c \
			   io/ft_printf.c \
			   io/ft_put_utils.c \
			   math/ft_count_digits.c \
			   math/ft_pow.c \
			   stdlib/ft_hex.c

# Color codes

NOCOLOR		:= \033[0m
GREEN		:= \033[0;32m
CYAN		:= \033[0;36m
YELLOW		:= \033[33m

# ASCII art
# font used is bigmoney-ne
#
# Had to duplicate each $ sign so as to escape them 
# from the GNU Make interpreter...

define msg_ascii
@echo "$(NOCOLOR)" 
@echo '                     /$$$$             /$$$$      /$$$$$$$$$$$$ '
@echo '                    |__/            | $$$$     /$$$$__  $$$$'
@echo '  /$$$$$$$$$$$$   /$$$$$$$$$$$$  /$$$$ /$$$$$$$$$$$$$$  /$$$$$$$$$$$$  | $$$$  \__/'
@echo ' /$$$$__  $$$$ /$$$$__  $$$$| $$$$| $$$$__  $$$$|_  $$$$_/  | $$$$$$$$    '
@echo '| $$$$  \ $$$$| $$$$  \__/| $$$$| $$$$  \ $$$$  | $$$$    | $$$$_/    '
@echo '| $$$$  | $$$$| $$$$      | $$$$| $$$$  | $$$$  | $$$$ /$$$$| $$$$      '
@echo '| $$$$$$$$$$$$$$/| $$$$      | $$$$| $$$$  | $$$$  |  $$$$$$$$/| $$$$      '
@echo '| $$$$____/ |__/      |__/|__/  |__/   \___/  |__/      '
@echo '| $$$$                                                  '
@echo '| $$$$                                                  '
@echo "|__/  by $(AUTHOR)"
@echo "$(NOCOLOR)"
endef

# Message after compiling

define msg_comp
@echo "$(GREEN)$1$(NOCOLOR) $2$(NOCOLOR)"
endef

# Bye message

define msg_end
@echo "$(GREEN)Done!$(NOCOLOR)"
endef

# .o to .c rule

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	$(call msg_comp,Compiled,$(notdir $<))

SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))
DEPS		= $(addprefix $(BUILD_DIR)/, $(addsuffix .d, $(basename $(SRC_FILES))))

# $< The name of the first prerequisite.
# $@ The file name of the target of the rule.

.PHONY: all clean fclean re bonus

all: $(NAME)

#$(NAME)::
#	$(call msg_ascii)

-include $(DEPS)

$(NAME):: libft
	@make -sC libft/
	@cp -p libft/libft.a $(NAME)

$(NAME):: $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	$(call msg_comp,Linked,$(NAME))

$(NAME)::
	$(call msg_end)

#bonus: all

clean:
	@make fclean -sC libft/
	@$(RM) -rf $(BUILD_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) a.out

re: fclean
	$(MAKE)

run: $(NAME)
	@$(CC) main.c $(NAME) && ./a.out
