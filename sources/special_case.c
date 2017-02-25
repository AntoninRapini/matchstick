/*
** special_case.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 13:12:55 2017 Antonin Rapini
** Last update Sat Feb 25 14:16:02 2017 Antonin Rapini
*/

#include "my_game.h"
#include "my_play.h"
#include "sources.h"

int	findfirstvalid(t_game *game)
{
  int	i;

  i = 0;
  while (i < game->lines)
    {
      if (game->gameinfos[i] == 1)
	return (i + 1);
      i++;
    }
  return (0);
}

void	is_specialandpair(t_game *game, t_play *play)
{
  int	i;

  i = 0;
  while (i < game->lines)
    {
      if (game->gameinfos[i] > 1)
	{
	  if (game->gameinfos[i] <= game->maxremove)
	    {
	      my_fillplay(play, i + 1, game->gameinfos[i]);
	      return ;
	    }
	  else if (game->gameinfos[i] > game->maxremove + 1)
	    {
	      if (game->gameinfos[i] % (game->maxremove + 1) > 1)
		{
		  my_fillplay(play, i + 1, game->gameinfos[i] % (game->maxremove + 1) - 1);
		  return ;
		}
	    }
	}
      i++;
    }
  i = 0;
  my_fillplay(play, findfirstvalid(game), 1);
}

void	is_specialandnotpair(t_game *game, t_play *play)
{
  int	i;

  i = 0;
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
	  return ;
	}
      i++;
    }
}

void	special_case(t_game *game, t_play *play, t_gamestatus *status)
{
  if (status->notsingle == 0)
    my_fillplay(play, findfirstvalid(game), 1);
  else
    {
      if (status->linesleft % 2 == 0)
	is_specialandpair(game, play);
      else
	is_specialandnotpair(game,play);
    }
}
