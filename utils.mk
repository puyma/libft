# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    utils.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 19:43:00 by mpuig-ma          #+#    #+#              #
#    Updated: 2022/08/07 19:43:00 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
