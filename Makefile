# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 19:08:59 by mpuig-ma          #+#    #+#              #
#    Updated: 2022/09/27 19:39:58 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libft.a
AUTHOR			?= mpuig-ma

CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra -MMD
RM				:= rm -rf
SRC_DIR			:= src
BUILD_DIR		:= build

# SRC_FILES

include			$(SRC_DIR)/sources.mk

# Include other rules, mainly utilities. 
# before was > include ./utils.mk

# Color codes

NOCOLOR			:= \033[0m
GREEN			:= \033[0;32m

# msg function takes up to two arguments;
# the first is echoed in green. 

define msg
@echo "$(GREEN)$1$(NOCOLOR) $2$(NOCOLOR)"
endef

# .o to .c rule

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call msg,Compiled,$(notdir $<))

OBJS	= $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))
DEPS	= $(addprefix $(BUILD_DIR)/, $(addsuffix .d, $(basename $(SRC_FILES))))

# $< The name of the first prerequisite.
# $@ The file name of the target of the rule.
# Automatic variables
# <https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html>

# A phony target is one that is not really the name of a file; 
# rather it is just a name for a recipe to be executed.

.PHONY: all clean fclean re

all: $(NAME)

# This acts like include in every way 
# except that there is no error (not even a warning) 
# if any of the filenames (or any prerequisites 
# of any of the filenames) do not exist 
# or cannot be remade.

-include $(DEPS)

$(NAME):: $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	$(call msg,Linked,$@)

$(NAME)::
	$(call msg,Done!)

clean:
	@$(RM) $(BUILD_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	$(MAKE)
