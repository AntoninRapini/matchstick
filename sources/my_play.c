/*
** my_play.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 02:34:06 2017 Antonin Rapini
** Last update Sun Feb 26 12:51:46 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"
#include "sources.h"
#include "get_next_line.h"
#include "my_play.h"
#include <stdlib.h>

void my_printplay(int line, int matches)
{
  my_putstr("Player removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

int my_endplay(t_play play, t_game *game)
{
  my_printplay(play.line, play.matches);
  my_removematches(game, play.line, play.matches);
  return (my_checkgamestatus(game) != 0 ? 2 : 0);
}

int	my_getplayerinput(t_play *play, t_game *game)
{
  int	playing;
  int	waitingforplay;
  char	*buffer;

  playing = 1;
  waitingforplay = 1;
  while (waitingforplay)
    {
      while (playing)
	{
	  my_putstr("Line: ");
	  if ((buffer = get_next_line(0)) == NULL)
	    return (1);
	  play->line = my_getnbr(buffer);
	  playing = my_check_lineinput(game, play->line);
	}
      playing = 1;
      my_putstr("Matches: ");
      if ((buffer = get_next_line(0)) == NULL)
	return (1);
      play->matches = my_getnbr(buffer);
      waitingforplay = my_check_removeinput(game, play->line, play->matches);
    }
  return (0);
}

int		my_play(t_game *game)
{
  t_play	play;

  my_putstr("\nYour turn:\n");
  if (my_getplayerinput(&play, game))
    return (3);
  return (my_endplay(play, game));
}
