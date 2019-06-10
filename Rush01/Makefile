# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/02 23:12:37 by cjulliar          #+#    #+#              #
#    Updated: 2019/06/02 23:12:40 by cjulliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

CC		= clang++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME	= ft_gkrellm
DEBUG	= debug_$(NAME)

SFML    = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio

NCURSE = -lncurses

OBJDIR	= obj

FAN		= -fsanitize=address,undefined -g

GREEN	= \x1b[32m

WHITE	= \x1b[0m

SRC		=	main.cpp		\
			CPUInfo.cpp		\
			Gui.cpp			\
			Monitor.cpp		\
			NCurses.cpp		\
			OHName.cpp		\
			OsInfo.cpp		\
			ProcessList.cpp \
			Process.cpp		\
			Ram.cpp			\
			Time.cpp		\
			CpuUsage.cpp

OBJ		= $(SRC:.cpp=.o)

INC =


INC_PATH =  ~/.brew/include
LIB_PATH = ~/.brew/lib

RPATH   = -rpath ~/.brew/lib

OBJP	= $(addprefix $(OBJDIR)/, $(OBJ))
INCP	= $(addprefix $(INC_PATH)/, $(INC))

all:  $(OBJDIR) $(NAME)
	@echo > /dev/null

$(NAME): obj $(OBJP)
	@$(CC) $(CFLAGS)  -o $@ $(OBJP)  -I $(INC_PATH) -L $(LIB_PATH) $(SFML) $(RPATH) $(NCURSE)
	@echo "${WHITE}$(NAME)			${GREEN}DONE${WHITE}"

debug: obj $(OBJP)
	@$(CC) $(CFLAGS)  -o $(DEBUG) $(OBJP) $(NCURSE) -I $(INC_PATH) $(SFML) -L $(LIB_PATH) $(RPATH) $(FAN)
	@echo "${WHITE}$(NAME)			${GREEN}DONE${WHITE}"

obj :
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(INCP)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(NAME) $(DEBUG)

re: fclean all
