/*
** my_aigetmatches.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 20 07:49:30 2017 Antonin Rapini
** Last update Sat Feb 25 14:16:22 2017 Antonin Rapini
*/

#include "my_game.h"
#include "my_play.h"
#include "sources.h"
#include "my_gamestatus.h"
#include <stdlib.h>

void	getmoduloinfos(int maxremove, int size, int *infos, int *modinfos)
{
  int	i;

  i = 0;
  while (i < size)
    {
      modinfos[i] = infos[i] % (maxremove + 1);
      i++;
    }
}

void	my_get_gameinfos(t_game *game, t_gamestatus *status)
{
  int	i;

  i = 0;
  status->nimsum = 0;
  status->linesleft = 0;
  status->notsingle = 0;
  while (i < game->lines)
    {
      if (game->gameinfos[i] > 0)
	status->linesleft++;
      if (game->gameinfos[i] > 1)
	status->notsingle++;
      status->nimsum = status->nimsum ^ status->modinfos[i];
      i++;
    }
  
}

t_play		my_getaiplay(t_game *game)
{
  int		i;
  t_play	play;
  t_gamestatus	status;

  i = 0;
  status.modinfos = malloc(sizeof(int) * game->lines);
  getmoduloinfos(game->maxremove, game->lines, game->gameinfos, status.modinfos);
  my_get_gameinfos(game, &status);
  if (status.notsingle <= 1)
    special_case(game, &play, &status);
  else if (status.nimsum != 0)
    {
      while (i < game->lines)
	{
	  if ((status.nimsum ^ status.modinfos[i]) < status.modinfos[i])
	    break;
	  i++;
	}
      my_fillplay(&play, i + 1,
		  status.modinfos[i] - (status.modinfos[i] ^ status.nimsum));
    }
  else
    my_fillplay(&play, findfirstvalid(game), 1);
  free(status.modinfos);
  return (play);
}
