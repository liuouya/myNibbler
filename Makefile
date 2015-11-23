##
## Makefile for nibbler in /home/liu_o/rendu/cpp_nibbler/src/graphics/lib_gtk
## 
## Made by ouya liu
## Login   <liu_o@epitech.net>
## 
## Started on  Thu Apr  2 19:00:28 2015 ouya liu
## Last update Sun Apr  5 23:39:46 2015 wilko perruchon
##

CC		= g++

CPPFLAGS	+= -W -Wall -Wextra
CPPFLAGS	+= -I./include
CPPFLAGS	+= -fPIC -g3

LDFLAGS		+= -ldl

RM		= rm -rf

NAME		= nibbler

LIB1		= ./lib/lib_opengl/lib_nibbler_opengl.so
LIB1_PATH	= ./lib/lib_opengl/
NAME1		= ./lib_nibbler_opengl.so

LIB2		= ./lib/lib_gtk/lib_nibbler_gtk.so
LIB2_PATH	= ./lib/lib_gtk/
NAME2		= ./lib_nibbler_gtk.so

LIB3		= ./lib/lib_sfml/lib_nibbler_sfml.so
LIB3_PATH	= ./lib/lib_sfml/
NAME3		= ./lib_nibbler_sfml.so

SRC		=	src/game/main.cpp \
			src/game/Snake.cpp \
			src/game/Grid.cpp \
			src/game/Callback.cpp \

OBJ		= $(SRC:.cpp=.o)

all: $(NAME) $(LIB1) $(NAME1) $(LIB2) $(NAME2) $(LIB3) $(NAME3)
	@echo "$(NAME) $(NAME1) $(NAME2) $(NAME3) are all up to date."

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

$(LIB1):
	make -C $(LIB1_PATH)

$(NAME1):
	ln -sf $(LIB1) $(NAME1)

$(LIB2):
	make -C $(LIB2_PATH)

$(NAME2):
	ln -sf $(LIB2) $(NAME2)

$(LIB3):
	make -C $(LIB3_PATH)

$(NAME3):
	ln -sf $(LIB3) $(NAME3)

clean:
	$(RM) $(OBJ)
	make -C $(LIB1_PATH) clean
	make -C $(LIB2_PATH) clean
	make -C $(LIB3_PATH) clean

fclean: clean
	$(RM) $(NAME) $(NAME1) $(LIB1) $(NAME2) $(LIB2) $(NAME3) $(LIB3)		

re: fclean all

.PHONY: all clean fclean re
