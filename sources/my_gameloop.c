/*
** my_play.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 02:00:02 2017 Antonin Rapini
** Last update Thu Feb 23 13:48:22 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"
#include "sources.h"
#include "my_play.h"

int		my_gameloop(t_game *game)
{
  int		gamestatus;
  t_play	playermove;

  gamestatus = 0;
  my_show_wordtab(game->map);
  while (gamestatus == 0)
    {
      gamestatus = my_play(game, &playermove);
      my_show_wordtab(game->map);
      if (gamestatus == 0)
	{
	  gamestatus = my_aiplay(game, playermove);
	  my_show_wordtab(game->map);
	}
    }
  if (gamestatus == 1)
    my_putstr("I lost... snif... but i'll get you next time!!\n");
  else
    my_putstr("You lost, too bad...\n");
  return (gamestatus);
}
