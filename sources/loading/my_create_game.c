/*
** my_create_game.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 13 18:39:16 2017 Antonin Rapini
** Last update Wed Feb 15 01:50:31 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_game.h"
#include "utils.h"
#include "sources.h"

t_game		*my_create_game(char *lines_str, char *maxremove_str)
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->lines = my_getnbr(lines_str);
  if (game->lines > 100 || game->lines < 1)
    return (NULL);
  game->maxremove = my_getnbr(maxremove_str);
  if (game->maxremove <= 0)
    return (NULL);
  if ((game->map = my_create_map(game->lines)) == NULL)
    return (NULL);
  if ((game->gameinfos = my_create_gameinfos(game->lines)) == NULL)
    return (NULL);
  return (game);
}
