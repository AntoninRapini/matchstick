/*
** my_aiplay.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 15 19:42:55 2017 Antonin Rapini
** Last update Sun Feb 26 12:42:07 2017 Antonin Rapini
*/

#include "my_play.h"
#include "my_game.h"
#include "utils.h"
#include "sources.h"

void my_printaiplay(int line, int matches)
{
  my_putstr("AI removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
}

int		my_aiplay(t_game *game)
{
  t_play	play;

  my_putstr("\nAI's turn...\n");
  play = my_getaiplay(game);
  my_printaiplay(play.line, play.matches);
  my_removematches(game, play.line, play.matches);
  return (my_checkgamestatus(game) != 0 ? 1 : 0);
}
