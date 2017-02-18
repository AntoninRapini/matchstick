/*
** my_check_lineinput.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 02:49:18 2017 Antonin Rapini
** Last update Thu Feb 16 02:13:48 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"

int my_check_airemove(t_game *game, int line, int removenbr)
{
  if (removenbr < 0)
    return (1);
  if (removenbr < 1)
    return (1);
  if (game->gameinfos[line - 1] < removenbr)
    return (1);
  if (game->maxremove < removenbr)
    return (1);
  return (0);
}
