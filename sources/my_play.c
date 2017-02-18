/*
** my_play.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 02:34:06 2017 Antonin Rapini
** Last update Thu Feb 16 13:53:59 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"
#include "sources.h"
#include "get_next_line.h"

void my_printplay(int line, int matches)
{
  my_putstr("Player removed ");
  my_put_nbr(matches);
  my_putstr(" matche(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

int	my_play(t_game *game)
{
  int	playing;
  char	*buffer;
  int	line;
  int	matches;

  playing = 1;
  my_putstr("\nYour turn:\n");
  while (playing)
    {
      my_putstr("Line: ");
      buffer = get_next_line(0);
      line = my_getnbr(buffer);
      playing = my_check_lineinput(game, line);
    }
  playing = 1;
  while (playing)
    {
      my_putstr("Matches: ");
      buffer = get_next_line(0);
      matches = my_getnbr(buffer);
      playing = my_check_removeinput(game, line, matches);
    }
  my_printplay(line, matches);
  my_removematches(game, line, matches);
  return (my_checkgamestatus(game) != 0 ? 2 : 0);
}
