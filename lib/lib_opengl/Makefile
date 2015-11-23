##
## Makefile for nibbler in /home/liu_o/rendu/cpp_nibbler/src/graphics/lib_gtk
## 
## Made by ouya liu
## Login   <liu_o@epitech.net>
## 
## Started on  Thu Apr  2 19:00:28 2015 ouya liu
## Last update Sun Apr  5 23:28:30 2015 wilko perruchon
##

CC		= g++

CPPFLAGS		+= -W -Wall -Wextra
CPPFLAGS		+= -fPIC -lGL -lGLU -lSDL -g3
CPPFLAGS		+= -I./include -I../../include
# CPPFLAGS		+= `pkg-config gtkmm-3.0 --cflags --libs`

RM		= rm -rf

NAME		= lib_nibbler_opengl.so

SRC		=	src/OpenGL.cpp \
			src/sound.cpp \
			src/texture.cpp

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
