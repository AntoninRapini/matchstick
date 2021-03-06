/*
** sources.h for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 01:48:16 2017 Antonin Rapini
** Last update Sun Feb 26 12:44:23 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "my_game.h"
#include "my_play.h"
#include "my_gamestatus.h"

t_game *my_create_game(char *, char *);
char **my_create_map(int);
int *my_create_gameinfos(int);
int my_gameloop(t_game *);
int my_play(t_game *);
int my_aiplay(t_game *);
int my_check_removeinput(t_game *, int, int);
int my_check_lineinput(t_game *, int);
void my_removematches(t_game *, int, int);
int my_checkgamestatus(t_game *);
t_play my_getaiplay(t_game *);
void special_case(t_game *, t_play *, t_gamestatus *);
int findfirstvalid(t_game *);
void my_fillplay(t_play *, int, int);

#endif /* !SOURCES_H_ */
