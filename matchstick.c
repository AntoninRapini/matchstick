/*
** matchstick.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 13 17:01:11 2017 Antonin Rapini
** Last update Wed Feb 15 02:29:12 2017 Antonin Rapini
*/

#include "my_game.h"
#include <stdlib.h>
#include "sources.h"
#include "utils.h"

int		main(int ac, char **av)
{
  t_game	*game;

  if (ac == 3)
    {
      if ((game = my_create_game(av[1], av[2])) != NULL)
	return (my_gameloop(game));
    }
  return (84);
}
