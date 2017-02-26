/*
** my_create_map.c for matchstick in /home/antonin.rapini/ModulesTek1/ProgElem/CPE_2016_matchstick/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Feb 13 18:16:08 2017 Antonin Rapini
** Last update Sun Feb 26 12:58:23 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "sources.h"

void	my_fillmap(char **map, int lines, int linesize)
{
  int	i;
  int	j;

  i = 0;
  while (i < lines)
    {
      j = 0;
      while (j < linesize)
	{
	  if (j == 0 || j == linesize - 1 || i == 0 || i == lines - 1)
	    map[i][j] = '*';
	  else
	    {
	      if (j > (linesize / 2) - i
		  && j < (linesize / 2) + i)
		map[i][j] = '|';
	      else
		map[i][j] = ' ';
	    }
	  j++;
	}
      i++;
    }
}

char	**my_create_map(int mapsize)
{
  char	**map;
  int	linesize;
  int	i;

  i = 0;
  linesize = 1 + ((mapsize - 1) * 2) + 2;
  if ((map =  malloc(sizeof(char *) * (mapsize + 2 + 1))) == NULL)
    return (NULL);
  while (i < mapsize + 2)
    {
      if ((map[i] = malloc(sizeof(char) * linesize)) == NULL)
	return (NULL);
      i++;
    }
  map[i] = NULL;
  my_fillmap(map, mapsize + 2, linesize);
  return (map);
}
