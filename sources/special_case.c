/*
** special_case.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 13:12:55 2017 Antonin Rapini
** Last update Thu Feb 23 20:20:58 2017 Antonin Rapini
*/

#include "my_game.h"
#include "my_play.h"

int special_case(t_game *game, t_play *play, int linesleft, int nimsum)
{
  int notsingle;
  int i;

  i = 0;
  notsingle = 0;
  if (nimsum){}
  while (i < game->lines)
    {
      if (game->gameinfos[i] > 1)
	notsingle++;
      i++;
    }
  i = 0;
  if (notsingle > 1)
    return (0);
  if (notsingle == 0)
    {
      while (i < game->lines)
	{
	  if (game->gameinfos[i] == 1)
	    {
	      play->line = i + 1;
	      play->matches = 1;
	      return (1);
	    }
	  i++;
	}
    }
  else
    {
      if (linesleft % 2 == 0)
	{
	  while (i < game->lines)
	    {
	      if (game->gameinfos[i] > 1)
		{
		  if (game->gameinfos[i] <= game->maxremove)
		    {
		      play->line = i + 1;
		      play->matches = game->gameinfos[i];
		      return (1);
		    }
		}
	      i++;
	    }
	  i = 0;
	  while (i < game->lines)
	    {
	      if (game->gameinfos[i] == 1)
		{
		  play->line = i + 1;
		  play->matches = 1;
		  return (1);
		}
	      i++;
	    }
	}
      else
	{
	  while (i < game->lines)
	    {
	      if (game->gameinfos[i] > 1)
		{
		  play->line = i + 1;
		  if (game->maxremove > game->gameinfos[i])
		    play->matches = game->gameinfos[i] - 1;
		  else if (game->gameinfos[i] % (game->maxremove + 1) > 1)
		    play->matches = game->gameinfos[i] % (game->maxremove + 1) - 1;
		  else
		    play->matches = 1;
		  return (1);
		}
	      i++;
	    }
	}
    }
  return (1);
}
