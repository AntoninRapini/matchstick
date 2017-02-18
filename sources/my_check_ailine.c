/*
** my_check_lineinput.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 02:49:18 2017 Antonin Rapini
** Last update Thu Feb 16 02:14:17 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"

int my_check_ailine(t_game *game, int line)
{
  if (line < 0)
    return (1);
  if (line == 0 || line > game->lines)
    return (1);
  if (game->gameinfos[line - 1] == 0)
    return (1);
  return (0);
}
