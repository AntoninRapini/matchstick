##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Thu Feb 23 11:40:38 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I include

SRC	=	utils/get_next_line.c	\
		utils/my_getnbr.c	\
		utils/my_putchar.c	\
		utils/my_putstr.c	\
		utils/my_put_nbr.c	\
		utils/my_show_wordtab.c	\
		sources/loading/my_create_game.c	\
		sources/loading/my_create_gameinfos.c	\
		sources/loading/my_create_map.c		\
		sources/my_gameloop.c	\
		sources/my_play.c	\
		sources/my_aiplay.c	\
		sources/my_check_removeinput.c	\
		sources/my_check_lineinput.c	\
		sources/my_removematches.c	\
		sources/my_checkgamestatus.c	\
		sources/my_getaiplay.c		\
		sources/special_case.c		\
		matchstick.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	matchstick

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
