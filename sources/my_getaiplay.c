/*
** my_aigetmatches.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 20 07:49:30 2017 Antonin Rapini
** Last update Thu Feb 23 20:21:13 2017 Antonin Rapini
*/

#include "my_game.h"
#include "my_play.h"
#include "sources.h"
#include <stdlib.h>

void getmoduloinfos(int maxremove, int size, int *infos, int *modinfos)
{
  int	i;

  i = 0;
  while (i < size)
    {
      modinfos[i] = infos[i] % (maxremove + 1);
      i++;
    }
}

t_play		my_getaiplay(t_game *game)
{
  int		i;
  int		nimsum;
  t_play	play;
  int		linesleft;
  static int	*modinfos = NULL;

  if (modinfos == NULL)
    modinfos = malloc(sizeof(int) * game->lines);
  getmoduloinfos(game->maxremove, game->lines, game->gameinfos, modinfos);
  i = 0;
  linesleft = 0;
  nimsum = 0;
  while (i++ < game->lines)
    if (game->gameinfos[i - 1] > 0)
      linesleft++;
  i = 0;
  while (i++ < game->lines)
    nimsum = nimsum ^ modinfos[i - 1];
  i = 0;
  if (!special_case(game, &play, linesleft, nimsum))
    {
      if (nimsum != 0)
	{
	  while (i < game->lines)
	    {
	      if ((nimsum ^ modinfos[i]) < modinfos[i])
		break;
	      i++;
	    }
	  play.line = i + 1;
	  play.matches = modinfos[i] - (modinfos[i] ^ nimsum);
	}
      else
	{
	  while (game->gameinfos[i] == 0)
	    i++;
	  play.line = i + 1;
	  play.matches = 1;
	}
    }
  return (play);
}
