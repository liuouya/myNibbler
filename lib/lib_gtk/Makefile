##
## Makefile for nibbler in /home/liu_o/rendu/cpp_nibbler/src/graphics/lib_gtk
## 
## Made by ouya liu
## Login   <liu_o@epitech.net>
## 
## Started on  Thu Apr  2 19:00:28 2015 ouya liu
## Last update Sat Apr  4 17:32:31 2015 ouya liu
##

CC		= g++

CPPFLAGS		+= -W -Wall -Wextra
CPPFLAGS		+= -fPIC
CPPFLAGS		+= -I./include -I../../include
CPPFLAGS		+= `pkg-config gtkmm-3.0 --cflags --libs`
CPPFLAGS		+= -g

RM		= rm -rf

NAME		= lib_nibbler_gtk.so

SRC		=	src/GTK.cpp \
			src/DBoard.cpp \
			src/myWindow.cpp \

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)
	@echo "$(NAME) is up to date."

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -shared -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
