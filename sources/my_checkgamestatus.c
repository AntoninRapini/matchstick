/*
** my_checkgamestatus.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 19:43:34 2017 Antonin Rapini
** Last update Thu Feb 16 14:00:34 2017 Antonin Rapini
*/

#include "my_game.h"

int	my_checkgamestatus(t_game *game)
{
  int	i;

  i = 0;
  while (i < game->lines)
    {
      if (game->gameinfos[i] != 0)
	return (0);
      i++;
    }
  return (1);
}
