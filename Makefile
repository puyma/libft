# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 19:08:59 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/06/05 15:09:02 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE			:=	make --no-print-directory
NAME			:=	libft.a
AUTHOR			?=	mpuig-ma

CC				:=	gcc
CFLAGS			:=	-Wall -Werror -Wextra -MMD
RM				:=	rm -rf
SRC_DIR			:=	src
BUILD_DIR		:=	build

# SRC_FILES

include			$(SRC_DIR)/sources.mk

NOSTYLE			:=	\033[0m
GREEN			:=	\033[0;32m
BOLD_CYAN		:=	\033[1;36m

define message =
@printf "$(BOLD_CYAN)%-20s: $(GREEN)%s$(NOSTYLE)\n" "$(1)" "$(2)"
endef

OBJS	= $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))
DEPS	= $(addprefix $(BUILD_DIR)/, $(addsuffix .d, $(basename $(SRC_FILES))))

.PHONY: libft all clean fclean re

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(@D)
	$(call message,"compiling",$<)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
# https://unix.stackexchange.com/questions/347032/makefile-looping-files-with-pattern

libft: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	$(call message,linked,$(NAME))

clean:
	@$(RM) $(BUILD_DIR)/
	$(call message,libft,clean)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE)
