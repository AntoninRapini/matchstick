/*
** my_check_lineinput.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 02:49:18 2017 Antonin Rapini
** Last update Sat Feb 25 15:04:29 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"

int my_check_lineinput(t_game *game, int line)
{
  if (line == -2)
    {
      my_putstr("\nError: invalid input (positive number expected)\n");
      return (1);
    }
  if (line < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (line == 0 || line > game->lines)
    {
      my_putstr("Error: this line is out of range\n");
      return (1);
    }
  if (game->gameinfos[line - 1] == 0)
    {
      my_putstr("Error: no more matches on this line\n");
      return (1);
    }
  return (0);
}
