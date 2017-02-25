/*
** my_check_lineinput.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 02:49:18 2017 Antonin Rapini
** Last update Sat Feb 25 15:04:51 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"

int my_check_removeinput(t_game *game, int line, int removenbr)
{
  if (removenbr == -2)
    {
      my_putstr("\nError: invalid input (positive number expected)\n");
      return (1);
    }
  if (removenbr < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (removenbr < 1)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (1);
    }
  if (game->maxremove < removenbr)
    {
      my_putstr("Error: you cannot remove more than ");
      my_put_nbr(game->maxremove);
      my_putstr(" matches per turn\n");
      return (1);
    }
  if (game->gameinfos[line - 1] < removenbr)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (1);
    }
  return (0);
}
