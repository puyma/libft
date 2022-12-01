# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 19:08:59 by mpuig-ma          #+#    #+#              #
#    Updated: 2022/12/01 16:30:47 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a
AUTHOR			?=	mpuig-ma

CC				:=	gcc
CFLAGS			:=	-Wall -Werror -Wextra -MMD
RM				:=	rm -rf
SRC_DIR			:=	src
BUILD_DIR		:=	build

# SRC_FILES

include			$(SRC_DIR)/sources.mk

# Color codes
NOCOLOR			:= \033[0m
GREEN			:= \033[0;32m

OBJS	= $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))
DEPS	= $(addprefix $(BUILD_DIR)/, $(addsuffix .d, $(basename $(SRC_FILES))))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: libft all clean fclean re

libft: $(NAME)
all: $(NAME)
# https://unix.stackexchange.com/questions/347032/makefile-looping-files-with-pattern

-include $(DEPS)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "Linked $(GREEN)$(NAME)$(NOCOLOR)"

clean:
	$(RM) $(BUILD_DIR)/

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)
