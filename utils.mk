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
PADDING		:= ' '
P			:= $(PADDING)

# ASCII art
# font used is bigmoney-ne
#
# Had to duplicate each $ sign
# so as to escape them from GNU Make...

define msg_ascii
@echo "$(CYAN)" 
@echo '$(P) /$$$$       /$$$$$$$$$$$$ /$$$$$$$$$$$$$$  /$$$$$$$$$$$$$$$$ /$$$$$$$$$$$$$$$$ '
@echo '$(P)| $$$$      |_  $$$$_/| $$$$__  $$$$| $$$$_____/|__  $$$$__/'
@echo '$(P)| $$$$        | $$$$  | $$$$  \ $$$$| $$$$         | $$$$   '
@echo '$(P)| $$$$        | $$$$  | $$$$$$$$$$$$$$ | $$$$$$$$$$      | $$$$   '
@echo '$(P)| $$$$        | $$$$  | $$$$__  $$$$| $$$$__/      | $$$$   '
@echo '$(P)| $$$$        | $$$$  | $$$$  \ $$$$| $$$$         | $$$$   '
@echo '$(P)| $$$$$$$$$$$$$$$$ /$$$$$$$$$$$$| $$$$$$$$$$$$$$/| $$$$         | $$$$   '
@echo '$(P)|________/|______/|_______/ |__/         |__/   '
@echo
@echo '$(P)------------------------------------------------'
@echo '$(P)by $(AUTHOR)'
@echo "$(NOCOLOR)"
endef

# Prints a line

define msg_line
@echo '-------------------------------------------------'
@echo
endef

# more complex...

define msg_comp
@echo 'Compiling...'
@echo
endef

# Bye message

define msg_end
@echo "$(NOCOLOR)Finished!"
@echo
endef
