/*
** my_removematches.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 19:44:08 2017 Antonin Rapini
** Last update Thu Feb 16 14:00:02 2017 Antonin Rapini
*/

#include "my_game.h"

void	my_removematches(t_game *game, int line, int matches)
{
  int	i;
  int	j;

  game->gameinfos[line - 1] -= matches;
  i = 0;
  while (game->map[line][i] != '|')
    i++;
  while (game->map[line][i] == '|')
    i++;
  i--;
  j = 0;
  while (j < matches)
    {
      game->map[line][i] = ' ';
      j++;
      i--;
    }
}
