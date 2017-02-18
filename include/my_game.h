/*
** my_game.h for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 13 18:37:49 2017 Antonin Rapini
** Last update Wed Feb 15 01:45:35 2017 Antonin Rapini
*/

#ifndef MY_GAME_H_
#define MY_GAME_H_

typedef struct	s_game
{
  int		lines;
  char		**map;
  int		*gameinfos;
  int		maxremove;
}		t_game;

#endif /* !MY_GAME_H_ */
