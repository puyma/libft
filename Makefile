# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 19:08:59 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/10/02 16:44:29 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a
AUTHOR			?=	mpuig-ma

SRC_DIR			:=	src
BUILD_DIR		:=	build

AR				:=	ar
CC				:=	gcc
LD				:=	ld
LDFLAGS			:=	-L$(SRC_DIR)/libft -lft
LDFLAGS			+=	-L$(SRC_DIR)/libmlx -lmlx

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

$(NAME): $(LIB) $(OBJS)
	ar -crs $(NAME) $(OBJS)

debug:: CFLAGS += $(DFLAGS)
debug:: $(NAME)

clean:
	rm -r $(BUILD_DIR)

fclean: clean
	rm $(NAME)

re: fclean
	$(MAKE)

-include $(DEPS)
