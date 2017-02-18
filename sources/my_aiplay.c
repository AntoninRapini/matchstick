/*
** my_aiplay.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 19:42:55 2017 Antonin Rapini
** Last update Thu Feb 16 14:02:39 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"
#include <stdlib.h>
#include <time.h>
#include "sources.h"
#include <stdio.h>

int my_generatenumber(int max)
{
  static int	first = 0;
  int		generated;

  if (!first)
    {
      srand(time(NULL));
      first = 1;
    }
  while ((generated = (int)(rand() / (double)RAND_MAX * (max - 1))) < 1)
    {
      printf("%i ", generated);
      fflush(stdout);
    }
  return (generated);
}

void my_printaiplay(int line, int matches)
{
  my_putstr("AI removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

int	my_aiplay(t_game *game)
{
  int	matches;
  int	line;

  line = 0;
  matches = 0;
  my_putstr("\nAI's turn...\n");
  while (my_check_ailine(game, line))
    line = my_generatenumber(game->lines);
  while (my_check_airemove(game, line, matches))
    matches = my_generatenumber(game->maxremove);
  my_printaiplay(line, matches);
  my_removematches(game, line, matches);
  return (my_checkgamestatus(game) != 0 ? 1 : 0);
}
