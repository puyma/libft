# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 19:08:59 by mpuig-ma          #+#    #+#              #
#    Updated: 2022/08/07 19:08:59 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables && (include) source files

NAME			:= libftprintf.a
AUTHOR			?= mpuig-ma
CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra
RM				:= rm -rf
SRC_DIR			:= src
BUILD_DIR		:= build
OBJS			= $(SRC_FILES:%.c=$(BUILD_DIR)/%.o)
include			$(SRC_DIR)/sources.mk 

# Include other rules,
# mainly utilities. 

include 		./utils.mk

# From The GNU Make Manual <https://www.gnu.org/software/make/manual/>
# last updated January 19, 2020.
#
# A phony target is one that is not really the name of a file; 
# rather it is just a name for a recipe to be executed.

.PHONY: all re fclean clean fclear rer

# Automatic variables
# <https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html>

all: $(NAME)

# Compilation

$(NAME)::
	$(call msg_ascii)

$(NAME):: $(OBJS)
	@echo "Linking $@"
	@ar -rcs $(NAME) $(OBJS)
	$(call msg_end)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean

clean:
	@$(RM) $(BUILD_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE)

# Clean –too– with CLEAR;
# clears the terminal screen.

fclear: fclean
	@clear

rer: fclear
	$(MAKE)
