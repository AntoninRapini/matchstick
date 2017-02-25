/*
** my_fillplay.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Feb 25 13:22:55 2017 Antonin Rapini
** Last update Sat Feb 25 13:23:35 2017 Antonin Rapini
*/

#include "my_play.h"

void my_fillplay(t_play *play, int line, int matches)
{
  play->line = line;
  play->matches = matches;
}
