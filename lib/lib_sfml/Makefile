##
## Makefile<3> for nibbler in /home/menu_x/rendu/cpp_nibbler
## 
## Made by xavier menu
## Login   <menu_x@epitech.net>
## 
## Started on  Sat Apr  4 11:51:46 2015 xavier menu
## Last update Sun Apr  5 17:18:51 2015 wilko perruchon
##

CC		= g++

CPPFLAGS		+= -W -Wall -Wextra -L /usr/lib64/libsfml-graphics.so -L /usr/lib64/libsfml-window.so -L /usr/lib64/libsfml-system.so
CPPFLAGS		+= -fPIC -lsfml-graphics -lsfml-window -lsfml-system -g3
CPPFLAGS		+= -I./include -I../../include
# CPPFLAGS		+= `pkg-config gtkmm-3.0 --cflags --libs`

RM		= rm -rf

NAME		= lib_nibbler_sfml.so

SRC		=	SFML.cpp \

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)
	@echo "$(NAME) is up to date."

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -shared -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
