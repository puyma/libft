# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 19:08:59 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/10/03 11:42:26 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a
AUTHOR			?=	mpuig-ma

SRC_DIR			:=	src
BUILD_DIR		:=	build

AR				:=	/usr/bin/ar
CC				:=	gcc

CFLAGS			:=	-Wall -Werror -Wextra
CPPFLAGS		:=	-MMD -O3 -iquote$(SRC_DIR)
DFLAGS			:=	-g -fsanitize='address,undefined'

# SRC_FILES

include			$(SRC_DIR)/sources.mk

OBJS	= $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(basename $(SRC_FILES))))
DEPS	= $(addprefix $(BUILD_DIR)/, $(addsuffix .d, $(basename $(SRC_FILES))))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all debug clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -crs $(NAME) $(OBJS)

debug:: CFLAGS += $(DFLAGS)
debug:: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

-include $(DEPS)
