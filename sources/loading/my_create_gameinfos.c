/*
** my_create_gameinfos.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources/loading
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 13 18:46:03 2017 Antonin Rapini
** Last update Wed Feb 15 01:50:50 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"

int	*my_create_gameinfos(int lines)
{
  int	*gameinfos;
  int	i;
  int	linesize;

  if ((gameinfos = malloc(sizeof(int) * lines)) == NULL)
    return (NULL);
  i = 0;
  linesize = 1;
  while (i < lines)
    {
      gameinfos[i] = linesize;
      linesize += 2;
      i++;
    }
  return (gameinfos);
}
