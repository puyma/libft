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

NAME			:= libft.a
AUTHOR			:= mpuig-ma
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

# Clean –also– with CLEAR;
# clears the terminal screen.

fclear: fclean
	@clear

rer: fclear
	$(MAKE)

# Special variables
#
# $@ 
# The file name of the target of the rule.
#
# $< 
# The name of the first prerequisite.
#
# $? 
# The names of all the prerequisites that are newer than the target, 
# with spaces between them. 
#
# $^ 
# The names of all the prerequisites, 
# with spaces between them.
#
# ‘$(@D)’ 
# The directory part of the file name of the target, 
# with the trailing slash removed.
#
# ‘$(@F)’ 
# The file-within-directory part of the file name of the target.
#
# ‘$(^D)‘ ‘$(^F)’ 
# Lists of the directory parts and the file-within-directory 
# parts of all prerequisites.
